cmake_minimum_required(VERSION 4.0)
project(Fuentes_Biblioteca_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_Biblioteca_2024_2 main.cpp
        src/Sobrecargas.cpp
        src/Sobrecargas.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Fuentes_Biblioteca_2024_2 PRIVATE AperturaDeArchivos)
