cmake_minimum_required(VERSION 4.0)
project(Laboratorio_4_2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_4_2025_1 main.cpp
        src/Utils.hpp
        src/BibliotecaGenerica.cpp
        src/BibliotecaGenerica.hpp
        src/BibliotecaEnteros.cpp
        src/BibliotecaEnteros.hpp
        src/BibliotecaRegistros.cpp
        src/BibliotecaRegistros.hpp)
