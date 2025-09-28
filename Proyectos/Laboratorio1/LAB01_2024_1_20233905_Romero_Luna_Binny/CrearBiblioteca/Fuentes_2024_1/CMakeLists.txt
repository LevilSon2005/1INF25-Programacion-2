cmake_minimum_required(VERSION 4.0)
project(Fuentes_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_2024_1 main.cpp
        src/Sobrecargas.cpp
        src/Sobrecargas.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(Fuentes_2024_1 PRIVATE AperturaDeArchivos)