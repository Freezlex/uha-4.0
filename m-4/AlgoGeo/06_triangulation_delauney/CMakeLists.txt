cmake_minimum_required(VERSION 3.24)
project(06_triangulation_delauney)

set(CMAKE_CXX_STANDARD 23)

add_executable(06_triangulation_delauney main.cpp includes/winbgi.cpp includes/graphics.h affichage.cpp affichage.h carte.cpp carte.h point.cpp point.h)
