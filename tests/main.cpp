#include "test_sbfAdditions.h"
#include "test_sbfNode.h"
#include "test_sbfElement.h"
#include "test_sbfMesh.h"
#include "test_stiffMatrices.h"
#include "test_sbfWorker.h"

#include <cstdio>

int main() {
    QList<QObject*> testObjects;

    testObjects << new TestSbfAdditions();
    testObjects << new TestSbfNode();
    testObjects << new TestSbfElement();
    testObjects << new TestSbfMesh();
    testObjects << new TestStiffMatrices();
    testObjects << new TestSbfWorker();

    int status = 0;
    for ( auto obj : testObjects )
        status |= QTest::qExec(obj);
    if ( status != 0 )
        std::cout << "Some test failed" << std::endl;
    else
        std::cout << "All tests passed :)" << std::endl;
    return status;
}
