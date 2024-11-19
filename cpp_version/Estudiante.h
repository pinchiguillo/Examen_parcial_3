//
// Created by pinchiguillo on 19/11/2024.
//

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Asistencia.h"

#include <string>
#include <vector>
#include <iostream>

class Estudiante {
private:
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
    std::vector<Asistencia> asistencias;

public:
    // Constructor
    Estudiante(const std::string& nombre, int edad, float promedio);

    // Métodos para gestionar materias
    void agregarMateria(const std::string& materia);
    void eliminarMateria(const std::string& materia);
    void mostrarMaterias() const;

    // Métodos para gestionar asistencias
    void registrarAsistencia(const Asistencia& asis);
    void mostrarAsistencias() const;

    // Método para mostrar los datos del estudiante
    void mostrarEstudiante() const;

    // Getters
    const std::string& getNombre() const;
    int getEdad() const;
    float getPromedio() const;

    // Setters
    void setNombre(const std::string& nuevoNombre);
    void setEdad(int nuevaEdad);
    void setPromedio(float nuevoPromedio);
};

#endif // ESTUDIANTE_H
ESTUDIANTE_H