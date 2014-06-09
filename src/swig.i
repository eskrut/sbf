%module sbf

%{
/* Includes the header in the wrapper code */
#include "string"

#include "sbfAdditions.h"
#include "sbfDeclspec.h"
#include "sbfElemStiffMatrixHexa8.h"
#include "sbfElement.h"
#include "sbfElementGroup.h"
#include "sbfEnums.h"
#include "sbfGroup.h"
#include "sbfGroupFilter.h"
#include "sbfMaterialProperties.h"
#include "sbfMatrixIterator.h"
#include "sbfMesh.h"
#include "sbfMeshBuilders.h"
#include "sbfNode.h"
#include "sbfNodeGroup.h"
#include "sbfParallelTask.h"
#include "sbfPropertiesSet.h"
#include "sbfPropertyTable.h"
#include "sbfReporter.h"
#include "sbfSELevel.h"
#include "sbfSELevelList.h"
#include "sbfSElement.h"
#include "sbfStiffBlock3x3.h"
#include "sbfStiffMatrixBlock3x3.h"
#include "sbfStiffMatrixBlock3x3Iterator.h"
#include "sbfTimer.h"
#include "sbfWorker.h"
%}

namespace std {
   %template(Indexes) vector<int>;
}

%include stl.i
%include <std_string.i>
%include <std_list.i>
%include <std_vector.i>
%include <std_map.i>
%include <std_pair.i>

%include "sbfAdditions.h"
%include "sbfDeclspec.h"
%include "sbfElemStiffMatrixHexa8.h"
%include "sbfElement.h"
%include "sbfElementGroup.h"
%include "sbfEnums.h"
%include "sbfGroup.h"
%include "sbfGroupFilter.h"
%include "sbfMaterialProperties.h"
%include "sbfMatrixIterator.h"
%include "sbfMesh.h"
%include "sbfMeshBuilders.h"
%include "sbfNode.h"
%include "sbfNodeGroup.h"
%include "sbfParallelTask.h"
%include "sbfPropertiesSet.h"
%include "sbfPropertyTable.h"
%include "sbfReporter.h"
%include "sbfSELevel.h"
%include "sbfSELevelList.h"
%include "sbfSElement.h"
%include "sbfStiffBlock3x3.h"
%include "sbfStiffMatrixBlock3x3.h"
%include "sbfStiffMatrixBlock3x3Iterator.h"
%include "sbfTimer.h"
%include "sbfWorker.h"
