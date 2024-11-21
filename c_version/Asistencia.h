//
// Created by alexa on 19/11/2024.
//

#ifndef ASISTENCIA_H
#define ASISTENCIA_H

#include <stdbool.h> // Para usar el tipo booleano

// Definición de la estructura Asistencia
typedef struct {
    char fecha[11];   // Formato YYYY-MM-DD
    char materia[100];
    char estado[50];  // "Asistió", "Falta", "Tardanza"
} Asistencia;
// Prototipos de funciones
void initAsistencia(Asistencia* asistencia, const char* fecha, const char* materia, const char* estado);
void mostrarAsistencia(const Asistencia* asistencia);
void setFecha(Asistencia* asistencia, const char* nuevaFecha);
const char* getFecha(const Asistencia* asistencia);
const char* getMateria(const Asistencia* asistencia);
const char* getEstado(const Asistencia* asistencia);

bool validarFecha(const char* fecha);

#endif // ASISTENCIA_H
