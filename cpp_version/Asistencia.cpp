//
// Created by pinchiguillo on 19/11/2024.
//

#include "Asistencia.h"

#include <iostream>
#include <string>

// Constructor
Asistencia::Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado)
    : fecha(fecha), materia(materia), estado(estado) {}

// Método para mostrar la asistencia
void Asistencia::mostrarAsistencia() const {
    std::cout << "Fecha: " << fecha
              << ", Materia: " << materia
              << ", Estado: " << estado << std::endl;
}

// Getters
const std::string& Asistencia::getFecha() const { return fecha; }
const std::string& Asistencia::getMateria() const { return materia; }
const std::string& Asistencia::getEstado() const { return estado; }
