#include "sbfStiffMatrixBand.h"
#include "sbfAdditions.h"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

BOOST_AUTO_TEST_SUITE(sbfStiffMatrixBandIteratorSuite)

BOOST_AUTO_TEST_CASE(fullMatrix)
{
    using sbfStiffMatrixBand3 = sbfStiffMatrixBand<3>;

    std::unique_ptr<sbfStiffMatrixBand3> stiff(new sbfStiffMatrixBand3(nullptr, nullptr, FULL_MATRIX));
}

BOOST_AUTO_TEST_SUITE_END()
