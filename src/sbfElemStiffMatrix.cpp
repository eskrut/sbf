#include "sbfElemStiffMatrix.h"

#include "sbfElement.h"

sbfElemStiffMatrix::sbfElemStiffMatrix(sbfElement *elem, sbfPropertiesSet *propSet) :
    elem_(elem),
    propSet_(propSet)
{
}
