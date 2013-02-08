#include "sbfMesh.h"

#ifdef USE_VTK

#include <vtkDataSet.h>
#include <vtkUnstructuredGrid.h>
#include <vtkSmartPointer.h>
#include <vtkXMLReader.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkFieldData.h>
#include <vtkCellTypes.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkDataArray.h>
#include <vtkFloatArray.h>
#include <vtksys/SystemTools.hxx>

VTKCellType sbfTypeToVTK(sbf::ElementType type);

//Make XML vtu file
int sbf::sbfMesh::writeToVTKFile(const char* baseName)
{
	vtkSmartPointer<vtkUnstructuredGrid> grid = vtkSmartPointer<vtkUnstructuredGrid>::New();
	vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

	points->SetNumberOfPoints(this->numNodes());
	for(int ct = 0; ct < this->numNodes(); ct++) { sbfNode node = this->node(ct); points->SetPoint(ct, node.x() , node.y(), node.z()); }
	grid->SetPoints(points);

	std::vector <int> cellTypes;
	cellTypes.reserve(this->numElements());
	for(int ct = 0; ct < this->numElements(); ct++){
		sbfElement *elem = this->elemPtr(ct);
		cellTypes.push_back(sbfTypeToVTK(elem->type()));
		cells->InsertNextCell(elem->numNodes());
		std::vector<int> indexes = elem->indexes();
		for(size_t ct1 = 0; ct1 < indexes.size(); ct1++) cells->InsertCellPoint(indexes[ct1]);
	}
	grid->SetCells(&cellTypes[0], cells);

	vtkSmartPointer<vtkXMLUnstructuredGridWriter> writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();

	vtkSmartPointer<vtkFloatArray> array = vtkSmartPointer<vtkFloatArray>::New();
	array->SetName("testData");
	//array->SetNumberOfComponents(1);
	array->SetNumberOfValues(this->numNodes());
	for(int ct = 0; ct < this->numNodes(); ct++) array->SetValue(ct, 0.0f);

	writer->SetNumberOfTimeSteps(2);
	writer->SetInput(grid);
	std::string name = baseName;
	name += ".";
	name += writer->GetDefaultFileExtension();
	writer->SetFileName(name.c_str());
	//writer->SetDataModeToAscii();
	writer->SetByteOrderToLittleEndian();
	//writer->SetCompressorTypeToNone();

	//
	writer->Start();
	grid->GetPointData()->SetScalars(array);
	writer->WriteNextTime(0.1);
	grid->GetPointData()->SetScalars(array);
	writer->WriteNextTime(0.2);
	writer->Stop();
	//writer->WriteNextTime(0.2);

//	writer->Write();

	return 0;
}

VTKCellType sbfTypeToVTK(sbf::ElementType type)
{
	switch(type){
	case sbf::HEXAHEDRON_LINEAR:
		return VTK_HEXAHEDRON;
		break;
	default:
		break;
	}
	return VTK_EMPTY_CELL;
}


#else //USE_VTK
//Make legacy vtk file
int sbf::sbfMesh::writeToVTKFile(const char* baseName)
{
	return 0;
}

#endif //USE_VTK
