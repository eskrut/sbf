#ifndef SBFSOLUTIONBUNDLE_H
#define SBFSOLUTIONBUNDLE_H

template <class ArrayType, int numArrays> class SolutionBundle
{
public:
    SolutionBundle(std::string baseName, int numNodes);
    ~SolutionBundle();
private:
    NodesData<ArrayType, 1> * arrays_[numArrays];
    std::string names_[numArrays];
    std::string baseName_;
    std::string extension_;
    int numDigits_;
    int stepToProceed_;
    int numNodes_;
    void init();

public:
    NodesData<ArrayType, 1> * array(int index);
    std::string & name(int index);
    std::string & baseName();
    void setStep(int step);
    int step();
    void setNumDigits(int numDigits);
    void free();
    void free(int index);
    void allocate();
    void allocate(int index);
    template <class StorageType = DefaultStorageDataType> int writeToFile(const char * baseName, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int readFromFile(const char * baseName, int step, const char * extension = ".sba", int numDigits = 4, const char *catalog = nullptr);
    template <class StorageType = DefaultStorageDataType> int writeToFile();//Short forms
    template <class StorageType = DefaultStorageDataType> int readFromFile();
    int writeNames();
    int readNames(const char* catalog = nullptr);
    bool exist();//Check if file with current step exists
};
template <class ArrayType, int numArrays>
SolutionBundle<ArrayType, numArrays>::SolutionBundle(std::string baseName, int numNodes) : baseName_(baseName), extension_(".sba"), numDigits_(4), stepToProceed_(1), numNodes_(numNodes) { init(); }
template <class ArrayType, int numArrays>
SolutionBundle<ArrayType, numArrays>::~SolutionBundle() { free(); }

template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::init()
{
    names_[0]="Temperature";names_[1]="SigmaXX";names_[2]="SigmaYY";names_[3]="SigmaZZ";names_[4]="SigmaXY";names_[5]="SigmaYZ";names_[6]="SigmaXZ";names_[7]="SigmaI";names_[8]="EXX";names_[9]="EYY";
    names_[10]="EZZ";names_[11]="EXY";names_[12]="EYZ";names_[13]="EXZ";names_[14]="EI";names_[15]="EIPL";names_[16]="16";names_[17]="17";names_[18]="18";names_[19]="19";
    for(int ct = 0; ct < numArrays; ct++) arrays_[ct] = nullptr;
}
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::free() { for(int ct = 0; ct < numArrays; ct++) if(arrays_[ct]) {delete arrays_[ct]; arrays_[ct] = nullptr;} }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::free(int index) { if(arrays_[index]) {delete arrays_[index]; arrays_[index] = nullptr;} }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::allocate() { free(); for(int ct = 0; ct < numArrays; ct++)  arrays_[ct] = new NodesData<ArrayType, 1>(numNodes_); }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::allocate(int index) { free(index); arrays_[index] = new NodesData<ArrayType, 1>(numNodes_); }

template <class ArrayType, int numArrays>
NodesData<ArrayType, 1> * SolutionBundle<ArrayType, numArrays>::array(int index) { return arrays_[index]; }
template <class ArrayType, int numArrays>
std::string & SolutionBundle<ArrayType, numArrays>::name(int index) { return names_[index]; }
template <class ArrayType, int numArrays>
std::string & SolutionBundle<ArrayType, numArrays>::baseName() { return baseName_; }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::setStep(int step) { stepToProceed_ = step; }
template <class ArrayType, int numArrays>
int SolutionBundle<ArrayType, numArrays>::step() { return stepToProceed_; }
template <class ArrayType, int numArrays>
void SolutionBundle<ArrayType, numArrays>::setNumDigits(int numDigits) { numDigits_ = numDigits; }

template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::writeToFile(const char * baseName, int step, const char * extension, int numDigits, const char *catalog)
{
    baseName_ = baseName; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << baseName << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ofstream out(sstr.str().c_str(), std::ios_base::binary);
    if(!out.good()) {report.error("Error while opening file to write ", sstr.str()); return 1;}
    int flags[numArrays];
    for(int ct = 0; ct < numArrays; ct++) flags[ct] = arrays_[ct] ? 1 : 0;
    out.write((const char *)flags, sizeof(int)*numArrays);
    for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
        //TODO implement compile time comparison
        if(typeid(StorageType) == typeid(ArrayType))
            out.write((const char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
        else{
            StorageType * storageData = new StorageType [numNodes_];
            for(int ctNode = 0; ctNode < numNodes_; ctNode++) storageData[ctNode] = static_cast<StorageType>(arrays_[ct]->data()[ctNode]);
            out.write((const char *)storageData, sizeof(StorageType)*numNodes_);
            delete [] storageData;
        }
    }
    out.close();
    stepToProceed_++;
    return 0;
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::readFromFile(const char * baseName, int step, const char * extension, int numDigits, const char *catalog)
{
    free();
    baseName_ = baseName; stepToProceed_ = step; numDigits_ = numDigits; extension_ = extension;
    std::stringstream sstr;
    if (catalog) sstr << catalog << "/";
    sstr << baseName << std::setw(numDigits) << std::setfill('0') << step << extension;
    std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
    if(!in.good()) {report.error("Error while reading file ", sstr.str()); return 1;}
    int flags[numArrays];
    in.read((char *)flags, sizeof(int)*numArrays);
    int numValidArrays = 0;
    for(int ct = 0; ct < numArrays; ++ct) if(flags[ct]) ++numValidArrays;
    in.seekg(0, std::ios_base::end);
    size_t length = in.tellg();
    if(length != sizeof(int)*numArrays + sizeof(StorageType)*numNodes_*numValidArrays) {
        report.error("Error! Data in file \"", sstr.str().c_str(), "\" not corresponds to data type, nodes number or array number", sstr.str());
        return 2;
    }
    in.seekg(0, std::ios_base::beg);
    in.read((char *)flags, sizeof(int)*numArrays);
    for(int ct = 0; ct < numArrays; ct++) if(flags[ct]) allocate(ct);
    for(int ct = 0; ct < numArrays; ct++) if(flags[ct]){
        //TODO implement compile time comparison
        if(typeid(StorageType) == typeid(ArrayType))
            in.read((char *)arrays_[ct]->data(), sizeof(ArrayType)*numNodes_);
        else{
            StorageType * storageData = new StorageType [numNodes_];
            in.read((char *)storageData, sizeof(StorageType)*numNodes_);
            for(int ctNode = 0; ctNode < numNodes_; ctNode++) arrays_[ct]->data()[ctNode] = static_cast<ArrayType>(storageData[ctNode]);
            delete [] storageData;
        }
    }
    in.close();
    if( stepToProceed_ == 1 )
        readNames(catalog);
    stepToProceed_++;
    return 0;
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::writeToFile()
{
    return writeToFile<StorageType>(baseName_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template <class ArrayType, int numArrays>
template <class StorageType>
int SolutionBundle<ArrayType, numArrays>::readFromFile()
{
    return readFromFile<StorageType>(baseName_.c_str(), stepToProceed_, extension_.c_str(), numDigits_);
}
template <class ArrayType, int numArrays>
bool SolutionBundle<ArrayType, numArrays>::exist()
{
    bool exist = false;
    std::stringstream sstr;
    sstr << baseName_ << std::setw(numDigits_) << std::setfill('0') << stepToProceed_ << extension_;
    std::ifstream in(sstr.str().c_str(), std::ios_base::binary);
    if(in.good()) exist = true;
    in.close();
    return exist;
}
template <class ArrayType, int numArrays>
int SolutionBundle<ArrayType, numArrays>::readNames(const char *catalog)
{
    std::stringstream sstr;
    if(catalog) sstr << catalog << "/";
    sstr << baseName_ << "_Names" << extension_;
    std::ifstream in(sstr.str().c_str());
    if(!in.good()){report("Cant read names file", sstr.str()); return 1;}
    for(int ct = 0; ct < numArrays; ct++){
        if(in.eof()){return 2;}
        in >> names_[ct];
    }
    in.close();
    return 0;
}
template <class ArrayType, int numArrays>
int SolutionBundle<ArrayType, numArrays>::writeNames()
{
    std::stringstream sstr;
    sstr << baseName_ << "_Names" << extension_;
    std::ofstream out(sstr.str().c_str());
    if(!out.good()){return 1;}
    for(int ct = 0; ct < numArrays; ct++)
        out << names_[ct];
    out.close();
    return 0;
}

#endif // SBFSOLUTIONBUNDLE_H
