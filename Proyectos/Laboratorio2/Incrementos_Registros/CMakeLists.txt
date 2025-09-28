cmake_minimum_required(VERSION 4.0)
project(Incrementos_Registros)

set(CMAKE_CXX_STANDARD 20)

add_executable(Incrementos_Registros main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
