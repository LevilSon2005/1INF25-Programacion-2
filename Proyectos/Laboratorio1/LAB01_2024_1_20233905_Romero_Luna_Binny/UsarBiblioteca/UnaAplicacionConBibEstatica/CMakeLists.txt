cmake_minimum_required(VERSION 4.0)
project(UnaAplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UnaAplicacionConBibEstatica main.cpp
        src/Funciones.cpp
        src/Funciones.hpp)

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(UnaAplicacionConBibEstatica PRIVATE AperturaDeArchivos)
target_link_libraries(UnaAplicacionConBibEstatica PRIVATE Sobrecargas)