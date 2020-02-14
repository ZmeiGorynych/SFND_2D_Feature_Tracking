cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(camera_fusion)

#find_package(OpenCV 4.1 REQUIRED)
#/home/ubuntu/shared/GitHubLibs/opencv-4.1.0/build
find_package(OpenCV REQUIRED PATHS /home/ubuntu/shared/GitHubLibs/opencv-4.1.0/build NO_DEFAULT_PATH)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Executable for create matrix exercise
add_executable (2D_feature_tracking src/matching2D_Student.cpp src/MidTermProject_Camera_Student.cpp)
target_link_libraries (2D_feature_tracking ${OpenCV_LIBRARIES})

# link how to install OpenCV on Ubuntu 16.04:
# https://www.pyimagesearch.com/2016/10/24/ubuntu-16-04-how-to-install-opencv/

# However for OpenCV 4.1.0 you should use the following cmake
# command to build OpenCV with nonfree libs
# cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D INSTALL_C_EXAMPLES=ON -D OPENCV_EXTRA_MODULES_PATH=~/shared/GitHubLibs/opencv_contrib-4.1.0/modules -D BUILD_EXAMPLES=ON -D OPENCV_ENABLE_NONFREE:BOOL=ON ..