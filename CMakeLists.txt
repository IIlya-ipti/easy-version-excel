cmake_minimum_required(VERSION 3.24)
project(simplified_excel)
set(CMAKE_CXX_STANDARD 17)

add_executable(simplified_excel src/main.cpp src/csv_class.cpp src/additionally.cpp)