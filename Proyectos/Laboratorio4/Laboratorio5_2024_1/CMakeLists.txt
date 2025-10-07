cmake_minimum_required(VERSION 4.0)
project(Laboratorio5_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio5_2024_1 main.cpp
        src/Utils.hpp
        src/BibliotecaGenerica.cpp
        src/BibliotecaGenerica.hpp
        src/FuncionEnteros.cpp
        src/FuncionEnteros.hpp
        src/BibliotecaRegistro.cpp
        src/BibliotecaRegistro.hpp)
