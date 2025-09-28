cmake_minimum_required(VERSION 4.0)
project(Prueba_Compilada)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Compilada main.cpp)

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Prueba_Compilada PRIVATE AperturaDeArchivos)
target_link_libraries(Prueba_Compilada PRIVATE Sobrecargas)
