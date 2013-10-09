#include "test_sbfAdditions.h"
#include "test_sbfNode.h"

int main() {
    QList<QObject*> testObjects;

    testObjects << new TestSbfAdditions();
    testObjects << new TestSbfNode();

    int status = 0;
    for ( auto obj : testObjects )
        status |= QTest::qExec(obj);
    return status;
}
