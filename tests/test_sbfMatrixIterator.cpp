#include "test_sbfMatrixIterator.h"
#include "sbfStiffMatrixBlock3x3Iterator.h"
#include "sbfStiffMatrixBlock6x6Iterator.h"
#include "sbfStiffMatrixBand6Iterator.h"
#include "sbfAdditions.h"
#include "sbfElement.h"
#include <memory>
#include <initializer_list>

//void TestMatrixIterator::case01_block3x3()
//{
//    //Initialize stiff matrix
//    std::unique_ptr<sbfStiffMatrixBlock3x3> stiff(new sbfStiffMatrixBlock3x3);
//    std::unique_ptr<sbfStiffMatrixBlock3x3Iterator> iterator;
//    //Filling pattern
////    [1 1 0 1]
////    [1 1 0 0]
////    [0 0 1 1]
////    [1 0 1 1]
//    std::vector<int> indJ, shiftJ, indJAlter, shiftJAlter;
//    auto fillFun = [=](double * dataPtr, double val){
//        for(int ct = 0; ct < 9; ct++) dataPtr[ct] = val;
//    };

//    //Full matrix
//    //Filling pattern
////    [1 2 0 3 ]
////    [2 4 0 0 ]
////    [0 0 5 6 ]
////    [3 0 6 7 ]
//    indJ.clear(); shiftJ.clear(); indJAlter.clear(); shiftJAlter.clear();
//    stiff->setType(FULL_MATRIX);
//    shiftJ.push_back(0);
//    indJ.insert(indJ.end(), {0, 1, 3});
//    shiftJ.push_back(indJ.size());
//    indJ.insert(indJ.end(), {0, 1});
//    shiftJ.push_back(indJ.size());
//    indJ.insert(indJ.end(), {2, 3});
//    shiftJ.push_back(indJ.size());
//    indJ.insert(indJ.end(), {0, 2, 3});
//    shiftJ.push_back(indJ.size());
//    stiff->setIndData(4, indJ.size(), indJ.data(), shiftJ.data());
//    fillFun(stiff->data(0, 0), 1);
//    fillFun(stiff->data(0, 1), 2);
//    fillFun(stiff->data(0, 3), 3);
//    fillFun(stiff->data(1, 0), 2);
//    fillFun(stiff->data(1, 1), 4);
//    fillFun(stiff->data(2, 2), 4);
//    fillFun(stiff->data(2, 3), 6);
//    fillFun(stiff->data(3, 0), 3);
//    fillFun(stiff->data(3, 2), 6);
//    fillFun(stiff->data(3, 3), 7);

//    iterator.reset(stiff->createIterator());
//    iterator->setToRow(0);
//    QVERIFY2(iterator->data() == stiff->data(), "Failed to initialize row");
//    QVERIFY2(iterator->column() == 0, "Failed to initialize row");
//    QVERIFY2(*iterator->data() == 1, "Failed to get right value");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*1, "Failed to compute address");
//    QVERIFY2(*iterator->data() == 2, "Failed to get right value");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*2, "Failed to compute address");
//    QVERIFY2(*iterator->data() == 3, "Failed to get right value");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

//    iterator->setToRow(2);
//    QVERIFY2(iterator->isDiagonal() == true, "Failed to interpret diagonal");
//    QVERIFY2(iterator->diagonal(2) == stiff->data()+9*5, "Failed to compute address");
//    QVERIFY2(iterator->data() == stiff->data()+9*5, "Failed to compute address");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->column() == 3, "Failed to evaluate column index");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");

//    iterator->setToColumn(1);
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*3, "Failed to initialize row");
//    QVERIFY2(iterator->row() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->row() == 1, "Failed to evaluate column index");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

//    iterator->setToRowInverse(0);
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*2, "Failed to initialize row");
//    QVERIFY2(iterator->column() == 3, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->column() == 1, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*1, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*0, "Failed to initialize row");
//    QVERIFY2(iterator->column() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == false, "Failed to switch to the next existing block");

//    iterator->setToColumnInverse(3);
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*9, "Failed to initialize row");
//    QVERIFY2(iterator->row() == 3, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->isDiagonal() == true, "Failed to interpret diagonal");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->row() == 2, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*8, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*7, "Failed to initialize row");
//    QVERIFY2(iterator->row() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

//    iterator->setToColumnInverse(0);
//    QVERIFY2(*iterator->data() == 3, "Failed to get right value");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(*iterator->data() == 2, "Failed to get right value");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(*iterator->data() == 1, "Failed to get right value");
//    QVERIFY2(iterator->isDiagonal() == true, "Failed to interpret diagonal");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");
//    //Full matrix
//    //Filling pattern
////    [1 2 0 3 ]
////    [2 4 0 0 ]
////    [0 0 5 6 ]
////    [3 0 6 7 ]

//    //Down treangle matrix
//    //Filling pattern
////    [1 2 0 5 ]
////    [2 3 0 0 ]
////    [0 0 4 6 ]
////    [5 0 6 7 ]
//    indJ.clear(); shiftJ.clear(); indJAlter.clear(); shiftJAlter.clear();
//    stiff->setType(DOWN_TREANGLE_MATRIX);
//    shiftJ.push_back(0);
//    shiftJAlter.push_back(0);
//    indJ.insert(indJ.end(), std::initializer_list<int>{0});
//    indJAlter.insert(indJAlter.end(), {1, 3});
//    shiftJ.push_back(indJ.size());
//    shiftJAlter.push_back(indJAlter.size());
//    indJ.insert(indJ.end(), {0, 1});
//    indJAlter.insert(indJAlter.end(), {});
//    shiftJ.push_back(indJ.size());
//    shiftJAlter.push_back(indJAlter.size());
//    indJ.insert(indJ.end(), std::initializer_list<int>{2});
//    indJAlter.insert(indJAlter.end(), std::initializer_list<int>{3});
//    shiftJ.push_back(indJ.size());
//    shiftJAlter.push_back(indJAlter.size());
//    indJ.insert(indJ.end(), {0, 2, 3});
//    indJAlter.insert(indJAlter.end(), {});
//    shiftJ.push_back(indJ.size());
//    shiftJAlter.push_back(indJAlter.size());
//    stiff->setIndData(4, indJ.size(), indJ.data(), shiftJ.data(), indJAlter.size(), indJAlter.data(), shiftJAlter.data());
//    fillFun(stiff->data(0, 0), 1);
//    fillFun(stiff->data(1, 0), 2);
//    fillFun(stiff->data(1, 1), 3);
//    fillFun(stiff->data(2, 2), 4);
//    fillFun(stiff->data(3, 0), 5);
//    fillFun(stiff->data(3, 2), 6);
//    fillFun(stiff->data(3, 3), 7);

//    iterator.reset(stiff->createIterator());
//    iterator->setToRow(0);
//    QVERIFY2(iterator->data() == stiff->data(), "Failed to initialize row");
//    QVERIFY2(iterator->column() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->data() == stiff->data()+9*1, "Failed to compute address");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->column() == 3, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*4, "Failed to compute address");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

//    iterator->setToRow(2);
//    QVERIFY2(iterator->isDiagonal() == true, "Failed to interpret diagonal");
//    QVERIFY2(iterator->data() == stiff->data()+9*3, "Failed to compute address");
//    QVERIFY2(iterator->diagonal(2) == stiff->data()+9*3, "Failed to compute address");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->column() == 3, "Failed to evaluate column index");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->data() == stiff->data()+9*5, "Failed to compute address");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");

//    iterator->setToColumn(2);
//    QVERIFY2(iterator->data() == stiff->data()+9*3, "Failed to initialize row");
//    QVERIFY2(iterator->row() == 2, "Failed to initialize row");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->row() == 3, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*5, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

//    iterator->setToRowInverse(0);
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*4, "Failed to initialize row");
//    QVERIFY2(iterator->column() == 3, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->column() == 1, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*1, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*0, "Failed to initialize row");
//    QVERIFY2(iterator->column() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == false, "Failed to switch to the next existing block");

//    iterator->setToRowInverse(3);
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*6, "Failed to initialize row");
//    QVERIFY2(iterator->column() == 3, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->column() == 2, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*5, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*4, "Failed to initialize row");
//    QVERIFY2(iterator->column() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == false, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == false, "Failed to switch to the next existing block");

//    iterator->setToColumnInverse(0);
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*4, "Failed to initialize row");
//    QVERIFY2(*iterator->data() == 5, "Failed to get right value");
//    QVERIFY2(iterator->row() == 3, "Failed to initialize row");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
//    QVERIFY2(iterator->row() == 1, "Failed to evaluate column index");
//    QVERIFY2(iterator->data() == stiff->data()+9*1, "Failed to initialize row");
//    QVERIFY2(*iterator->data() == 2, "Failed to get right value");
//    QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
//    QVERIFY2(iterator->haveNext() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->next() == true, "Failed to tell 'no more blocks'");
//    QVERIFY2(iterator->data() == stiff->data()+9*0, "Failed to initialize row");
//    QVERIFY2(*iterator->data() == 1, "Failed to get right value");
//    QVERIFY2(iterator->row() == 0, "Failed to initialize row");
//    QVERIFY2(iterator->isDiagonal() == true, "Failed to tell diagonal");
//    QVERIFY2(iterator->diagonal(0) == stiff->data()+9*0, "Failed to initialize row");
//    QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

//    //Down treangle matrix
//    //Filling pattern
////    [1 2 0 5 ]
////    [2 3 0 0 ]
////    [0 0 4 6 ]
////    [5 0 6 7 ]
//}


void TestMatrixIterator::case01_band6()
{
    CreateSmartAndRawPtr(sbfMesh, new sbfMesh, mesh);
    mesh->addNode(0, 0, 0);
    mesh->addNode(1, 1, 1);
    mesh->addNode(2, 2, 2);
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 1}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {1, 2}));
    mesh->applyToAllElements([](sbfElement &elem){elem.setMtr(1);});
    const int blockSize = 36;

    {
        CreateSmartAndRawPtr(sbfStiffMatrixBand6, new sbfStiffMatrixBand6(mesh, nullptr), stiff);

        QVERIFY2(stiff->storeType() == MatrixStoreType::FULL, "Fail to get full store type");

        CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);

        iterator->setToRow(0);
        QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*0, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*1, "Failed to initialize row");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        QVERIFY2(iterator->diagonal(1) == stiff->data()+blockSize*3, "Failed to initialize row");

        iterator->setToRow(1);
        QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*2, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*3, "Failed to initialize row");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*4, "Failed to initialize row");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToColumn(0);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*0, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*1, "Failed to initialize row");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToRowInverse(1);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*4, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*3, "Failed to initialize row");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*2, "Failed to initialize row");
        QVERIFY2(iterator->haveNext() == false, "Failed to tell 'there are more blocks'");

        iterator->setToColumnInverse(2);
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->row() == 2, "Failed to evaluate column index");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*6, "Failed to initialize row");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*5, "Failed to initialize row");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");
    }
    {
        CreateSmartAndRawPtr(sbfStiffMatrixBand6, new sbfStiffMatrixBand6(mesh, nullptr, MatrixType::DOWN_TREANGLE_MATRIX), stiff);

        QVERIFY2(stiff->storeType() == MatrixStoreType::FULL, "Fail to get full store type");

        CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);

        iterator->setToRow(0);
        QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*0, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*1, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        QVERIFY2(iterator->diagonal(1) == stiff->data()+blockSize*2, "Failed to initialize row");

        iterator->setToRow(1);
        QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*1, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*2, "Failed to initialize row");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*3, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToColumn(0);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*0, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*1, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToRowInverse(1);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*3, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->haveNext() == true, "Failed to tell 'there are more blocks'");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*2, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*1, "Failed to initialize row");
        QVERIFY2(iterator->haveNext() == false, "Failed to tell 'there are more blocks'");

        iterator->setToColumnInverse(2);
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->row() == 2, "Failed to evaluate column index");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*4, "Failed to initialize row");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*3, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");
    }
}

void TestMatrixIterator::case02_band6_advanced()
{
    CreateSmartAndRawPtr(sbfMesh, new sbfMesh, mesh);
    mesh->addNode(0, 0, 0);
    mesh->addNode(1, 1, 0);
    mesh->addNode(0, 2, 0);
    mesh->addNode(-1, 1, 0);
    mesh->addNode(-1, -1, 0);
    mesh->addNode(0, -2, 0);
    mesh->addNode(1, -1, 0);
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 1}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 2}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 3}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 4}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 5}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {0, 6}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {1, 2}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {2, 3}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {3, 4}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {4, 5}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {5, 6}));
    mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {6, 1}));
    mesh->setMtr(1);
    const int blockSize = 36;

    {
        CreateSmartAndRawPtr(sbfStiffMatrixBand6, new sbfStiffMatrixBand6(mesh, nullptr), stiff);

        QVERIFY2(stiff->storeType() == MatrixStoreType::FULL, "Fail to get full store type");

        CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);

        /*
         *  0   1   2   3   4   5   6
         *  7   8   9   10  11  12  13
         *  14  15  16  17
         *  18  19  20  21  22
         *  23  24  25  26  27  28
         *  29  30  31  32  33  34  35
         *  36  37  38  39  40  41  42
         */
        iterator->setToRow(3);
        QVERIFY2(iterator->column() == 0, "Failed to evaluate column index");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*18, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->column() == 1, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*22, "Failed to initialize row");
        QVERIFY2(iterator->column() == 4, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToColumn(4);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*4, "Failed to initialize row");
        QVERIFY2(iterator->row() == 0, "Failed to evaluate column index");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*40, "Failed to initialize row");
        QVERIFY2(iterator->row() == 6, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToColumnInverse(6);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*42, "Failed to initialize row");
        QVERIFY2(iterator->row() == 6, "Failed to evaluate column index");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->row() == 5, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->row() == 1, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*6, "Failed to initialize row");
        QVERIFY2(iterator->row() == 0, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        QVERIFY2(iterator->diagonal(0) == stiff->data()+blockSize*0, "Failed to get diagonal");
        QVERIFY2(iterator->diagonal(4) == stiff->data()+blockSize*27, "Failed to get diagonal");
        QVERIFY2(iterator->diagonal(6) == stiff->data()+blockSize*42, "Failed to get diagonal");

    }

    {
        CreateSmartAndRawPtr(sbfStiffMatrixBand6, new sbfStiffMatrixBand6(mesh, nullptr, MatrixType::DOWN_TREANGLE_MATRIX), stiff);

        QVERIFY2(stiff->storeType() == MatrixStoreType::FULL, "Fail to get full store type");

        CreateSmartAndRawPtr(sbfMatrixIterator, stiff->createIterator(), iterator);

        /*
         *  0   1   3   6   10  15  21
         *  1   2   4   7   11  16  22
         *  3   4   5   8
         *  6   7   8   9   13
         *  10  11  12  13  14  19
         *  15  16  17  18  19  20  26
         *  21  22  23  24  25  26  27
         */
        iterator->setToRow(3);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*6, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*13, "Failed to initialize row");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToColumn(4);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*10, "Failed to initialize row");
        QVERIFY2(iterator->row() == 0, "Failed to evaluate column index");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->row() == 3, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->row() == 4, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*19, "Failed to initialize row");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*25, "Failed to initialize row");
        QVERIFY2(iterator->row() == 6, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        iterator->setToColumnInverse(6);
        QVERIFY2(iterator->data() == stiff->data()+blockSize*27, "Failed to initialize row");
        QVERIFY2(iterator->row() == 6, "Failed to evaluate column index");
        QVERIFY2(iterator->isInNormal() == true, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*26, "Failed to initialize row");
        QVERIFY2(iterator->row() == 5, "Failed to evaluate column index");
        QVERIFY2(iterator->isInNormal() == false, "Failed to evaluate normal/alter");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->row() == 1, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == true, "Failed to switch to the next existing block");
        QVERIFY2(iterator->data() == stiff->data()+blockSize*21, "Failed to initialize row");
        QVERIFY2(iterator->row() == 0, "Failed to evaluate column index");
        QVERIFY2(iterator->next() == false, "Failed to tell 'no more blocks'");

        QVERIFY2(iterator->diagonal(0) == stiff->data()+blockSize*0, "Failed to get diagonal");
        QVERIFY2(iterator->diagonal(4) == stiff->data()+blockSize*14, "Failed to get diagonal");
        QVERIFY2(iterator->diagonal(6) == stiff->data()+blockSize*27, "Failed to get diagonal");
    }
}
