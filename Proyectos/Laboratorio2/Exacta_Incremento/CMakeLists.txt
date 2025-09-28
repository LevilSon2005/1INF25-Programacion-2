cmake_minimum_required(VERSION 4.0)
project(Exacta_Incremento)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exacta_Incremento main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
