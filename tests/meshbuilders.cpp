
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

#include "geom/sbfgeom2dline.h"
#include "geom/sbfgeom2darc.h"
#include "geom/sbfgeom2dface.h"

#include "sbfMesh.h"
#include "sbfMeshBuilders.h"

BOOST_AUTO_TEST_SUITE ( sbfMeshBuilders )

BOOST_AUTO_TEST_CASE ( baseEdges ) {

    auto l0 = sbfGeom2DLine(sbfNode(0, 0, 0), sbfNode(1, 1, 0));

    BOOST_REQUIRE(l0.end().distance(l0.begin()) == l0.length());

    auto nm = l0.nodeAtPortion(0.5);
    auto nt = sbfNode(0.5, 0.5, 0);
    BOOST_REQUIRE(nm.isSame(nt));

    auto a0 = sbfGeom2DArc(sbfNode(0, 0, 0), 2, -90.0_deg, 180.0_deg);

    BOOST_REQUIRE_CLOSE(a0.length(), 2*std::atan(1)*4, 1e-4);
    nm = a0.nodeAtPortion(0.5);
    BOOST_REQUIRE_SMALL(nm.distance(sbfNode(2, 0, 0)), 1e-6f);
}

BOOST_AUTO_TEST_CASE( baseExtrusionn ) {
    sbfNode bl(0, 0.3, 0), br(0.3, 0.3, 0), tr(std::sqrt(2)/2, std::sqrt(2)/2, 0), tl(0, 1, 0);

    auto b = std::make_shared<sbfGeom2DLine>(bl, br);
    auto r = std::make_shared<sbfGeom2DLine>(br, tr);
    auto t = std::make_shared<sbfGeom2DArc>(sbfNode(), tr, tl);
    auto l = std::make_shared<sbfGeom2DLine>(tl, bl);

    auto f = sbfGeom2DFace(b, r, t, l);
    f.setPartitions(5, 5);

    f.makeMesh();

    auto m = f.extrude(sbfNode(0, 0, 1), 1, 2);

    m->printInfo();
    m->writeMeshToFiles(std::string("extrusion"));

}

BOOST_AUTO_TEST_CASE( baseBrick ) {

    auto m = std::unique_ptr<sbfMesh>(sbfMeshBuilder::makeBlock(10, 1, 1, 20, 2, 2));

    m->printInfo();
    m->writeMeshToFiles(std::string("block"));

}

BOOST_AUTO_TEST_SUITE_END ()
