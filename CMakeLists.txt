cmake_minimum_required(VERSION 3.0.0)
project(prueba VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(lib STATIC archivos.cpp
funcionesAuxiliares.cpp
funcionesEquipos.cpp
manejoMemoria.cpp
menu.cpp
)
target_include_directories(lib PUBLIC /library)

add_executable(TP1 main.cpp)
target_link_libraries(TP1 PUBLIC lib)
