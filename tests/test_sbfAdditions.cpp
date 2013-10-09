#include "test_sbfAdditions.h"
#include "sbfAdditions.h"
#include <random>
#include <vector>
#include <unordered_map>
#include <limits>

void TestSbfAdditions::case01_sorting()
{
    //test simple sorting
    {
        using SortType = int;
        std::default_random_engine generator;
        std::uniform_int_distribution<SortType> distribution(-100000, 100000);
        auto random = std::bind(distribution, generator);
        std::vector<SortType> arr0;
        arr0.resize(1000);
        for(auto & it : arr0) it = random();
        auto arr1 = arr0;
        quickSort(&arr1[0], 0, arr1.size()-1);
        bool pass = true;
        for(auto it = arr1.begin(); it < arr1.end()-1; it++)
            if ( *it > *(it+1) ) {
                pass = false; break;
            }
        QVERIFY2(pass, "Failed to sort vector");
        arr1 = arr0;
        quickSort(&arr1[0], 0, arr1.size()-1, SortDirection::Down);
        pass = true;
        for(auto it = arr1.begin(); it < arr1.end()-1; it++)
            if ( *it < *(it+1) ) {
                pass = false; break;
            }
        QVERIFY2(pass, "Failed to sort vector (down)");
    }
    //test assotiated sorting
    {
        using SortType = float;
        using AssosType = int;
        std::default_random_engine generator;
        std::uniform_real_distribution<SortType> distributionSortType(-1000, 1000);
        std::uniform_int_distribution<AssosType> distributionAssosType(-std::numeric_limits<AssosType>::max(), std::numeric_limits<AssosType>::max());
        auto randomSortType = std::bind(distributionSortType, generator);
        auto randomAssosType = std::bind(distributionAssosType, generator);
        std::unordered_map<SortType, AssosType> map;

        for(int ct = 0; ct < 100000; ct++)
            map[randomSortType()] = randomAssosType();
        std::vector<SortType> sortArr;
        std::vector<AssosType> assArr;
        sortArr.reserve(map.size());
        assArr.reserve(map.size());

        for(auto it : map) {
            sortArr.push_back(it.first);
            assArr.push_back(it.second);
        }

        quickAssociatedSort(&sortArr[0], &assArr[0], 0, sortArr.size()-1);

        bool pass = true;
        for(auto it = sortArr.begin(); it < sortArr.end()-1; it++)
            if ( *it > *(it+1) ) { pass = false; break; }
        QVERIFY2(pass, "Failed to make assotiated sort");

        pass = true;
        for(size_t ct = 0; ct < sortArr.size(); ct++){
            if (map[sortArr[ct]] != assArr[ct]) { pass = false; break; }
        }
        QVERIFY2(pass, "Failed in assotiated sort");
    }
}
