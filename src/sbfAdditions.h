#ifndef SBFADDITIONS_H
#define SBFADDITIONS_H

#include <utility>

enum class SortDirection { Up, Down };

template <class TypeToSort> void quickSort(TypeToSort * arrayToSort, int left, int right, SortDirection dir = SortDirection::Up){
    int i = left, j = right;
    TypeToSort pivot = arrayToSort[(left + right) / 2];
    /* partition */
    if ( dir == SortDirection::Up ) {
        while (i <= j) {
            while (arrayToSort[i] < pivot)
                i++;
            while (arrayToSort[j] > pivot)
                j--;
            if (i <= j) {
                std::swap(arrayToSort[i], arrayToSort[j]);
                i++;
                j--;
            }
        }
    }
    else {
        while (i <= j) {
            while (arrayToSort[i] > pivot)
                i++;
            while (arrayToSort[j] < pivot)
                j--;
            if (i <= j) {
                std::swap(arrayToSort[i], arrayToSort[j]);
                i++;
                j--;
            }
        }
    }
    /* recursion */
    if (left < j)
        quickSort<TypeToSort>(arrayToSort, left, j, dir);
    if (i < right)
        quickSort<TypeToSort>(arrayToSort, i, right, dir);
}

template <class TypeToSort, class AssociatedType> void quickAssociatedSort(TypeToSort * arrayToSort, AssociatedType * associatedArray, int left, int right, SortDirection dir = SortDirection::Up){
    int i = left, j = right;
    TypeToSort pivot = arrayToSort[(left + right) / 2];
    /* partition */
    if ( dir == SortDirection::Up ) {
        while (i <= j) {
            while (arrayToSort[i] < pivot)
                i++;
            while (arrayToSort[j] > pivot)
                j--;
            if (i <= j) {
                std::swap(arrayToSort[i], arrayToSort[j]);
                std::swap(associatedArray[i], associatedArray[j]);
                i++;
                j--;
            }
        }
    }
    else {
        while (i <= j) {
            while (arrayToSort[i] > pivot)
                i++;
            while (arrayToSort[j] < pivot)
                j--;
            if (i >= j) {
                std::swap(arrayToSort[i], arrayToSort[j]);
                std::swap(associatedArray[i], associatedArray[j]);
                i++;
                j--;
            }
        }
    }
    /* recursion */
    if (left < j)
        quickAssociatedSort<TypeToSort, AssociatedType>(arrayToSort, associatedArray, left, j, dir);
    if (i < right)
        quickAssociatedSort<TypeToSort, AssociatedType>(arrayToSort, associatedArray, i, right, dir);
}

#include <memory>
#define CreateSmartAndRawPtr(Type, object, name) \
    std::unique_ptr< Type > name ## Ptr (object); \
    Type * name = (name ## Ptr).get();

#endif // SBFADDITIONS_H
