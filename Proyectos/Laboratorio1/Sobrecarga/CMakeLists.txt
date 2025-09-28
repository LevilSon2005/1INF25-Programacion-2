cmake_minimum_required(VERSION 4.0)
project(Sobrecarga)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sobrecarga main.cpp
        Librerias/Funciones.cpp
        Librerias/Funciones.hpp
        Librerias/Utils.hpp
        Librerias/Vector2D.hpp
)
