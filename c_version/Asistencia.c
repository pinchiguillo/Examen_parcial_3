//
// Created by alexa on 19/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char fecha[11];   // Para almacenar una fecha en formato YYYY-MM-DD
    char materia[100];
    char estado[50];
} Asistencia;

// Prototipos
void setFecha(Asistencia* asistencia, const char* nuevaFecha);
void mostrarAsistencia(const Asistencia* asistencia);
bool validarFecha(const char* fecha);

// Implementación de la función para establecer la fecha
void setFecha(Asistencia* asistencia, const char* nuevaFecha) {
    if (validarFecha(nuevaFecha)) {
        strncpy(asistencia->fecha, nuevaFecha, sizeof(asistencia->fecha) - 1);
        asistencia->fecha[sizeof(asistencia->fecha) - 1] = '\0'; // Asegura la terminación nula
    } else {
        fprintf(stderr, "Error: La fecha debe tener el formato YYYY-MM-DD y ser válida.\n");
        exit(EXIT_FAILURE);
    }
}

// Validar la fecha usando lógica similar a la validación en C++
bool validarFecha(const char* fecha) {
    int anio, mes, dia;
    if (sscanf(fecha, "%4d-%2d-%2d", &anio, &mes, &dia) != 3) {
        return false;
    }

    if (mes < 1 || mes > 12) {
        return false;
    }

    if (dia < 1 || dia > 31) {
        return false;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return false;
    }

    if (mes == 2) {
        // Verificar si es año bisiesto
        bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if ((esBisiesto && dia > 29) || (!esBisiesto && dia > 28)) {
            return false;
        }
    }

    return true;
}

// Mostrar la asistencia
void mostrarAsistencia(const Asistencia* asistencia) {
    printf("Fecha: %s, Materia: %s, Estado: %s\n", asistencia->fecha, asistencia->materia, asistencia->estado);
}

// Programa principal para probar la estructura
int main() {
    Asistencia asistencia;

    // Establecer valores
    strncpy(asistencia.materia, "Matemáticas", sizeof(asistencia.materia) - 1);
    asistencia.materia[sizeof(asistencia.materia) - 1] = '\0';

    strncpy(asistencia.estado, "Presente", sizeof(asistencia.estado) - 1);
    asistencia.estado[sizeof(asistencia.estado) - 1] = '\0';

    setFecha(&asistencia, "2024-11-21");

    // Mostrar la asistencia
    mostrarAsistencia(&asistencia);

    return 0;
}
