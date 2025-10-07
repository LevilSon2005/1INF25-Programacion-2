cmake_minimum_required(VERSION 4.0)
project(Laboratorio5_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio5_2024_2 main.cpp
        src/Utils.hpp
        src/BibliotecaGenerica.cpp
        src/BibliotecaGenerica.hpp
        src/ListaconEnteros.cpp
        src/ListaconEnteros.hpp)
