#include "sbfSElement.h"
#include "sbfSELevelList.h"
#include "sbfSELevel.h"
#include "sbfMesh.h"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

BOOST_AUTO_TEST_SUITE ( sbfSElementTest )

BOOST_AUTO_TEST_CASE ( dummy )
{
    std::unique_ptr<sbfMesh> m_up ( sbfMesh::makeBlock ( 1.0, 1.0, 1.0, 2, 1, 1, ElementType::HEXAHEDRON_LINEAR ) );
    sbfMesh *m = m_up.get();

    std::unique_ptr<sbfSELevelList> levelList_up ( std::make_unique<sbfSELevelList>() );
    sbfSELevelList *levelList = levelList_up.get();
    levelList->setMesh(m);

    sbfSELevel lev;
    lev.setMesh(m); lev.setSize(m->numElements()); lev.setLevelIndex(0);
    lev.setIndex(0, 0); lev.setIndex(1, 1);

    levelList->addLevel(lev);

    auto selevels = levelList->selevels();

    sbfSElement::update(selevels.back().begin(), selevels.back().end());

    BOOST_REQUIRE(selevels.size() == 1);
    BOOST_REQUIRE(selevels.front().size() == 2);
    BOOST_REQUIRE(selevels.front().front()->numInnerNodes() == 4);
    BOOST_REQUIRE(selevels.front().front()->numOuterNodes() == 4);
}

BOOST_AUTO_TEST_SUITE_END()
