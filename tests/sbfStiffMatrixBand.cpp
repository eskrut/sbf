#include "sbfStiffMatrixBand.h"
#include "sbfStiffMatrixBandIterator.h"
#include "sbfPropertiesSet.h"
#include "sbfMaterialProperties.h"
#include "sbfGroupFilter.h"
#include "sbfNodeGroup.h"
#include "sbfElement.h"
#include "sbfMeshBuilders.h"
#include "sbfAdditions.h"
#include <vector>
#include <initializer_list>
#include <cmath>

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
    std::unique_ptr<sbfMesh> m_up ( sbfMeshBuilder::makeBlock ( 100.0, 5.0, 1.0, 20, 10, 2, ElementType::HEXAHEDRON_LINEAR ) );
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

    stiff->compute(false);

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

BOOST_AUTO_TEST_CASE( simpleBeam )
{
    const float L = 1.0;
    const size_t numNodes = 10000;
    auto mesh = std::make_unique<sbfMesh>();
    int prevNode = mesh->addNode(0, 0, 0);
    for(size_t ct = 1; ct < numNodes; ++ct) {
        int nextNode = mesh->addNode(L / (numNodes - 1) * ct, 0, 0, false);
        mesh->addElement(sbfElement(ElementType::BEAM_LINEAR_6DOF, {prevNode, nextNode}));
        prevNode = nextNode;
    }
    mesh->setMtr(1);
    BOOST_REQUIRE( mesh->numNodes() == numNodes );
    BOOST_REQUIRE( mesh->numElements() == (numNodes-1) );

    //mesh->rotate(0, std::atan(1)*2, 0);

    //FIXME
    //Smart pointer couses crash mat deleted at props destruction
    auto mat = new sbfMaterialProperties();
    auto props = std::make_unique<sbfPropertiesSet>();
    mat->addTable("elastic module", 0, 1);
    mat->addTable("shear module", 0, 1);
    mat->addTable("area", 0, 1);
    mat->addTable("Ix", 0, 1);
    mat->addTable("Iy", 0, 1);
    mat->addTable("Iz", 0, 1);
    props->addMaterial(mat);


    NodesData<double, 6> d(mesh.get()), f(mesh.get());

    {
        //Test for stretching
        auto stif = std::make_unique<sbfStiffMatrixBand<6>>(mesh.get(), props.get());
        stif->compute(false);
        f.null();
        f.data(numNodes-1, 0) = 1;
        for(auto dof : {0, 1, 2, 3, 4, 5})
            stif->lockDof(0, dof, 0, f.data(), LockType::EXACT_LOCK_TYPE);

        auto chol = reinterpret_cast<sbfStiffMatrixBand<6> *>(stif->createChol(false));
        assert(chol->isValid());
        chol->solve_L_LT_u_eq_f(d.data(), f.data());

        for(auto ct : std::list<int>({0, numNodes-1}))
//        for(auto ct = 0; ct < numNodes; ++ct)
            report(d.data(ct, 0), d.data(ct, 1), d.data(ct, 2), d.data(ct, 3), d.data(ct, 4), d.data(ct, 5));
    }

    {
        //Test for bending by force
        auto stif = std::make_unique<sbfStiffMatrixBand<6>>(mesh.get(), props.get());
        stif->compute(false);
        f.null();
        f.data(numNodes-1, 1) = 3;
        for(auto dof : {0, 1, 2, 3, 4, 5})
            stif->lockDof(0, dof, 0, f.data(), LockType::EXACT_LOCK_TYPE);

        auto chol = reinterpret_cast<sbfStiffMatrixBand<6> *>(stif->createChol(false));
        assert(chol->isValid());
        chol->solve_L_LT_u_eq_f(d.data(), f.data());

        for(auto ct : std::list<int>({0, numNodes-1}))
            report(d.data(ct, 0), d.data(ct, 1), d.data(ct, 2), d.data(ct, 3), d.data(ct, 4), d.data(ct, 5));
    }

    {
        //Test for bending by moment
        auto stif = std::make_unique<sbfStiffMatrixBand<6>>(mesh.get(), props.get());
        stif->compute(false);
        f.null();
        f.data(numNodes-1, 5) = 2;
        for(auto dof : {0, 1, 2, 3, 4, 5})
            stif->lockDof(0, dof, 0, f.data(), LockType::EXACT_LOCK_TYPE);

        auto chol = reinterpret_cast<sbfStiffMatrixBand<6> *>(stif->createChol(false));
        assert(chol->isValid());
        chol->solve_L_LT_u_eq_f(d.data(), f.data());

        for(auto ct : std::list<int>({0, numNodes-1}))
            report(d.data(ct, 0), d.data(ct, 1), d.data(ct, 2), d.data(ct, 3), d.data(ct, 4), d.data(ct, 5));
    }

    {
        //Test for rotating by moment
        auto stif = std::make_unique<sbfStiffMatrixBand<6>>(mesh.get(), props.get());
        stif->compute(false);
        f.null();
        f.data(numNodes-1, 3) = 1;
        for(auto dof : {0, 1, 2, 3, 4, 5})
            stif->lockDof(0, dof, 0, f.data(), LockType::EXACT_LOCK_TYPE);

        auto chol = reinterpret_cast<sbfStiffMatrixBand<6> *>(stif->createChol(false));
        assert(chol->isValid());
        chol->solve_L_LT_u_eq_f(d.data(), f.data());

        for(auto ct : std::list<int>({0, numNodes-1}))
            report(d.data(ct, 0), d.data(ct, 1), d.data(ct, 2), d.data(ct, 3), d.data(ct, 4), d.data(ct, 5));
    }
}

BOOST_AUTO_TEST_SUITE_END()
