#include "sbfReporter.h"
#include "sbfMesh.h"
#include "sbfElement.h"
#include "sbfNode.h"
#include "sbfMeshBuilders.h"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

BOOST_AUTO_TEST_SUITE ( bricks )

BOOST_AUTO_TEST_CASE ( simple_loads )
{
    float xSide = 1;
    float ySide = 0.01;
    float zSide = 0.002;
    auto mesh = std::unique_ptr<sbfMesh>(
                sbfMeshBuilder::makeBlock(xSide, ySide, zSide,
                                          100, 100, 100,
                                          ElementType::HEXAHEDRON_LINEAR)
                );
    auto borders = mesh->computeBorderFaces(0.1f);
    BOOST_REQUIRE(borders.size() == 6);

}

BOOST_AUTO_TEST_SUITE_END()
