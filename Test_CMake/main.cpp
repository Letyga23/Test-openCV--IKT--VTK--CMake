#include "Header/ImageWork/OpenImage.h"
#include "Header/VTKTest.h"
#include "Header/ITKTest.h"

int main() 
{
    OpenImage open_image;
    VTKTest vtk;
    ITKTest itk;

    open_image.openImage("Image/forTest.jpg");
    //vtk.show();
    //itk.show();

    return 0;
}

