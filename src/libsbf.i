%module libsbf
%include "std_string.i"
%include "std_list.i"
%include "std_vector.i"
%{
/* Includes the header in the wrapper code */
#include "sbfDeclspec.h"
#include "sbfMesh.h"
#include "sbfProperty.h"
#include "sbfMatrix.h"
%}

namespace std {
   %template(Indexes) vector<int>;
}

%include "sbfDeclspec.h"
%include "sbfMesh.h"
%include "sbfProperty.h"
%include "sbfMatrix.h"