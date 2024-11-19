//
// Created by pinchiguillo on 19/11/2024.
//

#include <iostream>

#include "Estudiante.h"

int main() {
    // Creación de un objeto Estudiante
    Estudiante est1("Juan Pérez", 20, 8.5);

    // Gestión de materias
    est1.agregarMateria("Matemáticas");
    est1.agregarMateria("Física");
    est1.agregarMateria("Química");

    // Mostrar información del estudiante
    est1.mostrarEstudiante();

    // Registro de asistencias
    Asistencia asis1("2023-10-01", "Matemáticas", "Asistió");
    Asistencia asis2("2023-10-01", "Física", "Falta");
    Asistencia asis3("2023-10-02", "Química", "Tardanza");
    Asistencia asis4("2023-10-03", "Matemáticas", "Asistió");

    est1.registrarAsistencia(asis1);
    est1.registrarAsistencia(asis2);
    est1.registrarAsistencia(asis3);
    est1.registrarAsistencia(asis4);

    // Mostrar asistencias registradas
    std::cout << "\n";
    est1.mostrarAsistencias();

    // Confirmación de que Asistencia funciona
    std::cout << "\nPrueba individual de Asistencia:\n";
    asis1.mostrarAsistencia();
    asis2.mostrarAsistencia();
    asis3.mostrarAsistencia();
    asis4.mostrarAsistencia();

    return 0;
}