cmake_minimum_required(VERSION 3.23)
project(04_triangulation)

set(CMAKE_CXX_STANDARD 23)

add_executable(04_triangulation main.cpp includes/winbgi.cpp includes/graphics.h affichage.cpp affichage.h carte.cpp carte.h point.cpp point.h)
