cmake_minimum_required(VERSION 3.8)
project(Test_CMake)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")

find_package(OpenCV REQUIRED)
find_package(ITK REQUIRED)
find_package(VTK REQUIRED)

include(${ITK_USE_FILE})

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADER  "*.h")
add_executable(Test_CMake ${SOURCES} ${HEADER})

#target_link_directories(Test_CMake PRIVATE "C:/vcpkg/installed/x64-windows/lib") #Для ITK (чтобы находилося minc2.lib) если не работает include(${ITK_USE_FILE})
target_link_libraries(Test_CMake PRIVATE ${OpenCV_LIBRARIES} ${ITK_LIBRARIES} ${VTK_LIBRARIES})

vtk_module_autoinit(
    TARGETS Test_CMake
    MODULES ${VTK_LIBRARIES}
)