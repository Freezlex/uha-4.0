cmake_minimum_required(VERSION 3.23)
project(AlgoGeo)

set(CMAKE_CXX_STANDARD 23)

add_executable(AlgoGeo main.cpp includes/graphics.h includes/winbgi.cpp Shape/Point/Point.cpp Shape/Point/Point.h Shape/Envelope/Envelope.cpp Shape/Envelope/Envelope.h Shape/Polygon/Polygon.cpp Shape/Polygon/Polygon.h Shape/Vertex/Vertex.cpp Shape/Vertex/Vertex.h )
