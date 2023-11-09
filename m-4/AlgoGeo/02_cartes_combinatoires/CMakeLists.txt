cmake_minimum_required(VERSION 3.23)
project(02_cartes_combinatoires)

set(CMAKE_CXX_STANDARD 14)

add_executable(02_cartes_combinatoires main.cpp includes/winbgi.cpp includes/graphics.h affichage.cpp affichage.h carte.cpp carte.h point.cpp point.h)
