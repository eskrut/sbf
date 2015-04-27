#include "sbfStiffMatrixBand.h"
#include "sbfStiffMatrixBandIterator.h"
#include "sbfPropertiesSet.h"
#include "sbfGroupFilter.h"
#include "sbfNodeGroup.h"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

BOOST_AUTO_TEST_SUITE ( sbfStiffMatrixBandTest )

BOOST_AUTO_TEST_CASE ( cholParallel )
{
    std::unique_ptr<sbfMesh> m_up ( sbfMesh::makeBlock ( 1.0, 1.0, 1.0, 1, 1, 1, ElementType::HEXAHEDRON_LINEAR ) );
    sbfMesh *m = m_up.get();
    std::unique_ptr<sbfPropertiesSet> pSet_up ( std::make_unique<sbfPropertiesSet>() );
    pSet_up->addMaterial ( sbfMaterialProperties::makeMPropertiesSteel() );
    std::unique_ptr<sbfStiffMatrixBand<3>> stiff_up ( std::make_unique<sbfStiffMatrixBand<3>> (
                                                          m, pSet_up.get(),
                                                          MatrixType::FULL_MATRIX ) );
    sbfStiffMatrixBand<3> *stiff = stiff_up.get();

    stiff->computeSequantially();

    NodesData<double, 3> displ("displ", m), force("force", m);
    displ.null(); force.null();

    stiff->lockDof(0, 0, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(0, 1, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(0, 2, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(1, 0, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(1, 1, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(1, 2, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(2, 0, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(2, 1, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    stiff->lockDof(2, 2, 0, force.data(), LockType::EXACT_LOCK_TYPE);

//    std::vector<std::vector<double>> data;
//    data.resize(8*3);
//    for(auto &d : data) d.resize(8*3);
//    std::unique_ptr<sbfMatrixIterator> iter_up(stiff->createIterator());
//    sbfMatrixIterator *iter = iter_up.get();
//    for(int ctRow = 0; ctRow < m->numNodes(); ++ctRow) {
//        iter->setToRow(ctRow);
//        while(iter->isValid()) {
//            int col = iter->column();
//            for(int ct1 = 0; ct1 < 3; ++ct1) for(int ct2 = 0; ct2 < 3; ++ct2)
//                data[ctRow*3+ct1][col*3+ct2] = iter->data()[ct1*3 + ct2];
//            iter->next();
//        }
//    }
//    auto c = report.delemeter();
//    report.setDelemeter(' ');
//    report("[");
//    for(auto &d : data) {
//        std::string str;
//        for(auto &sub : d) {
//            str += std::to_string(sub);
//            if(&sub != &d.back()) str += ", ";
//        }
//        report("[", str, "]");
//        if(&d != &data.back()) report(",");
//    }
//    report("]");
//    report.setDelemeter(c);

    std::unique_ptr<sbfStiffMatrix> chol_up(stiff->createChol());
    sbfStiffMatrix *chol = chol_up.get();
}

BOOST_AUTO_TEST_CASE ( simpleBrickLoad )
{
    std::unique_ptr<sbfMesh> m_up ( sbfMesh::makeBlock ( 100.0, 5.0, 1.0, 200, 10, 2, ElementType::HEXAHEDRON_LINEAR ) );
    sbfMesh *m = m_up.get();

    NodesData<double, 3> displ("displ", m), force("force", m);
    displ.null(); force.null();

    std::unique_ptr<sbfPropertiesSet> pSet_up ( std::make_unique<sbfPropertiesSet>() );
    pSet_up->addMaterial ( sbfMaterialProperties::makeMPropertiesSteel() );

    std::unique_ptr<sbfStiffMatrixBand<3>> stiff_up ( std::make_unique<sbfStiffMatrixBand<3>> (
                                                          m, pSet_up.get(),
                                                          MatrixType::FULL_MATRIX ) );
    sbfStiffMatrixBand<3> *stiff = stiff_up.get();

    stiff->computeSequantially();

    sbfGroupFilter lockFilt;
    lockFilt.setCrdXF(-0.001, 0.001);
    auto lockGroup = m->addNodeGroup();
    lockGroup->addFilter(lockFilt);
    m->processNodeGroups();

    for(auto id : lockGroup->nodeIndList())
        stiff->lockDof(id, 0, 0, force.data(), LockType::EXACT_LOCK_TYPE);
    lockFilt.setCrdYF(-0.001, 0.001);
    lockFilt.setCrdZF(-0.001, 0.001);
    lockGroup->clearFilters();
    lockGroup->addFilter(lockFilt);
    m->processNodeGroups();
    BOOST_REQUIRE(lockGroup->nodeIndList().size() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
