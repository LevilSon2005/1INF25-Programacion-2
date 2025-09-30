cmake_minimum_required(VERSION 4.0)
project(Lista)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lista main.cpp
        src/BibliotecaGenerica.cpp
        src/BibliotecaGenerica.hpp
        src/ListaEmpleados.cpp
        src/ListaEmpleados.hpp
        src/Utils.hpp)
