cmake_minimum_required(VERSION 3.27)
project(Arboles_Binarios)

set(CMAKE_CXX_STANDARD 20)

add_executable(Arboles_Binarios main.cpp
        Abin_Enla.cpp
        Abin_Enla.h
        Abin_Vec.cpp
        Abin_Vec.h
        Abin_VecPos.cpp
        Abin_VecPos.h)
