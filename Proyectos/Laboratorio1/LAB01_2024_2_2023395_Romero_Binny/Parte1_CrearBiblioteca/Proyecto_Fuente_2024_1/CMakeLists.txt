cmake_minimum_required(VERSION 4.0)
project(Proyecto_Fuente_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Fuente_2024_1 main.cpp
        src/Sobrecarga.cpp
        src/Sobrecarga.hpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Proyecto_Fuente_2024_1 PRIVATE AperturaDeArchivos)