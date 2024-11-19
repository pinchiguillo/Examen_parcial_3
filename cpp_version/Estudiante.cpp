//
// Created by pinchiguillo on 19/11/2024.
//

#include "Estudiante.h"
#include "Asistencia.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Constructor
Estudiante::Estudiante(const std::string& nombre, int edad, float promedio)
    : nombre(nombre), edad(edad), promedio(promedio) {}

// Métodos para gestionar materias
void Estudiante::agregarMateria(const std::string& materia) {
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
void Estudiante::setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
void Estudiante::setEdad(int nuevaEdad) { edad = nuevaEdad; }
void Estudiante::setPromedio(float nuevoPromedio) { promedio = nuevoPromedio; }
