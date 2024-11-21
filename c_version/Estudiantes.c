//
// Created by alexa on 19/11/2024.
//
#include "Estudiantes.h"
#include "Asistencia.h"
#include "materias.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Constructor: Inicializa un estudiante con datos básicos
void initEstudiante(Estudiante* estudiante, const char* nombre, int edad, float promedio) {
    if (estudiante == NULL) return;

    setNombre(estudiante, nombre);
    setEdad(estudiante, edad);
    setPromedio(estudiante, promedio);
    estudiante->numMaterias = 0;
    estudiante->numAsistencias = 0;
}

// Métodos para gestionar materias
void agregarMateria(Estudiante* estudiante, const char* materia) {
    if (estudiante == NULL || materia == NULL) return;

    // Verificar si la materia está en la lista de materias disponibles
    if (!materiaDisponible(materia)) {
        fprintf(stderr, "Error: La materia '%s' no está disponible.\n", materia);
        return;
    }

    // Verificar si ya está inscrita
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            fprintf(stderr, "Error: La materia '%s' ya está inscrita.\n", materia);
            return;
        }
    }

    // Agregar la materia si hay espacio
    if (estudiante->numMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
    } else {
        fprintf(stderr, "Error: No se pueden inscribir más materias.\n");
    }
}

void eliminarMateria(Estudiante* estudiante, const char* materia) {
    if (estudiante == NULL || materia == NULL) return;

    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            // Desplazar las materias restantes hacia adelante
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }
    printf("La materia '%s' no está inscrita.\n", materia);
}

void mostrarMaterias(const Estudiante* estudiante) {
    if (estudiante == NULL) return;

    printf("Materias inscritas por %s:\n", estudiante->nombre);
    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("- %s\n", estudiante->materias[i]);
    }
}

// Métodos para gestionar asistencias
void registrarAsistencia(Estudiante* estudiante, const Asistencia* asistencia) {
    if (estudiante == NULL || asistencia == NULL) return;

    // Verificar si la materia está disponible
    if (!materiaDisponible(asistencia->materia)) {
        fprintf(stderr, "Error: La materia '%s' no está disponible.\n", asistencia->materia);
        return;
    }

    // Verificar si el estudiante está inscrito en la materia
    bool inscrito = false;
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], asistencia->materia) == 0) {
            inscrito = true;
            break;
        }
    }
    if (!inscrito) {
        fprintf(stderr, "Error: El estudiante no está inscrito en la materia '%s'.\n", asistencia->materia);
        return;
    }

    // Registrar la asistencia si hay espacio
    if (estudiante->numAsistencias < MAX_ASISTENCIAS) {
        estudiante->asistencias[estudiante->numAsistencias] = *asistencia;
        estudiante->numAsistencias++;
    } else {
        fprintf(stderr, "Error: No se pueden registrar más asistencias.\n");
    }
}

void mostrarAsistencias(const Estudiante* estudiante) {
    if (estudiante == NULL) return;

    printf("Registro de asistencias de %s:\n", estudiante->nombre);
    for (int i = 0; i < estudiante->numAsistencias; i++) {
        mostrarAsistencia(&estudiante->asistencias[i]);
    }
}

// Métodos para mostrar datos del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    if (estudiante == NULL) return;

    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
    mostrarMaterias(estudiante);
}

// Getters
const char* getNombre(const Estudiante* estudiante) {
    return estudiante ? estudiante->nombre : NULL;
}

int getEdad(const Estudiante* estudiante) {
    return estudiante ? estudiante->edad : -1;
}

float getPromedio(const Estudiante* estudiante) {
    return estudiante ? estudiante->promedio : -1;
}

// Setters
void setNombre(Estudiante* estudiante, const char* nuevoNombre) {
    if (estudiante == NULL || nuevoNombre == NULL || strlen(nuevoNombre) == 0) {
        fprintf(stderr, "Error: El nombre no puede estar vacío.\n");
        return;
    }
    strncpy(estudiante->nombre, nuevoNombre, MAX_NOMBRE - 1);
    estudiante->nombre[MAX_NOMBRE -
