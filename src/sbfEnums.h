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

#endif // SBFENUMS_H
