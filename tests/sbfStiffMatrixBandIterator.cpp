#include "sbfStiffMatrixBand.h"
#include "sbfStiffMatrixBandIterator.h"
#include "sbfElement.h"
#include "sbfAdditions.h"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

#include <cmath>

BOOST_AUTO_TEST_SUITE ( sbfStiffMatrixBandIteratorTest )

auto makeTestMesh01 = []()
{
    std::unique_ptr<sbfMesh> m_up = std::make_unique<sbfMesh>();
    sbfMesh *m = m_up.get();

    /*
     *    7-------6-------11------15
     *   /|      /|      /|      /|     Z
     *  4-------5-------10------14|     |   Y
     *  | |     | |     | |     | |     |  /
     *  | 3- - -|-2- - -|-9- - -|-13    | /
     *  |/      |/      |/      |/      |/
     *  0-------1-------8------12       0-------- X
     *
     *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     * 0    x   x   x   x   x   x   x   x
     * 1    x   x   x   x   x   x   x   x   x   x   x   x
     * 2    x   x   x   x   x   x   x   x   x   x   x   x
     * 3    x   x   x   x   x   x   x   x
     * 4    x   x   x   x   x   x   x   x
     * 5    x   x   x   x   x   x   x   x   x   x   x   x
     * 6    x   x   x   x   x   x   x   x   x   x   x   x
     * 7    x   x   x   x   x   x   x   x
     * 8        x   x           x   x       x   x   x   x   x   x   x   x
     * 9        x   x           x   x       x   x   x   x   x   x   x   x
     * 10       x   x           x   x       x   x   x   x   x   x   x   x
     * 11       x   x           x   x       x   x   x   x   x   x   x   x
     * 12                                   x   x   x   x   x   x   x   x
     * 13                                   x   x   x   x   x   x   x   x
     * 14                                   x   x   x   x   x   x   x   x
     * 15                                   x   x   x   x   x   x   x   x
     *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
    */
    m->addNode ( 0, 0, 0 );
    m->addNode ( 1, 0, 0 );
    m->addNode ( 1, 1, 0 );
    m->addNode ( 0, 1, 0 );
    m->addNode ( 0, 0, 1 );
    m->addNode ( 1, 0, 1 );
    m->addNode ( 1, 1, 1 );
    m->addNode ( 0, 1, 1 );
    m->addNode ( 2, 0, 0 );
    m->addNode ( 2, 1, 0 );
    m->addNode ( 2, 0, 1 );
    m->addNode ( 2, 1, 1 );
    m->addNode ( 3, 0, 0 );
    m->addNode ( 3, 1, 0 );
    m->addNode ( 3, 0, 1 );
    m->addNode ( 3, 1, 1 );
    m->addElement ( sbfElement ( ElementType::HEXAHEDRON_LINEAR, {0, 1, 2, 3, 4, 5, 6, 7} ) );
    m->addElement ( sbfElement ( ElementType::HEXAHEDRON_LINEAR, {1, 8, 9, 2, 5, 10, 11, 6} ) );
    m->addElement ( sbfElement ( ElementType::HEXAHEDRON_LINEAR, {8, 12, 13, 9, 10, 14, 15, 11} ) );
    return std::move ( m_up );
};

BOOST_AUTO_TEST_CASE ( fullMatrix )
{
    using sbfStiffMatrixBand3 = sbfStiffMatrixBand<3>;

    auto m_up = makeTestMesh01();

    std::unique_ptr<sbfStiffMatrixBand3> stiff_up ( std::make_unique<sbfStiffMatrixBand3> (
                                                        m_up.get(), nullptr,
                                                        FULL_MATRIX ) );
    sbfStiffMatrixBand3 *stiff = stiff_up.get();

    /*
     *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     * 0    0   1   2   3   4   5   6   7
     * 1    8   9   10  11  12  13  14  15  16  17  18  19
     * 2    20  21  22  23  24  25  26  27  28  29  30  31
     * 3    32  33  34  35  36  37  38  39
     * 4    40  41  42  43  44  45  46  47
     * 5    48  49  50  51  52  53  54  55  56  57  58  59
     * 6    60  61  62  63  64  65  66  67  68  69  70  71
     * 7    72  73  74  75  76  77  78  79
     * 8        80  81  82  83  84  85  86  87  88  89  90  91  92  93  94
     * 9        95  96  97  98  99  100 101 102 103 104 105 106 107 108 109
     * 10       110 111 112 113 114 115 116 117 118 119 120 121 122 123 124
     * 11       125 126 127 128 129 130 131 132 133 134 135 136 137 138 139
     * 12                                   140 141 142 143 144 145 146 147
     * 13                                   148 149 150 151 152 153 154 155
     * 14                                   156 157 158 159 160 161 162 163
     * 15                                   164 165 166 167 168 169 170 171
     *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     */

    std::unique_ptr<sbfMatrixIterator> iter_up ( stiff->createIterator() );
    sbfMatrixIterator *iter = iter_up.get();

    {
        iter->setToRow ( 0 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->column() == 4 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 4 );
        BOOST_REQUIRE ( iter->row() == 0 );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->column() == 7 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 7 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToRowInverse ( 15 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->column() == 15 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 171 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->column() == 8 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 164 );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToColumn ( 15 );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 8 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 94 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->row() == 15 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 171 );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToColumnInverse ( 8 );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->row() == 6 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 68 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->row() == 5 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 56 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->row() == 2 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 28 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->row() == 1 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 16 );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
}

BOOST_AUTO_TEST_CASE ( lowTriangle )
{
    using sbfStiffMatrixBand3 = sbfStiffMatrixBand<3>;

    auto m_up = makeTestMesh01();

    std::unique_ptr<sbfStiffMatrixBand3> stiff_up ( std::make_unique<sbfStiffMatrixBand3> (
                                                        m_up.get(), nullptr,
                                                        DOWN_TREANGLE_MATRIX ) );
    sbfStiffMatrixBand3 *stiff = stiff_up.get();

    /*
     *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     * 0    0   x   x   x   x   x   x   x
     * 1    1   2   x   x   x   x   x   x   x   x   x   x
     * 2    3   4   5   x   x   x   x   x   x   x   x   x
     * 3    6   7   8   9   x   x   x   x
     * 4    10  11  12  13  14  x   x   x
     * 5    15  16  17  18  19  20  x   x   x   x   x   x
     * 6    21  22  23  24  25  26  27  x   x   x   x   x
     * 7    28  29  30  31  32  33  34  35
     * 8        36  37  38  39  40  41  42  43  x   x   x   x   x   x   x
     * 9        44  45  46  47  48  49  50  51  52  x   x   x   x   x   x
     * 10       53  54  55  56  57  58  59  60  61  62  x   x   x   x   x
     * 11       63  64  65  66  67  68  69  70  71  72  73  x   x   x   x
     * 12                                   74  75  76  77  78  x   x   x
     * 13                                   79  80  81  82  83  84  x   x
     * 14                                   85  86  87  88  89  90  91  x
     * 15                                   92  93  94  95  96  97  98  99
     *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     */

    std::unique_ptr<sbfMatrixIterator> iter_up ( stiff->createIterator() );
    sbfMatrixIterator *iter = iter_up.get();

    {
        iter->setToRow ( 0 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->column() == 4 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 10 );
        BOOST_REQUIRE ( iter->row() == 0 );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->column() == 7 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 28 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToRowInverse ( 15 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->column() == 15 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 99 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->column() == 8 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 92 );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToColumn ( 15 );
        BOOST_REQUIRE ( iter->row() == 8 );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 92 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 15 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 99 );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToColumnInverse ( 8 );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 6 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 41 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 5 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 40 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 2 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 37 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 1 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 36 );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToRow ( 1 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( iter->column() == 4 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 11 );
        BOOST_REQUIRE ( iter->row() == 1 );
        BOOST_REQUIRE ( iter->haveNext() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->column() == 7 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 29 );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToColumn ( 0 );
        BOOST_REQUIRE ( iter->row() == 0 );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 0 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 7 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 28 );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
    {
        iter->setToColumn ( 1 );
        BOOST_REQUIRE ( iter->row() == 0 );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( ! iter->isInNormal() );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 1 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 2 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->isDiagonal() );
        BOOST_REQUIRE ( iter->isInNormal() );
        BOOST_REQUIRE ( iter->row() == 7 );
        BOOST_REQUIRE ( ( iter->data() - stiff->data() ) / std::pow ( stiff->numDof(), 2 ) == 29 );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( iter->next() );
        BOOST_REQUIRE ( ! iter->haveNext() );
        BOOST_REQUIRE ( iter->isValid() );
        BOOST_REQUIRE ( ! iter->next() );
        BOOST_REQUIRE ( ! iter->isValid() );
    }
}

BOOST_AUTO_TEST_SUITE_END()
