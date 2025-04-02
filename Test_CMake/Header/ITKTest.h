#pragma once
#include <itkImage.h>
#include <itkImageFileWriter.h>
#include <itkRGBPixel.h>
#include "Utils/DebugLog.h"

constexpr unsigned int Dimension = 2;
using PixelType = itk::RGBPixel<unsigned char>;
using ImageType = itk::Image<PixelType, Dimension>;

class ITKTest
{
public:
	ITKTest() {};
	void show();

private:
	void DrawCircle(ImageType::Pointer image, ImageType::IndexType center, unsigned int radius, PixelType color);
	itk::RGBPixel<unsigned char> CreateRGBPixel(unsigned char r, unsigned char g, unsigned char b);
};