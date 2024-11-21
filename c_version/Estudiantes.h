//
// Created by alexa on 19/11/2024.
//

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Asistencia.h"
#include <stdbool.h> // Para manejar valores booleanos

#define MAX_MATERIAS 50
#define MAX_ASISTENCIAS 100
#define MAX_NOMBRE 100

// Definición de la estructura Estudiante
typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][50]; // Hasta 50 materias, con un nombre máximo de 49 caracteres
    int numMaterias;                 // Número actual de materias

    Asistencia asistencias[MAX_ASISTENCIAS]; // Lista de asistencias
    int numAsistencias;                      // Número actual de asistencias
} Estudiante;

// Prototipos de funciones
/**
 * @brief Inicializa un estudiante con sus datos básicos.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param nombre Nombre del estudiante.
 * @param edad Edad del estudiante.
 * @param promedio Promedio del estudiante.
 */
void initEstudiante(Estudiante* estudiante, const char* nombre, int edad, float promedio);

/**
 * @brief Agrega una materia al estudiante.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param materia Nombre de la materia a agregar.
 */
void agregarMateria(Estudiante* estudiante, const char* materia);

/**
 * @brief Elimina una materia del estudiante.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param materia Nombre de la materia a eliminar.
 */
void eliminarMateria(Estudiante* estudiante, const char* materia);

/**
 * @brief Muestra todas las materias del estudiante.
 *
 * @param estudiante Puntero constante a la estructura Estudiante.
 */
void mostrarMaterias(const Estudiante* estudiante);

/**
 * @brief Registra una asistencia para el estudiante.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param asistencia Puntero a la estructura Asistencia.
 */
void registrarAsistencia(Estudiante* estudiante, const Asistencia* asistencia);

/**
 * @brief Muestra todas las asistencias del estudiante.
 *
 * @param estudiante Puntero constante a la estructura Estudiante.
 */
void mostrarAsistencias(const Estudiante* estudiante);

/**
 * @brief Muestra los datos del estudiante (nombre, edad, promedio).
 *
 * @param estudiante Puntero constante a la estructura Estudiante.
 */
void mostrarEstudiante(const Estudiante* estudiante);

/**
 * @brief Obtiene el nombre del estudiante.
 *
 * @param estudiante Puntero constante a la estructura Estudiante.
 * @return const char* Nombre del estudiante.
 */
const char* getNombre(const Estudiante* estudiante);

/**
 * @brief Obtiene la edad del estudiante.
 *
 * @param estudiante Puntero constante a la estructura Estudiante.
 * @return int Edad del estudiante.
 */
int getEdad(const Estudiante* estudiante);

/**
 * @brief Obtiene el promedio del estudiante.
 *
 * @param estudiante Puntero constante a la estructura Estudiante.
 * @return float Promedio del estudiante.
 */
float getPromedio(const Estudiante* estudiante);

/**
 * @brief Establece el nombre del estudiante.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param nuevoNombre Nuevo nombre del estudiante.
 */
void setNombre(Estudiante* estudiante, const char* nuevoNombre);

/**
 * @brief Establece la edad del estudiante.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param nuevaEdad Nueva edad del estudiante.
 */
void setEdad(Estudiante* estudiante, int nuevaEdad);

/**
 * @brief Establece el promedio del estudiante.
 *
 * @param estudiante Puntero a la estructura Estudiante.
 * @param nuevoPromedio Nuevo promedio del estudiante.
 */
void setPromedio(Estudiante* estudiante, float nuevoPromedio);

#endif // ESTUDIANTE_H
