#include "sbfStiffMatrixBand.h"
#include "sbfStiffMatrixBandIterator.h"
#include "sbfPropertiesSet.h"
#include "sbfGroupFilter.h"
#include "sbfNodeGroup.h"
#include <vector>
#include <initializer_list>

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

BOOST_AUTO_TEST_SUITE ( sbfStiffMatrixBandTest )

BOOST_AUTO_TEST_CASE ( construct )
{
    sbfStiffMatrixBandConstructData<6> constrData;
    std::vector<size_t> indJ ( {0, 6, 2, 6, 5, 6, 0, 0} );
    std::vector<size_t> shiftInd ( {0, 7, 12, 14, 14, 14} );
    int numNodes = 4;
    int numBlocks = 14;
    std::vector<double> data;
    data.resize ( constrData.blockSize * numBlocks, 0 );
    constrData.indJ = indJ.data();
    constrData.shiftInd = shiftInd.data();
    constrData.indJAlter = nullptr;
    constrData.shiftIndAlter = nullptr;
    constrData.numBlocks = numBlocks;
    constrData.numNodes = numNodes;
    constrData.numBlocksAlter = 0;
    constrData.type = MatrixType::FULL_MATRIX;
    constrData.data = data.data();
    constrData.ptrDataAlter = nullptr;

    //Do not delete this object - internal memory will be freed by vectors
    sbfStiffMatrixBand<6> *st = new sbfStiffMatrixBand<6> ( &constrData );
    auto it = st->createIterator();

    it->setToRow ( 0 );
    BOOST_REQUIRE ( it->column() == 0 );
    BOOST_REQUIRE ( it->next ( 6 ) );
    BOOST_REQUIRE ( it->column() == 6 );
    BOOST_REQUIRE ( ! it->next() );

    it->setToRow ( 3 );
    BOOST_REQUIRE ( ! it->isValid() );
}

BOOST_AUTO_TEST_CASE ( simpleBrickLoad )
{
    std::unique_ptr<sbfMesh> m_up ( sbfMesh::makeBlock ( 100.0, 5.0, 1.0, 20, 10, 2, ElementType::HEXAHEDRON_LINEAR ) );
    sbfMesh *m = m_up.get();

    NodesData<double, 3> displ ( "displ", m ), force ( "force", m );
    displ.null();
    force.null();

    std::unique_ptr<sbfPropertiesSet> pSet_up ( std::make_unique<sbfPropertiesSet>() );
    pSet_up->addMaterial ( sbfMaterialProperties::makeMPropertiesSteel() );

    std::unique_ptr<sbfStiffMatrixBand<3>> stiff_up ( std::make_unique<sbfStiffMatrixBand<3>> (
                                                          m, pSet_up.get(),
                                                          MatrixType::FULL_MATRIX ) );
    sbfStiffMatrixBand<3> *stiff = stiff_up.get();

    stiff->compute();

    sbfGroupFilter lockFilt;
    lockFilt.setCrdXF ( -0.001, 0.001 );
    auto lockGroup = m->addNodeGroup();
    lockGroup->addFilter ( lockFilt );
    m->processNodeGroups();

    for ( auto id : lockGroup->nodeIndList() )
        stiff->lockDof ( id, 0, 0, force.data(), LockType::EXACT_LOCK_TYPE );
    lockFilt.setCrdYF ( -0.001, 0.001 );
    lockFilt.setCrdZF ( -0.001, 0.001 );
    lockGroup->clearFilters();
    lockGroup->addFilter ( lockFilt );
    m->processNodeGroups();
    BOOST_REQUIRE ( lockGroup->nodeIndList().size() == 1 );
}

BOOST_AUTO_TEST_SUITE_END()
