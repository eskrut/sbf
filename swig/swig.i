%module sbf

%include "std_vector.i"

%{
#include "sbfNode.h"
#include "sbfElement.h"
%}

namespace std {
   %template(Indexes) vector<int>;
}


