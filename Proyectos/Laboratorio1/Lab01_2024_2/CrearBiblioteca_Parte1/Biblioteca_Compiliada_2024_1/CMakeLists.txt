cmake_minimum_required(VERSION 4.0)
project(Biblioteca_Compiliada_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_library(Sobrecargas STATIC src/Sobrecargas.cpp)

add_executable(Biblioteca_Compiliada_2024_1 main.cpp)

target_link_libraries(Biblioteca_Compiliada_2024_1 Sobrecargas)
