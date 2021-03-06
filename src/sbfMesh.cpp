#include "sbfMesh.h"
#include "sbfAdditions.h"
#include "sbfNode.h"
#include "sbfElement.h"
#include "sbfGroupFilter.h"
#include "sbfGroup.h"
#include "sbfElementGroup.h"
#include "sbfNodeGroup.h"
#include "sbfReporter.h"

#include "sbfthreadpool.hpp"
#include <atomic>
#include <array>
#include <set>
#include <algorithm>

void computeGraph(sbfMesh * mesh, int *** graph, bool makeReport);
void computeGraphAlter(sbfMesh * mesh, int *** graph, bool makeReport);
size_t computeProfileSize(int ** graph, int numNodes, bool * flagOwerFlow = nullptr);
int computeBandwidth(int ** graph, int numNodes);
void findUnnumberedNeighbors(int ** graph, int * mask, int * tmp, /*I do not know better name*/ int & temp, int * deg, int nodeCt);
void makeRCM(int ** graph, int numNodes, int startNode, int * newToOld, int *oldToNew);
int findStartNode(int ** graph, int numNodes);

ElementType tryToResolveTypeByNumNodes(int numNodes, int kort = 3);
int typesLibToFile(const ElementType & type);
ElementType typesFileToLib(const int type);

sbfMesh::sbfMesh()
{
    kort_ = 3;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    reserveNodesNumber(1000);
    reserveElementsNumber(1000);
}
sbfMesh::sbfMesh(const sbfMesh &mesh)
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    reserveNodesNumber(mesh.numNodeGroups());
    reserveElementsNumber(mesh.numElements());
    kort_ = mesh.kort_;
    int nnode = mesh.numNodes();
    for(int ct = 0; ct < nnode; ct++)
        addNode(mesh.node(ct), false);
    int nelem = mesh.numElements();
    for(int ct = 0; ct < nelem; ct++)
        addElement(mesh.elems_[ct]);
    mtr_ = mesh.mtr_;
    int ngrelem = mesh.numGroups();
    for(int ct = 0; ct < ngrelem; ct++)
    {
        //Not implemented yet!!!
    }
}

sbfMesh::~sbfMesh()
{
    clearAllGroups();
    mtr_.clear();
}

int sbfMesh::readCrdFromFile(const char* crdName)
{
    nodes_.clear();
    std::ifstream crdFile(crdName, std::fstream::binary);
    if(!crdFile.good())
    {
        report.error("Error! Can't read crd file ", crdName);
        return 1;
    }

    int temp;
    crdFile.read((char *)&temp, sizeof(temp));
    crdFile.read((char *)&kort_, sizeof(kort_));
    int numN = temp/kort_;

    nodes_.reserve(numN);

    float *tempF;
    tempF = new float [kort_*numN];
    crdFile.read((char *)tempF, kort_*numN*sizeof(tempF[0]));

    for(int ct = 0; ct < numN; ct++)
        nodes_.push_back(sbfNode(tempF[0*numN+ct], tempF[1*numN+ct], tempF[2*numN+ct]));
    delete [] tempF;

    crdFile.close();
    return 0;
}

int sbfMesh::readIndFromFile(const char* indName, FileVersion fileFormatVersion)
{
    elems_.clear();
    std::ifstream indFile(indName, std::fstream::binary);
    if(!indFile.good()){
        report.error("Error! Can't read ind file ", indName);
        return 1;
    }

    if(fileFormatVersion == FileVersion::AUTO_FORMAT){
        indFile.seekg(0, std::ios_base::end);
        int fileBytesLength = indFile.tellg();
        indFile.seekg(0, std::ios_base::beg);
        int oldNElem, newNTypes;
        indFile.read((char *)&oldNElem, sizeof(int)); newNTypes = oldNElem;
        int /*oldIndLen, */newIndLen;
        int oldNumNodes;
        indFile.read((char *)&oldNumNodes, sizeof(oldNumNodes));
        if(oldNumNodes) oldNElem /= oldNumNodes;
        else oldNElem = 0;
        if((int)((1+2*newNTypes)*sizeof(int)) < fileBytesLength){
            indFile.seekg((1+2*newNTypes)*sizeof(int), std::ios_base::beg);
            indFile.read((char *)&newIndLen, sizeof(newIndLen));
        }
        else newIndLen = 0;
        if(fileBytesLength == (int)((2 + oldNElem*oldNumNodes)*sizeof(int)))
            fileFormatVersion = FileVersion::OLD_FORMAT;
        else if(fileBytesLength == (int)((1 + 2*newNTypes + 1 + newIndLen)*sizeof(int)))
            fileFormatVersion = FileVersion::NEW_FORMAT;
        else fileFormatVersion = FileVersion::NOT_DEFINED_FORMAT;
        indFile.seekg(0, std::ios_base::beg);
    }

    if(fileFormatVersion == FileVersion::OLD_FORMAT){
        int temp;
        int numE;
        indFile.read((char *)&numE, sizeof(numE));
        indFile.read((char *)&temp, sizeof(temp));
        numE /= temp;
        elems_.reserve(numE);
        for(int ct = 0; ct < numE; ct++)
        {
            elems_.push_back(sbfElement());
            elems_.back().setNumNodes(temp);
            elems_.back().setMesh(this);
            elems_.back().setType(tryToResolveTypeByNumNodes(temp));
            for(int ct1 = 0; ct1 < temp; ct1++)
            {
                int tempi;
                indFile.read((char *)&tempi, sizeof(tempi));
                tempi--;
                elems_.back().setNode(ct1, tempi);
            }
        }
    }
    else if(fileFormatVersion == FileVersion::NEW_FORMAT){
        int nTypes;
        std::vector <int> types;
        std::vector <int> nElem;
        int indLength;
        int numAllElem = 0;
        indFile.read((char *)&nTypes, sizeof(nTypes));
        types.resize(nTypes, -1);
        nElem.resize(nTypes, -1);
        for(int ct = 0; ct < nTypes; ct++){
            indFile.read((char *)&types[ct], sizeof(types[ct]));
            indFile.read((char *)&nElem[ct], sizeof(types[ct]));
            numAllElem += nElem[ct];
        }
        indFile.read((char *)&indLength, sizeof(indLength));
        elems_.reserve(numAllElem);
        for(int ct = 0; ct < nTypes; ct++){
            ElementType type_ = typesFileToLib(types[ct]);
            int temp_i = numNodesInElement(type_);
            for(int ct1 = 0; ct1 < nElem[ct]; ct1++){
                elems_.push_back(sbfElement(temp_i));
                elems_.back().setType(type_);
                elems_.back().setMesh(this);
                for(int ct2 = 0; ct2 < temp_i; ct2++)
                {
                    int temp_i2;
                    indFile.read((char *)&temp_i2, sizeof(temp_i2));
                    //indFile.read((char *)&elems_.back().nodeIndex(ct2), sizeof(elems_.back().nodeIndex(ct2)));
                    elems_.back().setNode(ct2, --temp_i2);
                }
            }
        }
    }
    else {
        report.error("Ind file version error");
        return 1;
    }
    indFile.close();
    return 0;
}

int sbfMesh::readMtrFromFile(const char* mtrName)
{
    mtr_.clear();
    std::ifstream mtrFile(mtrName, std::fstream::binary);
    if(!mtrFile.good())
    {
        report.error("Error! Can't read mtr file ", mtrName);
        return 1;
    }

    int temp;
    int nelems = numElements();
    for(int ct = 0; ct < nelems; ct++)
    {
        mtrFile.read((char *)&temp, sizeof(temp));
        elems_[ct].setMtr(temp);
    }

    mtrFile.close();
    return 0;
}
int sbfMesh::readMeshFromFiles(const char* indName, const char* crdName, const char* mtrName, FileVersion fileFormatVersion)
{
    if(readIndFromFile(indName, fileFormatVersion) != 0)
        return 1;
    if(readCrdFromFile(crdName) != 0)
        return 2;
    if(readMtrFromFile(mtrName) != 0)
        return 3;
    return 0;
}

int sbfMesh::readMeshFromFiles(const std::string &indName, const std::string &crdName, const std::string &mtrName)
{
    return readMeshFromFiles(indName.c_str(), crdName.c_str(), mtrName.c_str());
}

int sbfMesh::readMeshFromFilesWithPrefix(const std::string &prefix,
                                         const std::string &indName,
                                         const std::string &crdName,
                                         const std::string &mtrName)
{
    return readMeshFromFiles(prefix + indName, prefix + crdName, prefix + mtrName);
}

int sbfMesh::writeCrdToFile(const char* crdName)
{
    std::ofstream crdFile(crdName, std::fstream::binary);
    if(!crdFile.good())
    {
        report.error("Error! Can't open crd file ", crdName, " for writing");
        return 1;
    }

    int temp = numNodes()*kort_;
    crdFile.write((char *)&temp, sizeof(temp));
    crdFile.write((char *)&kort_, sizeof(kort_));

    for(int ct = 0; ct < kort_; ct++)
        for(int ct1 = 0; ct1 < numNodes(); ct1++)
            crdFile.write(reinterpret_cast<const char *>(&(nodes_[ct1].crdAtKort(ct))), sizeof(nodes_[ct1].x()));
    crdFile.close();
    return 0;
}

int sbfMesh::writeIndToFile(const char* indName, const FileVersion fileFormatVersion)
{
    std::ofstream indFile(indName, std::fstream::binary);
    if(!indFile.good())
    {
        report.error("Error! Can't open ind file ", indName, " for writing");
        return 1;
    }

    if(fileFormatVersion == FileVersion::OLD_FORMAT){
        int temp = (int) elems_.size() * elems_[0].numNodes();
        indFile.write((char *)&temp, sizeof(temp));
        temp = elems_[0].numNodes();
        indFile.write((char *)&temp, sizeof(temp));

        for(int ct = 0; ct < numElements(); ct++)
            for(int ct1 = 0; ct1 < elems_[ct].numNodes(); ct1++)
            {
                int tempi = elems_[ct].nodeIndex(ct1) + 1;
                indFile.write((char *)&(tempi), sizeof(tempi));
            }
    }
    else if(fileFormatVersion == FileVersion::NEW_FORMAT){
        bool autoGeneratedGroups = false;
        if(numGroups() == 0){
            //Automatic groups generation based on elemType
            autoGeneratedGroups = true;
            std::map<ElementType, sbfElementGroup *> typeGroups;
            for(int ct = 0; ct < numElements(); ct++){
                sbfElement *elem = elemPtr(ct);
                if(typeGroups.find(elem->type()) == typeGroups.end()) typeGroups[elem->type()] = addElementGroup();
                typeGroups[elem->type()]->addElement(ct, false);
            }
        }

        int nTypes = numGroups();
        ElementType typeL;
        int typeF;
        int nElem;
        int indLength = 0;
        indFile.write((char *)&nTypes, sizeof(nTypes));
        for(int ct = 0; ct < nTypes; ct++){
            typeL = elemGroups_[ct]->type();
            nElem = elemGroups_[ct]->numElems();
            indLength += nElem*numNodesInElement(typeL);
            typeF = typesLibToFile(typeL);
            indFile.write((char *)&typeF, sizeof(typeF));
            indFile.write((char *)&nElem, sizeof(nElem));
        }
        indFile.write((char *)&indLength, sizeof(indLength));
        for(int ct = 0; ct < nTypes; ct++){
            typeL = elemGroups_[ct]->type();
            for(int ct1 = 0; ct1 < elemGroups_[ct]->numElems(); ct1++){
                int temp_i = numNodesInElement(typeL);
                for(int ct2 = 0; ct2 < temp_i; ct2++)
                {
                    int tempi = elems_[elemGroups_[ct]->element(ct1)].nodeIndex(ct2) + 1;
                    indFile.write((char *)&tempi, sizeof(tempi));
                }
            }
        }

        if(autoGeneratedGroups) clearElemGroups();
    }
    indFile.close();
    return 0;
}

int sbfMesh::writeMtrToFile(const char* mtrName, const FileVersion fileFormatVersion) const
{
    std::ofstream mtrFile(mtrName, std::fstream::binary);
    if(!mtrFile.good())
    {
        report.error("Error! Can't open mtr file ", mtrName, " for writing");
        return 1;
    }
    if(fileFormatVersion == FileVersion::OLD_FORMAT){
        for(int ct = 0; ct < numElements(); ct++){
            int mtr_ = elems_[ct].mtr();
            mtrFile.write((char *)&mtr_, sizeof(mtr_));
        }
    }
    else if(fileFormatVersion == FileVersion::NEW_FORMAT){
        if(numGroups() == 0)
            report.error("Mtr file write failed! No groups!");
        else{
            int nTypes = numGroups();
            for(int ct = 0; ct < nTypes; ct++){
                for(int ct1 = 0; ct1 < elemGroups_[ct]->numElems(); ct1++){
                    int temp_i = elems_[elemGroups_[ct]->element(ct1)].mtr();
                    mtrFile.write((char *)&temp_i, sizeof(temp_i));
                }
            }
        }
    }
    mtrFile.close();
    return 0;
}
int sbfMesh::writeMeshToFiles(const char* indName, const char* crdName, const char* mtrName, const FileVersion fileFormatVersion)
{
    bool autoGeneratedGroups = false;
    if(fileFormatVersion == FileVersion::NEW_FORMAT){
        if(numGroups() == 0){
            //Automatic groups generation based on elemType
            autoGeneratedGroups = true;
            std::map<ElementType, sbfElementGroup *> typeGroups;
            for(int ct = 0; ct < numElements(); ct++){
                sbfElement *elem = elemPtr(ct);
                if(typeGroups.find(elem->type()) == typeGroups.end()) typeGroups[elem->type()] = addElementGroup();
                typeGroups[elem->type()]->addElement(ct, false);
            }
        }
    }
    if(writeIndToFile(indName, fileFormatVersion) != 0)
        return 1;
    if(writeCrdToFile(crdName) != 0)
        return 2;
    if(writeMtrToFile(mtrName, fileFormatVersion) != 0)
        return 3;
    if(autoGeneratedGroups) clearElemGroups();
    return 0;
}

int sbfMesh::writeMeshToFiles(const std::string &indName, const std::string &crdName, const std::string &mtrName)
{
    return writeMeshToFiles(indName.c_str(), crdName.c_str(), mtrName.c_str());
}

int sbfMesh::writeMeshToFilesWithPrefix(const std::string &prefix)
{
    return writeMeshToFiles(prefix + "ind.sba", prefix + "crd.sba", prefix + sbf::makeNameWithStep("mtr", 1, 4) +".sba");
}

sbfNode & sbfMesh::node(const int seqNumber)
{
    return nodes_[seqNumber];
}

const sbfNode &sbfMesh::node(const int seqNumber) const
{
    return nodes_[seqNumber];
}
sbfElement &sbfMesh::elem(const int seqNumber)
{
    return elems_[seqNumber];
}
const sbfElement &sbfMesh::elem(const int seqNumber) const
{
    return elems_[seqNumber];
}
sbfElement * sbfMesh::elemPtr(const int sequenceNumber)
{
    if(sequenceNumber >= (int)elems_.size())
        return nullptr;
    return & elems_[sequenceNumber];
}

const sbfElement *sbfMesh::elemPtr(const int sequenceNumber) const
{
    if(sequenceNumber >= (int)elems_.size())
        return nullptr;
    return & elems_[sequenceNumber];
}

int sbfMesh::numElements() const
{
    return (int) elems_.size();
}

int sbfMesh::numNodes() const
{
    return (int) nodes_.size();
}

int sbfMesh::numGroups() const
{
    return (int) elemGroups_.size();
}

int sbfMesh::numNodeGroups() const
{
    return (int) nodeGroups_.size();
}

void sbfMesh::printInfo() const
{
    std::stringstream sstr;
    sstr << "Number of elements " << numElements() << std::endl;
    sstr << "Number of nodes " << nodes_.size() << std::endl;
    std::map<ElementType, size_t> numElementsMap;
    numElementsMap[ElementType::BEAM_LINEAR_3DOF] = 0;
    numElementsMap[ElementType::BEAM_QUADRATIC_3DOF] = 0;
    numElementsMap[ElementType::BEAM_LINEAR_6DOF] = 0;
    numElementsMap[ElementType::BEAM_QUADRATIC_6DOF] = 0;
    numElementsMap[ElementType::RECTANGLE_LINEAR] = 0;
    numElementsMap[ElementType::RECTANGLE_QUADRATIC] = 0;
    numElementsMap[ElementType::TRIANGLE_LINEAR] = 0;
    numElementsMap[ElementType::TRIANGLE_QUADRATIC] = 0;
    numElementsMap[ElementType::HEXAHEDRON_LINEAR] = 0;
    numElementsMap[ElementType::HEXAHEDRON_QUADRATIC] = 0;
    numElementsMap[ElementType::TRIANGLE_PRISM_LINEAR] = 0;
    numElementsMap[ElementType::TRIANGLE_PRISM_QUADRATIC] = 0;
    numElementsMap[ElementType::TETRAHEDRON_LINEAR] = 0;
    numElementsMap[ElementType::TETRAHEDRON_QUADRATIC] = 0;
    numElementsMap[ElementType::NO_DEFINED_ELEMENT] = 0;
    std::map<int, int> mtrMap;
    for(int ct = 0; ct < numElements(); ct++) {
        numElementsMap[elems_[ct].type()]++;
        mtrMap[elems_[ct].mtr()]++;
    }
    sstr << "Elements in mesh:" << std::endl;
    sstr << "Beam 3 DOF linear\t\t" << numElementsMap[ElementType::BEAM_LINEAR_3DOF] << std::endl;
    sstr << "Beam 3 DOF quadratic\t\t" << numElementsMap[ElementType::BEAM_QUADRATIC_3DOF] << std::endl;
    sstr << "Beam 6 DOF linear\t\t" << numElementsMap[ElementType::BEAM_LINEAR_6DOF] << std::endl;
    sstr << "Beam 6 DOF quadratic\t\t" << numElementsMap[ElementType::BEAM_QUADRATIC_6DOF] << std::endl;
    sstr << "Hexahedron linear\t\t" << numElementsMap[ElementType::HEXAHEDRON_LINEAR] << std::endl;
    sstr << "Hexahedron quadratic\t\t" << numElementsMap[ElementType::HEXAHEDRON_QUADRATIC] << std::endl;
    sstr << "Tetrahedron linear\t\t" << numElementsMap[ElementType::TETRAHEDRON_LINEAR] << std::endl;
    sstr << "Tetrahedron quadratic\t\t" << numElementsMap[ElementType::TETRAHEDRON_QUADRATIC] << std::endl;
    sstr << "Undefined elements\t\t" << numElementsMap[ElementType::NO_DEFINED_ELEMENT] << std::endl;
    sstr << "Number of elements groups " << this->numGroups() << std::endl;
    sstr << "Number of nodes groups " << this->numNodeGroups() << std::endl;
    sstr << "Bounding box:" << std::endl << "xMin = " << minX() << "\txMax = " << maxX() << std::endl << "yMin = " << minY() << "\tyMax = " << maxY() << std::endl << "zMin = " << minZ() << "\tzMax = " << maxZ() << std::endl;
    sstr << "Materials in mesh:" << std::endl;
    for(auto m : mtrMap) sstr << m.first << " (" << m.second << ")" << std::endl;
    report(sstr.str());
}
float sbfMesh::max(const int kort) const
{
    int nNode = numNodes();
    if(nNode == 0)
        return -std::numeric_limits<float>::max();
    float max = nodes_[0].crdAtKort(kort), tempF;
    for(int ct = 1; ct < nNode; ct++){
        tempF = nodes_[ct].crdAtKort(kort);
        if(max < tempF)
            max = tempF;
    }
    return max;
}
float sbfMesh::min(const int kort) const
{
    int nNode = numNodes();
    if(nNode == 0)
        return std::numeric_limits<float>::max();
    float min = nodes_[0].crdAtKort(kort), tempF;
    for(int ct = 1; ct < nNode; ct++){
        tempF = nodes_[ct].crdAtKort(kort);
        if(min > tempF)
            min = tempF;
    }
    return min;
}
float sbfMesh::maxX() const
{
    return max(0);
}
float sbfMesh::maxY() const
{
    return max(1);
}
float sbfMesh::maxZ() const
{
    return max(2);
}
float sbfMesh::minX() const
{
    return min(0);
}
float sbfMesh::minY() const
{
    return min(1);
}
float sbfMesh::minZ() const
{
    return min(2);
}

int sbfMesh::addElement(const sbfElement & elem)
{
    /*	return index of new added element	*/
    elems_.push_back(elem);
    elems_.back().setMesh(this);
    return (int)elems_.size()-1;
}
void sbfMesh::insertElement(const sbfElement & elem, int position)
{
    //	elems_.push_back(elem);
    //	elems_.back().setMesh(this);
    if(position < (int)elems_.size()){
        elems_.insert(elems_.begin() + position, elem);
        elems_[position].setMesh(this);
    }
    else{/*throw exception*/}
}

void sbfMesh::deleteElement(int elemID)
{
    if(elemID < (int)elems_.size()){
        elems_.erase(elems_.begin() + elemID);
    }
    else{/*throw exception*/}
}

int sbfMesh::addNode(float x, float y, float z, bool checkExisted, float tol)
{
    /*	return index of new created node or already existed node with tolerance	*/
    sbfNode node(x, y, z);
    return addNode(node, checkExisted, tol);
}
int sbfMesh::addNode(const sbfNode &node, bool checkExisted, float tol)
{
    /*	return index of new created node or already existed node with tolerance	*/
    int nNodes = numNodes();
    if(checkExisted){
        const int numThreads = 8;
        sbfThreadPool pool(numThreads);
        std::array<int, numThreads> ids;
        std::array<std::future<int>, numThreads> futures;
        std::atomic<bool> found(false);
        auto findExisting = [&](int start){
            int foundID = -1;
            for(int ct = start; ct >= 0 && !found.load(); ct -= numThreads)
            {
                if(nodes_[ct].isSame(node, tol)) {
                    foundID = ct;
                    found.store(true);
                    break;
                }
            }
            return foundID;
        };
        for(int ct = 0; ct < numThreads; ++ct)
            futures[ct] = pool.enqueue(findExisting, nNodes-1-ct);
        for(int ct = 0; ct < numThreads; ++ct)
            ids[ct] = futures[ct].get();
        for(int ct = 0; ct < numThreads; ++ct)
            if(ids[ct] != -1) return ids[ct];

//        for(int ct = nNodes-1; ct >= 0; ct--)
//        {
//            if(nodes_[ct].isSame(node, tol))
//                return ct;
//        }

        nodes_.push_back(node);
        return nNodes;
    }
    else{
        nodes_.push_back(node);
        return nNodes;
    }
}
void sbfMesh::deleteNode(int nodeIndex, bool renumberElemIndexes)
{
    if(nodeIndex < static_cast<int>(nodes_.size())){
        if(renumberElemIndexes){
            //Process elements indexes
            const int numThreads = 8;
            sbfThreadPool pool(numThreads);
            std::array<std::future<int>, numThreads> futures;
            for(int ct = 0; ct < numThreads; ++ct)
                futures[ct] = pool.enqueue([&](int start){
                    std::vector<int> indexes;
                    for(size_t elemCt = start; elemCt < static_cast<size_t>(numElements()); elemCt += numThreads){
                        indexes = elems_[elemCt].indexes();
                        bool mod = false;
                        for(size_t nodeCt = 0; nodeCt < indexes.size(); nodeCt++)
                            if(indexes[nodeCt] >= nodeIndex) {
                                indexes[nodeCt]--;
                                mod = true;
                            }
                        if(mod)
                            elems_[elemCt].setNodes(indexes);
                    }
                    return 0;
                }, ct);
            for(int ct = 0; ct < numThreads; ++ct)
                futures[ct].get();
        }
        std::vector<sbfNode>::iterator eraceIterator = nodes_.begin() + nodeIndex;
        nodes_.erase(eraceIterator);
    }
}
int sbfMesh::nodeAt(float x, float y, float z, float tol) const
{
    /*	return index of node at specified coordinates with tolerance
        or -1 otherwise	*/
    int nNodes = numNodes();
    sbfNode node(x, y, z);
    for(int ct = 0; ct < nNodes; ct++)
    {
        if(nodes_[ct].isSame(node, tol))
            return ct;
    }
    return -1;
}
int sbfMesh::mergeNodes(float tol)
{
    //TODO seems to be working, make it parallel (if possible)
    //BUG crashes on complex meshes
    std::vector<int> newInd, oldInd, shiftInd;
    std::vector<int> toDelete;
    std::vector<int> sortX, newSortX;
    std::vector<bool> isMerged;
    newInd.resize(numNodes(), -1);
    shiftInd.resize(numNodes(), 0);
    toDelete.reserve(numNodes());
    isMerged.resize(numNodes(), false);
    int nnodes = numNodes();
    for(int ct = 0; ct < nnodes; ct++)
        newInd[ct] = ct;
    oldInd = newInd;
    sortX = oldInd;

    int numMergedNodes = 0;

    std::vector<float> crdX;
    crdX.resize(nnodes, 0.0);
    for(int ct = 0; ct < nnodes; ct++) crdX[ct] = nodes_[ct].x();
    sbf::quickAssociatedSort<float, int>(&crdX[0], &sortX[0], 0, nnodes-1);
    newSortX = sortX;

    std::vector<int> equalInd;
    equalInd.reserve(nnodes);
    for(int ct1 = 0; ct1 < nnodes-1; ct1++){
        int ind1, ind2;
        ind1 = sortX[ct1];
        if(isMerged[ind1])
            continue;
        equalInd.clear();
        equalInd.push_back(ind1);
        for(int ct2 = ct1 + 1; ct2 < nnodes; ct2++){
            ind2 = sortX[ct2];
            if(isMerged[ind2])
                continue;
            if(crdX[ct2] - crdX[ct1] > tol)
                break;
            sbfNode n1, n2;
            n1 = nodes_[ind1];
            n2 = nodes_[ind2];
            if(fabs(n1.y() - n2.y()) <  tol){
                if(fabs(n1.z() - n2.z()) <  tol){
                    if(n1.distance(n2) < tol)
                        equalInd.push_back(ind2);
                }
            }
        }
        if(equalInd.size() > 1)
        {
            int minInd = equalInd[0], len = (int) equalInd.size();
            for(int ct = 1; ct < len; ct++)
                if(minInd > equalInd[ct])
                    minInd = equalInd[ct];
            for(int ct = 0; ct < len; ct++){
                int tempI = equalInd[ct];
                if(tempI != minInd){
                    toDelete.push_back(tempI);
                    newInd[tempI] = minInd;
                    isMerged[tempI] = true;
                }
            }
        }
    }

    renumberNodes(&newInd[0]);

    sbf::quickSort<int>(&toDelete[0], 0, (int)toDelete.size()-1, sbf::SortDirection::Down);
    for(int ct = 0; ct < (int)toDelete.size(); ct++){//Loop on indexes of nodes to delete
        std::vector<sbfNode>::iterator it = nodes_.begin();
        for(int ct1 = 0; ct1 < toDelete[ct]; ct1++) it++;
        nodes_.erase(it);
    }//Loop on indexes of nodes to delete

    //Evaluate shiftInd
    for(std::vector<int>::iterator it = newInd.begin(), itShift = shiftInd.begin(); it != newInd.end(); it++, itShift++){
        for(std::vector<int>::iterator itDel = toDelete.begin(); itDel != toDelete.end(); itDel++){
            if((*it) > (*itDel)) (*itShift)--;
        }
    }
    numMergedNodes = (int)toDelete.size();

    for(std::vector<sbfElement>::iterator it = elems_.begin(); it != elems_.end(); it++){//Loop on elements to reduce nodes indexes
        std::vector<int> indexes = (*it).indexes();
        for(std::vector<int>::iterator itInd = indexes.begin(); itInd != indexes.end(); itInd++)
            (*itInd) += shiftInd[*itInd];
    }
    return numMergedNodes;
}
void sbfMesh::renumberNodes(int * newIndexes)
{
    std::vector<sbfNode> newNodes;
    newNodes.resize(numNodes());
    for(int ct = 0; ct < numNodes(); ct++)
        newNodes[ct] = nodes_[newIndexes[ct]];
    for(int ct = 0; ct < numNodes(); ct++)
        nodes_[ct] = newNodes[ct];
    newNodes.clear();
    std::vector<int> indexesMap1, indexesMap2;
    indexesMap1.resize(numNodes());
    indexesMap2.resize(numNodes());
    for(int ct = 0; ct < numNodes(); ct++){
        indexesMap1[ct] = newIndexes[ct];
        indexesMap2[ct] = ct;
    }
    sbf::quickAssociatedSort<int, int>(&indexesMap1[0], &indexesMap2[0], 0, numNodes()-1);
    for(std::vector<sbfElement>::iterator it = elems_.begin(); it != elems_.end(); it++){//Loop on elements in mesh
        int nnodes = (*it).numNodes();
        for(int ct = 0; ct < nnodes; ct++)
            (*it).setNode(ct, indexesMap2[(*it).nodeIndex(ct)]);
    }//Loop on elements in mesh
    indexesMap1.clear();
    indexesMap2.clear();
}
sbfElementGroup * sbfMesh::addElementGroup()
{
    sbfElementGroup * gr = new sbfElementGroup();
    gr->setMesh(this);
    elemGroups_.push_back(gr);
    return gr;
}
sbfElementGroup * sbfMesh::addElementGroup(sbfGroupFilter filter)
{
    sbfElementGroup * gr = new sbfElementGroup();
    gr->setMesh(this);
    gr->addFilter(filter);
    elemGroups_.push_back(gr);
    return gr;
}
sbfNodeGroup * sbfMesh::addNodeGroup()
{
    sbfNodeGroup * gr = new sbfNodeGroup();
    gr->setMesh(this);
    nodeGroups_.push_back(gr);
    return gr;
}
sbfNodeGroup * sbfMesh::addNodeGroup(sbfGroupFilter filter)
{
    sbfNodeGroup * gr = new sbfNodeGroup();
    gr->setMesh(this);
    gr->addFilter(filter);
    nodeGroups_.push_back(gr);
    return gr;
}
void sbfMesh::processElemGroups()
{
    for(int ct = 0; ct < numGroups(); ct++)
    {
        elemGroups_[ct]->clearGroup();
        for(int ct1 = 0; ct1 < elemGroups_[ct]->numFilters(); ct1++)
        {
            sbfGroupFilter filter = elemGroups_[ct]->filter(ct1);
            for(int ct2 = 0; ct2 < numElements(); ct2++)
                if(filter.isPass(elems_[ct2]))
                    elemGroups_[ct]->addElement(ct2, false);
        }
    }
}
void sbfMesh::processElemGroup(const int sequenceNumber)
{
    elemGroups_[sequenceNumber]->clearGroup();
    for(int ct1 = 0; ct1 < elemGroups_[sequenceNumber]->numFilters(); ct1++)
    {
        sbfGroupFilter filter = elemGroups_[sequenceNumber]->filter(ct1);
        for(int ct2 = 0; ct2 < numElements(); ct2++)
            if(filter.isPass(elems_[ct2]))
                elemGroups_[sequenceNumber]->addElement(ct2);
    }
}
void sbfMesh::processNodeGroups()
{
    for(int ct = 0; ct < numNodeGroups(); ct++)
        processNodeGroup(ct);
}
void sbfMesh::processNodeGroup(const int sequenceNumber)
{
    nodeGroups_[sequenceNumber]->clearGroup();
    for(int ct1 = 0; ct1 < nodeGroups_[sequenceNumber]->numFilters(); ct1++)
    {
        sbfGroupFilter filter = nodeGroups_[sequenceNumber]->filter(ct1);
        for(int ct2 = 0; ct2 < numNodes(); ct2++)
            if(filter.isPass(nodes_[ct2]))
                nodeGroups_[sequenceNumber]->addNode(ct2);
    }
}
void sbfMesh::clearElemGroups()
{
    for(size_t ct = 0; ct < elemGroups_.size(); ct++) delete elemGroups_[ct];
    elemGroups_.clear();
}
void sbfMesh::clearNodeGroups()
{
    for(size_t ct = 0; ct < nodeGroups_.size(); ct++) delete nodeGroups_[ct];
    nodeGroups_.clear();
}
void sbfMesh::clearAllGroups()
{
    for(size_t ct = 0; ct < elemGroups_.size(); ct++) delete elemGroups_[ct];
    elemGroups_.clear();
    for(size_t ct = 0; ct < nodeGroups_.size(); ct++) delete nodeGroups_[ct];
    nodeGroups_.clear();
}

std::vector<std::list<sbfMesh::sbfMeshBorderFace> > sbfMesh::computeBorderFaces(float normalAngleThreashold)
{
    borderFaces_.clear();
    borderFaces_.shrink_to_fit();

    //Find all external faces;

    report.createNewProgress("Find all external faces");

    std::vector<std::set<size_t>> connectivity;

    struct fhData{
        int elemID, faceID;
        size_t hash;
    };
    std::list<fhData> allFaces;
    auto getPartialList = [this, &r = report](int elemStartID, size_t length){
        std::list<fhData> partList;
        for(int ctElem = elemStartID; ctElem < elemStartID + length; ++ctElem) {
            const auto hs = elemPtr(ctElem)->facesHashes();
            for(int ctFace = 0; ctFace < hs.size(); ++ctFace){
                fhData d;
                d.elemID = ctElem;
                d.faceID = ctFace;
                d.hash = hs[ctFace];
                partList.push_back(d);
            }
            if(elemStartID == 0 && (ctElem - elemStartID) % (length/100 + 1) == 0){
                r.updateProgress(elemStartID, elemStartID + length, ctElem);
            }
        }
        return partList;
    };

    const int numAllElems = numElements();
    const int perProcPortion = numAllElems / sbfNumThreads;
    int remainingStart = 0;
    std::list<std::future<std::list<fhData>>> futures;
    if(perProcPortion > 0) {
        //Do async jobs
        for(int ct = 0; ct < sbfNumThreads - 1; ++ct){
            futures.push_back(std::async(std::launch::async, getPartialList, remainingStart, perProcPortion));
            remainingStart += perProcPortion;
        }
    }
    allFaces = getPartialList(remainingStart, numAllElems - remainingStart);
    for(auto &f : futures){
        auto partList = f.get();
        allFaces.splice(allFaces.begin(), partList);
    }
    allFaces.sort([](const fhData& left, const fhData& right){return left.hash < right.hash;});

    report.finalizeProgress();

    connectivity.resize(numAllElems);

    std::list<fhData> uniqueFaces;
    auto next = allFaces.begin();
    std::advance(next, 1);
    auto end = allFaces.end();
    auto end_m1 = end;
    std::advance(end_m1, -1);
    for(auto it = allFaces.begin(); next != end && it != end; ++it, ++next){
        if(it->hash != next->hash) {
            uniqueFaces.push_back(*it);
            if(next == end_m1)
                uniqueFaces.push_back(*next);
        }
        else{
            //it and next connected
            connectivity[it->elemID].insert(next->elemID);
            connectivity[next->elemID].insert(it->elemID);
            ++it;
            ++next;
        }
    }

    uniqueFaces.sort([](const fhData& left, const fhData& right){
        if(left.elemID != right.elemID)
            return left.elemID < right.elemID;
        else return left.faceID < right.faceID;
    });

    borderFaces_.reserve(uniqueFaces.size());
    for(auto itU = uniqueFaces.begin(); itU != uniqueFaces.end(); itU++){
        sbfMeshBorderFace f;
        f.elemID = itU->elemID;
        f.faceID = itU->faceID;
        borderFaces_.emplace_back(std::list<sbfMeshBorderFace>{f});
    }

    std::for_each(borderFaces_.begin(), borderFaces_.end(), [this](std::list<sbfMesh::sbfMeshBorderFace> &faces){
        for(auto &f : faces){
            if(this->elemPtr(f.elemID)->type() != ElementType::HEXAHEDRON_LINEAR)
                report.error("This algorithm works only with hexa elements");
            f.nodeIDs = this->elemPtr(f.elemID)->facesNodesIndexes()[f.faceID];
            f.norms.reserve(f.nodeIDs.size());
            f.norms.emplace_back(node(f.nodeIDs[0]).normal(node(f.nodeIDs[1]), node(f.nodeIDs.back())));
            for(int ct = 1; ct < f.nodeIDs.size()-1; ++ct){
                f.norms.emplace_back(node(f.nodeIDs[ct]).normal(node(f.nodeIDs[ct+1]), node(f.nodeIDs[ct-1])));
            }
            f.norms.emplace_back(node(f.nodeIDs.back()).normal(node(f.nodeIDs[0]), node(f.nodeIDs[f.nodeIDs.size()-2])));
        }
    });

    //Cluster faces with continuous normal

    std::list<std::pair<size_t, size_t>> toCollapse;
    {

        report.createNewProgress("Clustering faces");

        auto checkFunc = [
                &bundle = std::as_const(borderFaces_),
                &connectivity/* = std::as_const(connectivity)*/,
                this,normalAngleThreashold
                ](size_t baseID, size_t compareID){
            const auto &baseFaces = bundle[baseID];
            const auto &compareFaces = bundle[compareID];
            for(const auto &fb : baseFaces){
                for(const auto &fc : compareFaces){
                    if(connectivity[fb.elemID].count(fc.elemID) == 0)
                        continue;
                    //FIXME make better comparision
                    //For now just one-by-one node checking
                    //Should be edge comparision
                    for(int ctB = 0; ctB < fb.nodeIDs.size(); ++ctB){
                        for(int ctC = 0; ctC < fc.nodeIDs.size(); ++ctC) {
                            if(fb.nodeIDs[ctB] == fc.nodeIDs[ctC]){
                                auto angle = std::fabs(node(fb.nodeIDs[ctB]).angleVal(fb.norms[ctB], fc.norms[ctC]));
                                if(angle <= normalAngleThreashold)
                                    return true;
                            }
                        }
                    }
                }
            }
            return false;
        };

        std::list<std::future<std::list<std::pair<size_t, size_t>>>> futures;

        auto proc = [checkFunc, &r = report](size_t startID, size_t step, size_t stopID){
            std::list<std::pair<size_t, size_t>> toCollapseProc;
            for(auto ct = startID; ct < stopID-1; ct += step){
                for(auto ctCheck = ct + 1; ctCheck < stopID; ++ctCheck)
                    if(checkFunc(ct, ctCheck))
                        toCollapseProc.push_back(std::make_pair(ct, ctCheck));
                if(startID == 0 && (ct - startID) % ((stopID - startID) / 100 + 1) == 0)
                    r.updateProgress(startID, stopID, ct);
            }
            return toCollapseProc;
        };

        const int numBorders = borderFaces_.size();
        const int perProcPortion = numBorders / sbfNumThreads;
        size_t seedID = 0;
        size_t step = 1;
        if(perProcPortion > 0) {
            //Do async jobs
            step = sbfNumThreads;
            for(int ct = 0; ct < sbfNumThreads - 1; ++ct){
                futures.push_back(std::async(std::launch::async, proc, seedID, step, borderFaces_.size()));
                ++seedID;
            }
        }
        toCollapse = proc(seedID, step, borderFaces_.size());
        for(auto &f : futures){
            auto partList = f.get();
            toCollapse.splice(toCollapse.begin(), partList);
        }

        toCollapse.sort([=](const std::pair<size_t, size_t> &left, const std::pair<size_t, size_t> &right){
            return left.second > right.second;
        });

        report.finalizeProgress();

        auto tc = toCollapse.begin();
        std::set<size_t> collapseSet;
        collapseSet.insert(tc->first);
        collapseSet.insert(tc->second);
        auto collapsing = [&](){
            auto it = collapseSet.begin();
            auto end = collapseSet.end();
            --end;
            for(; it != end; ++it)
                borderFaces_[*it].splice(borderFaces_[*it].end(), borderFaces_[*end]);
            borderFaces_.erase(borderFaces_.begin() + *end);
        };
        for(; tc != toCollapse.end(); ++tc) {
            if(tc->second != *collapseSet.crbegin()){
                collapsing();
                collapseSet.clear();
            }
            collapseSet.insert(tc->first);
            collapseSet.insert(tc->second);
        }
        collapsing();
        borderFaces_.shrink_to_fit();
    }
    return borderFaces_;
}

void sbfMesh::addMesh(sbfMesh & mesh, bool passGroups, bool checkExisted, float tol)
{
    //Add existed mesh content [and pass] groups to current mesh

    int nnodes = mesh.numNodes();
    std::vector <int> newInd;
    newInd.resize(nnodes, -1);
    for(int ct = 0; ct < nnodes; ct++)
        newInd[ct] = addNode(mesh.node(ct), checkExisted, tol);
    int nelem = mesh.numElements();
    for(int ct = 0; ct < nelem; ct++){
        sbfElement el = mesh.elem(ct);
        for(int ct1 = 0; ct1 < el.numNodes(); ct1++)
            el.setNode(ct1, newInd[el.nodeIndex(ct1)]);
        addElement(el);
    }
    if(passGroups)
    {
        //TODO Not implemented yet!!!!
    }
}
void sbfMesh::addMesh(const sbfMesh *mesh, bool passGroups, bool checkExisted, float tol)
{
    //Add existed mesh content [and pass] groups to current mesh

    int nnodes = mesh->numNodes();
    std::vector <int> newInd;
    newInd.resize(nnodes, -1);
    for(int ct = 0; ct < nnodes; ct++)
        newInd[ct] = addNode(mesh->node(ct), checkExisted, tol);
    int nelem = mesh->numElements();
    for(int ct = 0; ct < nelem; ct++){
        sbfElement el = mesh->elem(ct);
        for(int ct1 = 0; ct1 < el.numNodes(); ct1++)
            el.setNode(ct1, newInd[el.nodeIndex(ct1)]);
        addElement(el);
    }
    if(passGroups)
    {
        //TODO Not implemented yet!!!!
    }
}

void sbfMesh::setMtr(int mtr)
{
    applyToAllElements([=](sbfElement&elem){elem.setMtr(mtr);});
}

void sbfMesh::increaseMtr(int shift)
{
    applyToAllElements([=](sbfElement&elem){elem.setMtr(elem.mtr()+shift);});
}

void sbfMesh::replaceMtr(int oldID, int newID)
{
    applyToAllElements([=](sbfElement&elem){if(elem.mtr() == oldID) {elem.setMtr(newID);}});
}

//Geometry modifications
void sbfMesh::scale(float scaleX, float scaleY, float scaleZ)
{
    //FIXME what to do with negative or zero scales?
    int nnode = numNodes();
    //TODO parallelize this
    for(int ct = 0; ct < nnode; ct++){
        nodes_[ct].setX(nodes_[ct].x()*scaleX);
        nodes_[ct].setY(nodes_[ct].y()*scaleY);
        nodes_[ct].setZ(nodes_[ct].z()*scaleZ);
    }
}
void sbfMesh::scale(float scale_)
{
    scale(scale_, scale_, scale_);
}
void sbfMesh::translate(float transX, float transY, float transZ)
{
    int nnode = numNodes();
    //TODO parallelize this
    for(int ct = 0; ct < nnode; ct++){
        nodes_[ct].setX(nodes_[ct].x() + transX);
        nodes_[ct].setY(nodes_[ct].y() + transY);
        nodes_[ct].setZ(nodes_[ct].z() + transZ);
    }
}
void sbfMesh::rotate(float rotX, float rotY, float rotZ)
{
    //Rotate around vector (rotX, rotY, rotZ) to angle |(rotX, rotY, rotZ)|

    //Generate rotate matrix.
    float angle, dirx, diry, dirz, cs, sn;
    angle = sqrt(pow(rotX, (float)2.0) + pow(rotY, (float)2.0) + pow(rotZ, (float)2.0));
    if(angle == 0) return;
    dirx = rotX/angle;
    diry = rotY/angle;
    dirz = rotZ/angle;
    cs = cos(angle);
    sn = sin(angle);
    float L[3][3];

    L[0][0] = cs + dirx*dirx*(1.0f - cs);
    L[0][1] = dirx*diry*(1.0f - cs) - dirz*sn;
    L[0][2] = dirx*dirz*(1.0f - cs) + diry*sn;

    L[1][0] = dirx*diry*(1.0f - cs) + dirz*sn;
    L[1][1] = cs + diry*diry*(1.0f - cs);
    L[1][2] = diry*dirz*(1.0f - cs) - dirx*sn;

    L[2][0] = dirx*dirz*(1.0f - cs) - diry*sn;
    L[2][1] = diry*dirz*(1.0f - cs) + dirx*sn;
    L[2][2] = cs + dirz*dirz*(1.0f - cs);

    int nnode = numNodes();
    //TODO parallelize this
    for(int ct = 0; ct < nnode; ct++){
        float crd_[3];
        crd_[0] = nodes_[ct].x();
        crd_[1] = nodes_[ct].y();
        crd_[2] = nodes_[ct].z();
        nodes_[ct].setX(L[0][0]*crd_[0] + L[0][1]*crd_[1] + L[0][2]*crd_[2]);
        nodes_[ct].setY(L[1][0]*crd_[0] + L[1][1]*crd_[1] + L[1][2]*crd_[2]);
        nodes_[ct].setZ(L[2][0]*crd_[0] + L[2][1]*crd_[1] + L[2][2]*crd_[2]);
    }
}

sbfElementGroup * sbfMesh::elemGroup(const int sequenceNumber) const
{
    return elemGroups_[sequenceNumber];
}
sbfNodeGroup * sbfMesh::nodeGroup(const int sequenceNumber) const
{
    return nodeGroups_[sequenceNumber];
}
void sbfMesh::reserveNodesNumber(const int newNodesNumber)
{
    nodes_.reserve(newNodesNumber);
}
void sbfMesh::reserveElementsNumber(const int newElemsNumber)
{
    elems_.reserve(newElemsNumber);
}

void sbfMesh::optimizeNodesNumbering(RenumberOptimizationType type, bool makeReport)
{
    /*
     * This code based on procedures from RCMW2.cpp of sbfv_2011
     */

    int numNodes = this->numNodes();
    size_t size = 0;
    int startNode = 0;
    int *newToOld, *oldToNew;
    int ** graph;

    newToOld = new int [numNodes];
    oldToNew = new int [numNodes];

    graph = nullptr;
    computeGraphAlter(this, &graph, makeReport);
    size = computeProfileSize(graph, numNodes);
    if ( makeReport ) report("Until number optimization: size = ", size, " bandwidth = ", computeBandwidth(graph, numNodes));

    switch(type){
    default:
    case RenumberOptimizationType::SIMPLE:
        startNode = 0;
        break;
    case RenumberOptimizationType::FIND_FIRST_NODE:
        startNode = findStartNode(graph, numNodes);
        break;
    }

    makeRCM(graph, numNodes, startNode, newToOld, oldToNew);
    renumberNodes(newToOld);

    for(int ct = 0; ct < numNodes; ct++) delete [] graph[ct];
    delete [] graph;

    computeGraphAlter(this, &graph, makeReport);
    size = computeProfileSize(graph, numNodes);
    if ( makeReport ) report("After number optimization: size = ", size, " bandwidth = ", computeBandwidth(graph, numNodes));

    for(int ct = 0; ct < numNodes; ct++) delete [] graph[ct];
    delete [] graph;

    delete [] newToOld;
    delete [] oldToNew;
}

void sbfMesh::applyToAllNodes(std::function<void (sbfNode &)> lambda)
{
    for(auto & node : nodes_) lambda(node);
}

void sbfMesh::applyToAllElements(std::function<void (sbfElement &)> lambda)
{
    for(auto & elem : elems_) lambda(elem);
}

void sbfMesh::applyToAllElements(std::function<void (const sbfElement &)> lambda) const
{
    for(auto & elem : elems_) lambda(elem);
}
void computeGraph(sbfMesh * mesh, int *** graph, bool makeReport)
{
    std::list<int> neighbors;
    int * mask;
    int numMask;
    int numNodes = mesh->numNodes();
    int numElems = mesh->numElements();
    int **localGraph;

    //FIXME Possible leak of memory
    localGraph = new int * [numNodes];
    mask = new int [numNodes];
    numMask = 0;

    //Graph computing
    if ( makeReport ) report.createNewProgress("Computing graph");
    for(int curNode = 0; curNode < numNodes; curNode++){//Loop on nodes
        if ( makeReport && curNode % (numNodes/20 > 0 ? numNodes/20 : 1) == 0)
            report.updateProgress(0, numNodes-1, curNode);
        numMask = 0;
        //Find elements which contains node "curNode"
        for(int curElem = 0; curElem < numElems; curElem++){//Loop on elements
            sbfElement * elem = mesh->elemPtr(curElem);
            std::vector<int> indexes = elem->indexes();
            int numElemNodes = (int)indexes.size();
            for(int ct = 0; ct < numElemNodes; ct++){//Loop on nodes in element
                if(indexes[ct] == curNode){
                    mask[numMask++] = curElem;
                    break;
                }
            }//Loop on nodes in element
        }//Loop on elements
        //Find neighbors for node "curNode"
        neighbors.clear();
        for(int elemCt = 0; elemCt < numMask; elemCt++){//Loop on elements
            int curElem = mask[elemCt];
            //numNeighborsOld = numNeighbors;
            sbfElement * elem = mesh->elemPtr(curElem);
            std::vector<int> indexes = elem->indexes();
            int numElemNodes = (int)indexes.size();
            for(int ct = 0; ct < numElemNodes; ct++){//Loop on nodes in element
                neighbors.push_back(indexes[ct]);
            }//Loop on nodes in element
        }//Loop on elements
        neighbors.sort();
        neighbors.unique();
        neighbors.remove(curNode);
        localGraph[curNode] = new int [neighbors.size()+1];
        localGraph[curNode][0] = (int)neighbors.size();
        int count = 1;
        for(std::list<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) localGraph[curNode][count++] = *it;
    }//Loop on nodes
    if ( makeReport ) report.finalizeProgress();

    neighbors.clear();
    delete [] mask;
    *graph = localGraph;
}
void computeGraphAlter(sbfMesh * mesh, int *** graph, bool makeReport)
{
    std::list<int> neighbors;
    std::vector<std::list<int>> elemInd;
    int * mask;
    //int numNeighbors, numMask;//, numNeighborsOld;
    int numNodes = mesh->numNodes();
    int numElems = mesh->numElements();
    int **localGraph;

    elemInd.resize(numNodes);
    //FIXME Possible leak of memory
    localGraph = new int * [numNodes];
    mask = new int [numNodes];
    //numMask = 0;
    //numNeighbors = 0;

    //Graph computing
    if ( makeReport ) report.createNewProgress("Computing graph: Pass I:");
    int curElem;
    for(curElem = 0; curElem < numElems; curElem++){//Loop on elements
        if ( makeReport && curElem % (numElems/4 > 0 ? numElems/4 : 1) == 0)
            report.updateProgress(0, numElems, curElem);
        sbfElement * elem = mesh->elemPtr(curElem);
        std::vector<int> indexes = elem->indexes();
        int numElemNodes = (int)indexes.size();
        for(int ct = 0; ct < numElemNodes; ct++){//Loop on nodes in element
            elemInd[indexes[ct]].push_back(curElem);
        }//Loop on nodes in element
    }//Loop on elements
    if ( makeReport ) report.finalizeProgress();
    if ( makeReport ) report.createNewProgress("Computing graph: Pass II:");
    int curNode;
    for(curNode = 0; curNode < numNodes; curNode++){//Loop on nodes
        if ( makeReport && curNode % (numNodes/4 > 0 ? numNodes/4 : 1) == 0)
            report.updateProgress(0, numNodes, curNode);
        neighbors.clear();
        std::list<int>::iterator it, itStart, itStop;
        itStart = elemInd[curNode].begin();
        itStop = elemInd[curNode].end();
        for(it = itStart; it != itStop; it++){//Loop on elements which contain curNode
            sbfElement * elem = mesh->elemPtr(*it);
            std::vector<int> indexes = elem->indexes();
            int numElemNodes = (int)indexes.size();
            for(int ct = 0; ct < numElemNodes; ct++)
                neighbors.push_back(indexes[ct]);
        }//Loop on elements which contain curNode
        neighbors.sort();
        neighbors.unique();
        neighbors.remove(curNode);
        localGraph[curNode] = new int [neighbors.size()+1];
        localGraph[curNode][0] = (int)neighbors.size();
        int count = 1;
        for(std::list<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) localGraph[curNode][count++] = *it;
    }//Loop on nodes
    if ( makeReport ) report.finalizeProgress();

    neighbors.clear();
    delete [] mask;
    *graph = localGraph;
}
size_t computeProfileSize(int ** graph, int numNodes, bool * flagOverFlow)
{
    size_t size = 0, threthold = std::numeric_limits<size_t>::max()/100*99;
    bool flagOF = false;
    for(int ct = 0; ct < numNodes; ct++){
        int bandwidth = graph[ct][1] < ct ? ct - graph[ct][1] : 0;
        size += bandwidth*9;
        size++;
        if(size > threthold)
            flagOF = true;
    }
    if(flagOverFlow)
     *flagOverFlow = flagOF;
    return size;
}
int computeBandwidth(int ** graph, int numNodes)
{
    int bandwidth = 0;
    for(int ct = 0; ct < numNodes; ct++)
        bandwidth = ct - graph[ct][1] > bandwidth ? ct - graph[ct][1] : bandwidth;
    return bandwidth*3;
}
void findUnnumberedNeighbors(int ** graph, int * mask, int * tmp, /*I do not know better name*/ int & count, int * deg, int nodeCt)
{
    count = 0;
    for(int ct = 1; ct <= graph[nodeCt][0]; ct++){
        if(mask[graph[nodeCt][ct]] != 1){
            tmp[count] = graph[nodeCt][ct];
            deg[count] = graph[tmp[count]][0];
            count++;
        }
    }
    sbf::quickAssociatedSort<int, int>(deg, tmp, 0, count-1);
}
void makeRCM(int ** graph, int numNodes, int startNode, int * newToOld, int *oldToNew)
{
    int *mask, *unnumberedNeighbors, *tmp, *deg;
    int numUnnumberedNeighbors, count;
    mask = new int [numNodes];
    unnumberedNeighbors = new int [numNodes];
    tmp = new int [numNodes];
    deg = new int [numNodes];

    for(int ct = 0; ct < numNodes; ct++){mask[ct] = 0; unnumberedNeighbors[ct] = -1; tmp[ct] = deg[ct] = -1;}
    newToOld[0] = startNode;
    mask[startNode] = 1;
    numUnnumberedNeighbors = 0;

    int curNode;
    for(curNode = 0; curNode < numNodes - 1; curNode++){//Loop on nodes
        findUnnumberedNeighbors(graph, mask, tmp, count, deg, newToOld[curNode]);
        for(int ct = 0; ct < count; ct++){
            unnumberedNeighbors[numUnnumberedNeighbors] = tmp[ct];
            mask[tmp[ct]] = 1;
            numUnnumberedNeighbors++;
        }
        newToOld[curNode + 1] = unnumberedNeighbors[curNode];
        if(newToOld[curNode + 1] == -1){
            report.error("makeRCM error newToOld[", curNode + 1, "] == -1, tmp = ", count);
            break;
        }
    }//Loop on nodes
    if(curNode < numNodes - 1)
        for(int ct = 0; ct < numNodes; ct++)
            newToOld[ct] = ct;

    int ct1 = 0, ct2 = numNodes-1;
    while(ct1 < ct2){
        int temp = newToOld[ct1];
        newToOld[ct1] = newToOld[ct2];
        newToOld[ct2] = temp;
        ct1++; ct2--;
    }

    for(int ct = 0; ct < numNodes; ct++) oldToNew[newToOld[ct]] = ct;

    delete [] mask;
    delete [] unnumberedNeighbors;
    delete [] tmp;
    delete [] deg;
}
int findStartNode(int ** graph, int numNodes)
{
    int index, minNumNeighbors;
    index = 0; minNumNeighbors = graph[index][0];
    for(int ct = 1; ct < numNodes; ct++){
        if(minNumNeighbors > graph[ct][0]){
            minNumNeighbors = graph[ct][0];
            index = ct;
        }
    }
    return index;
}

ElementType tryToResolveTypeByNumNodes(int numNodes, int kort)
{
    switch ( kort ) {
    case 3:
    {
        switch ( numNodes ) {
        case 8:
            return ElementType::HEXAHEDRON_LINEAR;
        case 20:
            return ElementType::HEXAHEDRON_QUADRATIC;
        case 4:
            return ElementType::TETRAHEDRON_LINEAR;
        case 10:
            return ElementType::TETRAHEDRON_QUADRATIC;
        case 2:
            return ElementType::BEAM_LINEAR_3DOF;
        case 3:
            return ElementType::BEAM_QUADRATIC_3DOF;
        default:
            return ElementType::NO_DEFINED_ELEMENT;
        }
    }
    default:
        return ElementType::NO_DEFINED_ELEMENT;
    }
}
int typesLibToFile(const ElementType & type)
{
    //Convert internal element type to sba ind file format
    switch ( type ) {
    case ElementType::BEAM_LINEAR_3DOF:
        return 10;
    case ElementType::BEAM_QUADRATIC_3DOF:
        return 11;
    case ElementType::BEAM_LINEAR_6DOF:
        return 8;
    case ElementType::BEAM_QUADRATIC_6DOF:
        return 9;
    case ElementType::RECTANGLE_LINEAR:
        return 6;
    case ElementType::HEXAHEDRON_LINEAR:
        return 0;
    case ElementType::HEXAHEDRON_QUADRATIC:
        return 1;
    case ElementType::TETRAHEDRON_LINEAR:
        return 4;
    case ElementType::TETRAHEDRON_QUADRATIC:
        return 5;
    default:
        return -1;
    }
}
ElementType typesFileToLib(const int type)
{
    //Convert sba ind file type of element to internal library element type
    switch ( type ) {
    case 10:
        return ElementType::BEAM_LINEAR_3DOF;
    case 11:
        return ElementType::BEAM_QUADRATIC_3DOF;
    case 8:
        return ElementType::BEAM_LINEAR_6DOF;
    case 9:
        return ElementType::BEAM_QUADRATIC_6DOF;
    case 6:
        return ElementType::RECTANGLE_LINEAR;
    case 0:
        return ElementType::HEXAHEDRON_LINEAR;
    case 1:
        return ElementType::HEXAHEDRON_QUADRATIC;
    case 4:
        return ElementType::TETRAHEDRON_LINEAR;
    case 5:
        return ElementType::TETRAHEDRON_QUADRATIC;
    default:
        return ElementType::NO_DEFINED_ELEMENT;
    }
}
