#ifndef SBFENUMS_H
#define SBFENUMS_H

enum class ElementType : short {
    //This enumeration type holds types of elements.
    /*1D elements*/
    BEAM_LINEAR_3DOF = 0, BEAM_QUADRATIC_3DOF = 1, BEAM_LINEAR_6DOF = 2, BEAM_QUADRATIC_6DOF = 3,
    /*2D elements*/
    RECTANGLE_LINEAR = 10, RECTANGLE_QUADRATIC = 11, TRIANGLE_LINEAR = 12, TRIANGLE_QUADRATIC = 13,
    /*3D elements*/
    HEXAHEDRON_LINEAR = 20, HEXAHEDRON_QUADRATIC = 21, TRIANGLE_PRISM_LINEAR = 22, TRIANGLE_PRISM_QUADRATIC = 23, TETRAHEDRON_LINEAR = 24, TETRAHEDRON_QUADRATIC = 25,
    /*Unknown element*/
    NO_DEFINED_ELEMENT = -1
};

enum class FileVersion : short {
    OLD_FORMAT = 0,
    NEW_FORMAT = 1,
    AUTO_FORMAT = 10,//try to determine file format during file reading
    NOT_DEFINED_FORMAT = -1
};

enum class RenumberOptimizationType : short {
    SIMPLE = 0,
    FIND_FIRST_NODE = 1
};


enum class BlockType : short {
    NO_DEFINED_BLOCK,
    DIAGONAL_BLOCK,
    UP_TREANGLE_BLOCK,
    DOWN_TREANGLE_BLOCK
};

enum MatrixType : short {
    NO_DEFINED_MATRIX = 1,
    FULL_MATRIX = 2,
    UP_TREANGLE_MATRIX = 4,
    DOWN_TREANGLE_MATRIX = 8,
    INCOMPLETE_CHOL = 16,
    CHOL_FACTOR = 32
};
inline MatrixType operator|(MatrixType first, MatrixType second) {
    return static_cast<MatrixType>(static_cast<short>(first) | static_cast<short>(second));
}

enum MatrixStoreType : short {
    NO_DEFINED_STORE_TYPE,
    COMPACT,                //Store only non-zero elements of matrix
    FULL                    //Store all elements of matrix
};

enum LockType : short {
    EXACT_LOCK_TYPE,
    APPROXIMATE_LOCK_TYPE
};

#endif // SBFENUMS_H
