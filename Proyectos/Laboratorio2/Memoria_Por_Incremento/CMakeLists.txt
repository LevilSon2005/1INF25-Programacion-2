cmake_minimum_required(VERSION 4.0)
project(Memoria_Por_Incremento)

set(CMAKE_CXX_STANDARD 20)

add_executable(Memoria_Por_Incremento main.cpp
        src/MemoriaIncrementos.cpp
        src/MemoriaIncrementos.hpp
        src/Utils.hpp)
