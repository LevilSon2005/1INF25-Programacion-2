cmake_minimum_required(VERSION 4.0)
project(Teoria_Punteros_Genericos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Teoria_Punteros_Genericos main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
)
