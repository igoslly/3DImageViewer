
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

#include "vtkImageViewer3.h"




int main(int argc, char *argv[])
{


	int x = 200;
	int y = 200;
	int z = 100;

	//读取Dicom数据
	//VTK可以从文件夹中读取一系列数据，并组合为三维图像数据。
	char dirname[100] = "..\\..\\Source\\CT2\\";
	vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
	dicomReader->SetDirectoryName(dirname);
	dicomReader->Update();

	////创建显示窗口
	//vtkSmartPointer<vtkRenderWindow> windowsBasic = vtkSmartPointer<vtkRenderWindow> ::New();
	//windowsBasic->SetSize(500, 500);

	////创建vtkImageViewer3子窗口，用以显示二维图形
	//vtkSmartPointer<vtkImageViewer3> viewer = vtkSmartPointer<vtkImageViewer3>::New();
	////设置数据源
	//viewer->SetInputConnection(dicomReader->GetOutputPort());
	////设置显示坐标
	//viewer->SetPoint(x, y, z);
	////设置渲染窗口
	//viewer->SetRenderWindow(windowsBasic);

	//vtkImageViewer2单图像实现
	vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
	viewer->SetInputConnection(dicomReader->GetOutputPort());
	viewer->SetSliceOrientationToXY();
	viewer->SetSlice(100);

	//创建交互器
	vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//windowInteractor->SetRenderWindow(windowsBasic);//-3
	windowInteractor->SetRenderWindow(viewer->GetRenderWindow());//-2
	//交互器样式暂时采用vtkInteractorStyleImage
	vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	windowInteractor->SetInteractorStyle(windowInteractorStyle);

	//初始化与显示
	windowInteractor->Initialize();
	windowInteractor->Start();

	return 0;
}
