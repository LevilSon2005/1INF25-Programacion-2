cmake_minimum_required(VERSION 4.0)
project(Ejercicio_BibGenerica_BibCadaVariable)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ejercicio_BibGenerica_BibCadaVariable main.cpp
        src/BibliotecaGenerica.cpp
        src/BibliotecaGenerica.hpp
        src/BibliotecaEnteros.cpp
        src/BibliotecaEnteros.hpp
        src/Utils.hpp)
