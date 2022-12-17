cmake_minimum_required(VERSION 3.23)
project(rocket_os)

set(CMAKE_CXX_STANDARD 14)

include_directories(functions)

add_executable(rocket_os
        functions/test.cpp
        functions/test.h
        src/main.cpp src/Sensors/imu.cpp)
