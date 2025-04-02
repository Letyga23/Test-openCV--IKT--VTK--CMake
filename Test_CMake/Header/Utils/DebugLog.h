#pragma once
#include <Windows.h>
#include <string>
#include <locale>
#include <codecvt>

static void DebugLog(const std::string& message)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideMessage = converter.from_bytes(message + "\n");
    OutputDebugStringW((wideMessage).c_str());
}

static void DebugLog(int message)
{
    DebugLog(std::to_string(message));
}

static void DebugLog(float message)
{
    DebugLog(std::to_string(message));
}

static void DebugLog(bool message)
{
    DebugLog(message ? std::string("true") : std::string("false"));
}

static void DebugLog(const char* message)
{
    DebugLog(std::string(message));
}