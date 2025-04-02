#pragma once
#include <opencv2/opencv.hpp>
#include "../Utils/DebugLog.h"

#ifdef _WIN32
#include <windows.h>  //Для Windows API
#else
#include <X11/Xlib.h> //Для Linux (X11)
#endif

class OpenImage
{
	cv::Mat original_img;
	cv::Mat resized_img;
	std::string window_name;
	int max_scale = 100;
	int min_scale = 1;

public:
	OpenImage(std::string window_name = "Test");
	//Открытие изображения с масштабированием окна под экран
	void openImage(const std::string& path, double percent = 50.0);

private:
	//Функция получения разрешения экрана
	void getScreenResolution(int& width, int& height);

	//Функция изменения качества изображения через трекбар
	static void onResolution(int scale, void* userdata);
};