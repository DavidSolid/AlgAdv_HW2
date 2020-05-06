cmake_minimum_required(VERSION 3.14)
project(AlgAdv_HW2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgAdv_HW2 main.cpp graph_structures/Matrix.h utilities/Parser.h utilities/Graph_Data.h algorithms/prim.h data_structures/MinHeap.h algorithms/preorder_2approx.h)