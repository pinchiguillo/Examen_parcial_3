//
// Created by pinchiguillo on 19/11/2024.
//

#include "Asistencia.h"

#include <iostream>
#include <string>

#include <regex>      // Para usar std::regex
#include <stdexcept>  // Para usar std::invalid_argument
#include <sstream>    // Para convertir partes de la fecha a números

Asistencia::Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado)
    : materia(materia), estado(estado) {
    setFecha(fecha); // Valida y asigna la fecha
}

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

void Asistencia::setFecha(const std::string& nuevaFecha) {
    // Validar el formato con la expresión regular
    std::regex formatoFecha("^\\d{4}-(\\d{2})-(\\d{2})$");
    std::smatch match;
    if (std::regex_match(nuevaFecha, match, formatoFecha)) {
        // Extraer los componentes de la fecha
        int anio, mes, dia;
        std::stringstream ss(nuevaFecha);
        char guion; // Para descartar los guiones
        ss >> anio >> guion >> mes >> guion >> dia;

        // Validar el rango lógico de los componentes
        if (mes < 1 || mes > 12) {
            throw std::invalid_argument("Error: El mes debe estar entre 1 y 12.");
        }
        if (dia < 1 || dia > 31) {
            throw std::invalid_argument("Error: El día debe estar entre 1 y 31.");
        }
        if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
            throw std::invalid_argument("Error: El mes especificado tiene un máximo de 30 días.");
        }
        if (mes == 2) {
            // Comprobar si es año bisiesto
            bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
            if ((esBisiesto && dia > 29) || (!esBisiesto && dia > 28)) {
                throw std::invalid_argument("Error: Febrero tiene un máximo de 28 días (29 en años bisiestos).");
            }
        }

        // Si pasa todas las validaciones, asignar la fecha
        this->fecha = nuevaFecha;
    } else {
        throw std::invalid_argument("Error: La fecha debe tener el formato YYYY-MM-DD.");
    }
}