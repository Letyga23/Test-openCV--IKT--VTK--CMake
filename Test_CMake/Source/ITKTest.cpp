#include "..\Header\ITKTest.h"

void ITKTest::show()
{
    const int widthAndLength = 500;
    const unsigned int radius = 100;

    //Создаём изображение размером 500x500
    ImageType::Pointer image = ImageType::New();
    ImageType::RegionType region;
    region.SetSize({ widthAndLength, widthAndLength });
    image->SetRegions(region);
    image->Allocate();

    //Заполняем изображение серым цветом
    image->FillBuffer(CreateRGBPixel(127, 127, 127));

    //Рисуем красный круг
    DrawCircle(image, { widthAndLength / 2, widthAndLength / 2 }, radius, CreateRGBPixel(255, 0, 0));

    //Записываем изображение в файл
    try
    {
        using WriterType = itk::ImageFileWriter<ImageType>;
        WriterType::Pointer writer = WriterType::New();
        writer->SetFileName("test_itk_output_with_circle.png");
        writer->SetInput(image);
        writer->Update();
        DebugLog("Файл test_itk_output_with_circle.png успешно записан!");
    }
    catch (const itk::ExceptionObject& error)
    {
        DebugLog("Ошибка записи файла: " + std::string(error.GetDescription()));
    }
}

itk::RGBPixel<unsigned char> ITKTest::CreateRGBPixel(unsigned char r, unsigned char g, unsigned char b)
{
    itk::RGBPixel<unsigned char> color;
    color.SetRed(r);
    color.SetGreen(g);
    color.SetBlue(b);
    return color;
}

void ITKTest::DrawCircle(ImageType::Pointer image, ImageType::IndexType center, unsigned int radius, itk::RGBPixel<unsigned char> color)
{
    ImageType::SizeType size = image->GetLargestPossibleRegion().GetSize();

    //Проход по всем пикселям
    for (unsigned int x = 0; x < size[0]; ++x)
    {
        for (unsigned int y = 0; y < size[1]; ++y)
        {
            if (std::sqrt(std::pow(x - center[0], 2) + std::pow(y - center[1], 2)) <= radius)
                image->SetPixel({ x, y }, color);  //Окрашиваем пиксель
        }
    }
}
