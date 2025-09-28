cmake_minimum_required(VERSION 4.0)
project(Prueba_Biblioteca_Compilada_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_Compilada_2024_2 main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Prueba_Biblioteca_Compilada_2024_2 PRIVATE AperturaDeArchivos)
target_link_libraries(Prueba_Biblioteca_Compilada_2024_2 PRIVATE Sobrecargas)