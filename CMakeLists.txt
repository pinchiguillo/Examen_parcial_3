cmake_minimum_required(VERSION 3.30)

project(Examen_parcial_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(C_Version main.c
        main.c
        c_version/Asistencia.c
        c_version/Asistencia.h
        c_version/Estudiantes.c
        c_version/Estudiantes.h)

add_executable(Cpp_Version
        cpp_version/main.cpp
        cpp_version/Estudiante.h
        cpp_version/Estudiante.cpp
        cpp_version/Asistencia.h
        cpp_version/Asistencia.cpp
        cpp_version/materias.h
