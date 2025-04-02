#include "../../Header/ImageWork/OpenImage.h"

OpenImage::OpenImage(std::string window_name) : window_name(window_name)
{
}

void OpenImage::openImage(const std::string& path, double percent)
{
    original_img = cv::imread(path);
    if (original_img.empty())
    {
        DebugLog("Ошибка: не удалось загрузить изображение!");
        return;
    }

    //Получаем разрешение экрана динамически
    int screen_width, screen_height;
    getScreenResolution(screen_width, screen_height);

    //Вычисляем стартовый размер окна
    int window_width = static_cast<int>(screen_width * (percent / 100.0));
    int window_height = static_cast<int>(screen_height * (percent / 100.0));

    //Создаем изменяемое окно
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);
    cv::resizeWindow(window_name, window_width, window_height);

    //Устанавливаем обработчик изменения размера окна
    int default_scale = 100; //100% качество по умолчанию
    cv::createTrackbar("Resolution", window_name, &default_scale, max_scale, OpenImage::onResolution, this);
    cv::setTrackbarMin("Resolution", window_name, min_scale);


    cv::waitKey(0);
}

void OpenImage::getScreenResolution(int& width, int& height)
{
#ifdef _WIN32
    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);
#else
    Display* disp = XOpenDisplay(nullptr);
    if (disp)
    {
        Screen* scr = DefaultScreenOfDisplay(disp);
        width = scr->width;
        height = scr->height;
        XCloseDisplay(disp);
    }
    else
    {
        width = 1920; //Значения по умолчанию, если не удалось получить
        height = 1080;
    }
#endif
}

void OpenImage::onResolution(int scale, void* userdata)
{
    OpenImage* self = static_cast<OpenImage*>(userdata); //Получаем указатель на объект
    if (scale < 1) scale = 1; //Минимальное значение 1%

    double factor = scale / 100.0; //Коэффициент уменьшения
    cv::Size new_size(self->original_img.cols * factor, self->original_img.rows * factor);

    cv::resize(self->original_img, self->resized_img, new_size, 0, 0, cv::INTER_LINEAR);
    cv::imshow(self->window_name, self->resized_img);
}
