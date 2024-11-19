//
// Created by pinchiguillo on 19/11/2024.
//

#include "Estudiante.h"
#include "Asistencia.h"
#include "materias.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Constructor
Estudiante::Estudiante(const std::string& nombre, int edad, float promedio)
    : edad(edad), promedio(promedio) {
    setNombre(nombre); // Usa el setter para validar y asignar el nombre
}

// Métodos para gestionar materias
void Estudiante::agregarMateria(const std::string& materia) {
    // Verificar si la materia está en la lista de materias disponibles
    if (std::find(materiasDisponibles.begin(), materiasDisponibles.end(), materia) == materiasDisponibles.end()) {
        // Si no está en la lista, lanzar una excepción
        throw std::runtime_error("La materia '" + materia + "' no está disponible en la lista predefinida.");
    }

    // Agregar la materia a la lista del estudiante
    materias.push_back(materia);
}

void Estudiante::eliminarMateria(const std::string& materia) {
    auto it = std::find(materias.begin(), materias.end(), materia);
    if (it != materias.end()) {
        materias.erase(it);
    } else {
        std::cout << "La materia '" << materia << "' no está inscrita." << std::endl;
    }
}

void Estudiante::mostrarMaterias() const {
    std::cout << "Materias inscritas por " << nombre << ":" << std::endl;
    for (const auto& materia : materias) {
        std::cout << "- " << materia << std::endl;
    }
}

// Métodos para gestionar asistencias
void Estudiante::registrarAsistencia(const Asistencia& asis) {
    // Verificar si la materia existe en el listado predefinido de materias
    if (std::find(materiasDisponibles.begin(), materiasDisponibles.end(), asis.getMateria()) == materiasDisponibles.end()) {
        throw std::runtime_error("La materia '" + asis.getMateria() + "' no existe en el listado de materias disponibles.");
    }

    // Verificar si el estudiante está inscrito en la materia
    if (std::find(materias.begin(), materias.end(), asis.getMateria()) == materias.end()) {
        throw std::runtime_error("El estudiante no está inscrito en la materia '" + asis.getMateria() + "'.");
    }

    // Si pasa ambas validaciones, registrar la asistencia
    asistencias.push_back(asis);
}

void Estudiante::mostrarAsistencias() const {
    std::cout << "Registro de asistencias de " << nombre << ":" << std::endl;
    for (const auto& asis : asistencias) {
        asis.mostrarAsistencia();
    }
}

// Método para mostrar los datos del estudiante
void Estudiante::mostrarEstudiante() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;
    mostrarMaterias();
}

// Getters
const std::string& Estudiante::getNombre() const { return nombre; }
int Estudiante::getEdad() const { return edad; }
float Estudiante::getPromedio() const { return promedio; }

// Setters
void Estudiante::setNombre(const std::string& nuevoNombre) {
    if (!nuevoNombre.empty()) {
        nombre = nuevoNombre;
    } else {
        throw std::invalid_argument("Error: El nombre no puede estar vacío.");
    }
}
void Estudiante::setEdad(int nuevaEdad) {
    if (nuevaEdad >= 0) {
        edad = nuevaEdad;
    } else {
        throw std::invalid_argument("Error: La edad no puede ser negativa.");
    }
}
void Estudiante::setPromedio(float nuevoPromedio) {
    if (nuevoPromedio >= 0 && nuevoPromedio <= 10) {
        promedio = nuevoPromedio;
    } else {
        throw std::invalid_argument("Error: La nota debe estar entre 0 y 10.");
    }
}
