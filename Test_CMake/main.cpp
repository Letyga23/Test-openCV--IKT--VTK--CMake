#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "Header/ImageWork/OpenImage.h"
#include "Header/VTKTest.h"
#include "Header/ITKTest.h"

int main() 
{
    OpenImage open_image;
    VTKTest vtk;
    ITKTest itk;

    //open_image.openImage(R"(C:\Users\Admin\Pictures\Wallhaven\wallhaven-lmd95y.jpg)");
    vtk.show();
    //itk.show();

    return 0;
}

