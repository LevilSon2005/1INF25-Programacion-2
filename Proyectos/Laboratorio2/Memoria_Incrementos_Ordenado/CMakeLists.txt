cmake_minimum_required(VERSION 4.0)
project(Memoria_Incrementos_Ordenado)

set(CMAKE_CXX_STANDARD 20)

add_executable(Memoria_Incrementos_Ordenado main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
