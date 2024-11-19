//
// Created by pinchiguillo on 19/11/2024.
//

#include <iostream>

#include "Asistencia.h"

int main() {

    // Registro de asistencias
    Asistencia asis1("2023-10-01", "Matemáticas", "Asistió");
    Asistencia asis2("2023-10-01", "Física", "Falta");
    Asistencia asis3("2023-10-02", "Química", "Tardanza");
    Asistencia asis4("2023-10-03", "Matemáticas", "Asistió");

    // Confirmación de que Asistencia funciona
    std::cout << "\nPrueba individual de Asistencia:\n";
    asis1.mostrarAsistencia();
    asis2.mostrarAsistencia();
    asis3.mostrarAsistencia();
    asis4.mostrarAsistencia();

    return 0;
}