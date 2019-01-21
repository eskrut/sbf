#ifndef SBFNODESDATA_H
#define SBFNODESDATA_H

#include <climits>

template < class ArrayType, int numComp> class NodesData
//template holder for nodes data
{
public:
    NodesData(std::string name, const sbfMesh* mesh);
    NodesData(std::string name, int numNodes);
    NodesData(const sbfMesh *mesh);
    NodesData(int numNodes);
    ~NodesData();
    enum Type{ // Note that file writing is always store data by kort, while during solution data usually stored by nodes.
        ByNodes,	// Store information in sequence by nodes i.e. XYZXYZ...XYZ
        ByKort		// Store information in sequence by kort i.e. XX...XXYY...YYZZ...ZZ
    };
private:
    ArrayType *data_;
    int numNodes_;
    std::string name_;
    const sbfMesh *mesh_;
    std::string extension_;
    int numDigits_;
    int stepToProceed_;
    Type type_;
    void init();
    void free();
public:
    ArrayType * data(); // Return pointer to data
    ArrayType *data() const;
    ArrayType &data(int nodeIndex, int compIndex); // Return  reference to value of specific component in specific node
    ArrayType data(int nodeIndex, int compIndex) const;
    //! Return data assuming type_ == ByNodes
    ArrayType operator()(int nodeIndex, int compIndex) const;
    ArrayType &operator()(int nodeIndex, int compIndex);
    void null(){if( data_ != nullptr) for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = 0.0; }
    void copyData(ArrayType * data) { if( !data_ ) init(); for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = data[ct];}
    void copyData(const NodesData<ArrayType, numComp> & nodesData) { if(!data_) init(); ArrayType * srcData = nodesData.data(); if(srcData) for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = srcData[ct]; }
    //void setNumNodes(int numNodes);
    int numNodes();
    int numComponents();
    std::string & name();
    void setStep(int step) {stepToProceed_ = step;}
    int step() const {return stepToProceed_;}
    void setName(const char * name) {name_ = name;}
    void setName(const std::string &name) {setName(name.c_str());}
    void setNumDigits(int numDigits) {numDigits_ = numDigits;}
    int numDigits() const {return numDigits_;}
    void setExtention(const char *extension) {extension_ = extension;}
    std::string extention() const {return extension_;}
    Type type() {return type_;}
    void setType(Type type) {type_ = type;}
    const sbfMesh *mesh() const {return mesh_;}
    template <class StorageType = DefaultStorageDataType> int writeToFile(const char *name, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int readFromFile(const char * name, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int writeToFile();//Short forms
    template <class StorageType = DefaultStorageDataType> int readFromFile();
    template <class StorageType = DefaultStorageDataType, int numInOneFile> int writeToFileSplited();
    bool exist();//Check if file with current step exists
    static bool exist(const char *name, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    int numExistedSteps();

    //Useful mathematics functions
    NodesData<ArrayType, numComp> operator+(/*const */NodesData<ArrayType, numComp> & right)
    {
        NodesData<ArrayType, numComp> result(this->numNodes());
        ArrayType *srcDataLeft = this->data(), *srcDataRight = right.data(), *trgData = result.data();
        if(srcDataLeft && srcDataRight)
            for(int ct = 0; ct < numNodes_*numComp; ct++)
                trgData[ct] = srcDataLeft[ct] + srcDataRight[ct];
        return result;
    }
    NodesData<ArrayType, numComp> operator-(/*const */NodesData<ArrayType, numComp> & right)
    {
        NodesData<ArrayType, numComp> result(this->numNodes());
        ArrayType *srcDataLeft = this->data(), *srcDataRight = right.data(), *trgData = result.data();
        if(srcDataLeft && srcDataRight)
            for(int ct = 0; ct < numNodes_*numComp; ct++)
                trgData[ct] = srcDataLeft[ct] - srcDataRight[ct];
        return result;
    }
    NodesData<ArrayType, numComp> operator*(const ArrayType & mult)
    {
        NodesData<ArrayType, numComp> result(this->numNodes());
        ArrayType *srcDataLeft = this->data(), *trgData = result.data();
        if(srcDataLeft)
            for(int ct = 0; ct < numNodes_*numComp; ct++)
                trgData[ct] = srcDataLeft[ct]*mult;
        return result;
    }
    void operator*=(const ArrayType & mult)
    {
            for(int ct = 0; ct < numNodes_*numComp; ct++)
                data_[ct] *= mult;
    }
    ArrayType scalMul(/*const */NodesData<ArrayType, numComp> & nodesData)
    {
        ArrayType sum = std::numeric_limits<ArrayType>::quiet_NaN();
        ArrayType * srcData = nodesData.data(), * thisData = this->data();
        if(srcData && thisData) {
            sum = 0;
            for(int ct = 0; ct < numNodes_*numComp; ct++)
                sum += thisData[ct]*srcData[ct];
        }
        return sum;
    }

    //Some info
    ArrayType max(int dof) const;
    ArrayType min(int dof) const;
};


template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(std::string name, const sbfMesh *mesh) : data_(nullptr), numNodes_(0) , name_(name), mesh_(mesh), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { numNodes_ = mesh ? mesh->numNodes() : 0; init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(std::string name, int numNodes) : data_(nullptr), numNodes_(numNodes) , name_(name), mesh_(nullptr), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(const sbfMesh* mesh) : data_(nullptr), numNodes_(0) , name_("data"), mesh_(mesh), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { numNodes_ = mesh ? mesh->numNodes() : 0; init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::NodesData(int numNodes) : data_(nullptr), numNodes_(numNodes) , name_("data"), mesh_(nullptr), extension_(".sba"), numDigits_(4), stepToProceed_(1), type_(ByNodes) { init(); }

template < class ArrayType, int numComp>
NodesData<ArrayType, numComp>::~NodesData() { free(); }

template < class ArrayType, int numComp>
void NodesData<ArrayType, numComp>::init() { free(); data_ = new ArrayType [numComp*numNodes_]; }

template < class ArrayType, int numComp>
void NodesData<ArrayType, numComp>::free() { if(data_ != nullptr) delete [] data_; }

template < class ArrayType, int numComp>
ArrayType * NodesData<ArrayType, numComp>::data() { return data_; }

template < class ArrayType, int numComp>
ArrayType * NodesData<ArrayType, numComp>::data() const { return data_; }

template < class ArrayType, int numComp>
ArrayType & NodesData<ArrayType, numComp>::data(int nodeIndex, int compIndex)
{
    assert(nodeIndex < numNodes_);
    assert( compIndex < numComp );
    if(type_ == ByNodes)
        return data_[nodeIndex*numComp+compIndex];
    else /*if(type_ == ByKort)*/
        return data_[compIndex*numNodes_+nodeIndex];
}

template < class ArrayType, int numComp>
ArrayType NodesData<ArrayType, numComp>::data(int nodeIndex, int compIndex) const
{
    assert(nodeIndex < numNodes_);
    assert(compIndex < numComp);
    if(type_ == ByNodes)
        return data_[nodeIndex*numComp+compIndex];
    else /*if(type_ == ByKort)*/
        return data_[compIndex*numNodes_+nodeIndex];
}

template < class ArrayType, int numComp>
ArrayType NodesData<ArrayType, numComp>::operator()(int nodeIndex, int compIndex) const { return *(data_ + numComp*nodeIndex + compIndex); }

template < class ArrayType, int numComp>
ArrayType &NodesData<ArrayType, numComp>::operator()(int nodeIndex, int compIndex) { return *(data_ + numComp*nodeIndex + compIndex); }

template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numNodes() { return numNodes_; }

template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numComponents() { return numComp; }

template < class ArrayType, int numComp>
std::string & NodesData<ArrayType, numComp>::name() { return name_; }

template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::writeToFile(const char * name, int step, const char * extension, int numDigits, const char *catalog)
{
    name_ = name; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << name << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
    if(!out.good()) {
        report.error("Error while writing file \"", sstr.str(), "\"");
        return 1;
    }
    //TODO implement compile time ArrayType comparison
    if(typeid(StorageType) == typeid(ArrayType)){
        if(type_ == ByNodes){
            ArrayType * storageData = new ArrayType [numNodes_*numComp];
            for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = data_[ct1*numComp+ct];
            out.write((const char *)storageData, sizeof(ArrayType)*numNodes_*numComp);
            delete [] storageData;
        }
        else if(type_ == ByKort)
            out.write((const char *)data_, sizeof(ArrayType)*numNodes_*numComp);
    }
    else{
        StorageType * storageData = new StorageType [numNodes_*numComp];
        if(type_ == ByNodes)
            for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) storageData[ct*numNodes_+ct1] = static_cast<StorageType>(data_[ct1*numComp+ct]);
        else if(type_ == ByKort)
            for(int ct = 0; ct < numNodes_*numComp; ct++) storageData[ct] = static_cast<StorageType>(data_[ct]);
        out.write((const char *)storageData, sizeof(StorageType)*numNodes_*numComp);
        delete [] storageData;
    }
    out.close();
    stepToProceed_++;
    return 0;
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::readFromFile(const char * name, int step, const char * extension, int numDigits, const char *catalog)
{
    name_ = name; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << name << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
    if(!in.good()) {
        report.error("Error while reading file \"", sstr.str(), "\"");
        return 1;
    }
    in.seekg(0, std::ios_base::end);
    size_t length = in.tellg();
    if(length != sizeof(StorageType)*numNodes_*numComp) {report.error("Error! Data in file \"", sstr.str().c_str(), "\" not corresponds to data type and nodes number", sstr.str()); return 2;}
    in.seekg(0, std::ios_base::beg);
    //TODO implement compile time comparison
    if(typeid(StorageType) == typeid(ArrayType)){
        if(type_ == ByNodes){
            ArrayType * storageData = new ArrayType [numNodes_*numComp];
            in.read((char *)storageData, sizeof(ArrayType)*numNodes_*numComp);
            for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = storageData[ct*numNodes_+ct1];
            delete [] storageData;
        }
        else if(type_ == ByKort)
            in.read((char *)data_, sizeof(ArrayType)*numNodes_*numComp);
    }
    else{
        StorageType * storageData = new StorageType [numNodes_*numComp];
        in.read((char *)storageData, sizeof(StorageType)*numNodes_*numComp);
        if(type_ == ByNodes)
            for(int ct = 0; ct < numComp; ct++) for(int ct1 = 0; ct1 < numNodes_; ct1++) data_[ct1*numComp+ct] = static_cast<ArrayType>(storageData[ct*numNodes_+ct1]);
        else if(type_ == ByKort)
            for(int ct = 0; ct < numNodes_*numComp; ct++) data_[ct] = static_cast<ArrayType>(storageData[ct]);
        delete [] storageData;
    }
    in.close();
    stepToProceed_++;
    return 0;
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::writeToFile()
{
    return writeToFile<StorageType>(name_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template < class ArrayType, int numComp>
template <class StorageType>
int NodesData<ArrayType, numComp>::readFromFile()
{
    return readFromFile<StorageType>(name_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template < class ArrayType, int numComp>
template <class StorageType, int numInOneFile>
int NodesData<ArrayType, numComp>::writeToFileSplited()
{
    NodesData<ArrayType, numInOneFile> tmp(name_+std::to_string(1), mesh_);
    tmp.setStep(step());
    for(int ct = 0;ct < numInOneFile; ct++)
        for(int ct1 = 0; ct1 < numNodes_; ct1++) tmp.data(ct1, ct) = data(ct1, ct);
    tmp.writeToFile();
    return 0;
}
template < class ArrayType, int numComp>
bool NodesData<ArrayType, numComp>::exist()
{
    bool exist = false;
    std::stringstream sstr;
    sstr << name_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
    std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
    if(in.good()) exist = true;
    in.close();
    return exist;
}

template<class ArrayType, int numComp>
bool NodesData<ArrayType, numComp>::exist(const char *name, int step, const char *extension, int numDigits, const char *catalog)
{
    std::string fName;
    if(catalog) fName += catalog + std::string("/");
    fName += name;
    NodesData<ArrayType, numComp> d(fName.c_str(), nullptr);
    d.setNumDigits(numDigits);
    d.setExtention(extension);
    d.setStep(step);
    return d.exist();
}
template < class ArrayType, int numComp>
int NodesData<ArrayType, numComp>::numExistedSteps()
{
    int numSteps = 0;
    NodesData<ArrayType, numComp> tmp(name_, numNodes_);
    tmp.setStep(step());
    while(tmp.exist()) {
        ++numSteps;
        tmp.setStep(step() + numSteps);
    }
    return numSteps;
}

template<class ArrayType, int numComp>
ArrayType NodesData<ArrayType, numComp>::max(int dof) const
{
    if(numNodes_ > 0) {
        ArrayType val = data(0, dof);
        for(int ct = 1; ct < numNodes_; ++ct)
            val = std::max(val, data(ct, dof));
        return val;
    }
    return std::numeric_limits<ArrayType>::quiet_NaN();
}

template<class ArrayType, int numComp>
ArrayType NodesData<ArrayType, numComp>::min(int dof) const
{
    if(numNodes_ > 0) {
        ArrayType val = data(0, dof);
        for(int ct = 1; ct < numNodes_; ++ct)
            val = std::min(val, data(ct, dof));
        return val;
    }
    return std::numeric_limits<ArrayType>::quiet_NaN();
}

#endif // SBFNODESDATA_H
