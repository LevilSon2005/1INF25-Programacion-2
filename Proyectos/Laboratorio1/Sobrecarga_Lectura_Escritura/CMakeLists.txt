cmake_minimum_required(VERSION 4.0)
project(Sobrecarga_Lectura_Escritura)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sobrecarga_Lectura_Escritura main.cpp
        src/FuncionesAux.cpp
        src/FuncionesAux.hpp
        src/Utils.hpp
        src/Sobrecarga.cpp
        src/Sobrecarga.hpp
        src/Review.hpp
        src/Reviews.hpp)
