//
// Created by pinchiguillo on 19/11/2024.
//

#include "tests.h"

#include <iostream>
#include <exception>

#include "Estudiante.h"

bool display_debug = false;
#define DPRINT(x) if(display_debug) { x; }

void run_Tests() {

    bool all_pased = true;

    // Caso de prueba 1: Estudiante con materias y asistencias normales
    std::cout << "================= CASO DE PRUEBA 1 =================\n";
    try {
        Estudiante est1("Juan Pérez", 20, 8.5);
        est1.agregarMateria("Matemáticas");
        est1.agregarMateria("Física");
        est1.agregarMateria("Química");
        DPRINT(est1.mostrarEstudiante();)

        Asistencia asis1("2023-10-01", "Matemáticas", "Asistió");
        Asistencia asis2("2023-10-02", "Física", "Falta");
        est1.registrarAsistencia(asis1);
        est1.registrarAsistencia(asis2);
        DPRINT(est1.mostrarAsistencias();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 2: Estudiante sin materias ni asistencias
    std::cout << "\n================= CASO DE PRUEBA 2 =================\n";
    try {
        Estudiante est2("María López", 19, 9.0);
        DPRINT(est2.mostrarEstudiante();)
        DPRINT(est2.mostrarMaterias();) // Asumiendo que existe este método

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 3: Estudiante con nota extrema
    std::cout << "\n================= CASO DE PRUEBA 3 =================\n";
    try {
        Estudiante est3("Carlos García", 21, 11.0);
        est3.agregarMateria("Historia");
        DPRINT(est3.mostrarEstudiante();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 4: Registro de asistencia a materia no agregada
    std::cout << "\n================= CASO DE PRUEBA 4 =================\n";
    try {
        Estudiante est4("Ana Martínez", 22, 7.5);
        Asistencia asis3("2023-10-03", "Biología", "Asistió");
        est4.registrarAsistencia(asis3);
        DPRINT(est4.mostrarAsistencias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 5: Estudiante con muchas materias
    std::cout << "\n================= CASO DE PRUEBA 5 =================\n";
    try {
        Estudiante est5("Luis Fernández", 23, 6.5);
        for (int i = 1; i <= 50; ++i) {
            est5.agregarMateria("Materia " + std::to_string(i));
        }
        DPRINT(est5.mostrarMaterias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test passed: " << e.what() << "\n";
    }

    // Caso de prueba 6: Asistencias en fechas no consecutivas
    std::cout << "\n================= CASO DE PRUEBA 6 =================\n";
    try {
        Estudiante est6("Laura Gómez", 20, 8.0);
        est6.agregarMateria("Inglés");
        Asistencia asis4("2023-10-05", "Inglés", "Asistió");
        Asistencia asis5("2023-10-10", "Inglés", "Falta");
        est6.registrarAsistencia(asis4);
        est6.registrarAsistencia(asis5);
        DPRINT(est6.mostrarAsistencias();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 7: Estudiante con caracteres especiales en el nombre
    std::cout << "\n================= CASO DE PRUEBA 7 =================\n";
    try {
        Estudiante est7("José Álvarez-Ñ", 24, 7.2);
        est7.agregarMateria("Arte");
        DPRINT(est7.mostrarEstudiante();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 8: Fecha mal puesta en asistencia
    std::cout << "\n================= CASO DE PRUEBA 8 =================\n";
    try {
        Estudiante est8("Lucía Pérez", 19, 8.0);
        est8.agregarMateria("Biología");
        Asistencia asis6("2023-13-40", "Biología", "Asistió"); // Fecha inválida
        est8.registrarAsistencia(asis6);
        DPRINT(est8.mostrarAsistencias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 9: Materia que no existe en el registro de asistencia
    std::cout << "\n================= CASO DE PRUEBA 9 =================\n";
    try {
        Estudiante est9("Miguel Torres", 21, 7.8);
        est9.agregarMateria("Química");
        Asistencia asis7("2023-10-04", "Física", "Asistió"); // Materia no agregada
        est9.registrarAsistencia(asis7);
        DPRINT(est9.mostrarAsistencias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 10: Edad negativa
    std::cout << "\n================= CASO DE PRUEBA 10 ================\n";
    try {
        Estudiante est10("Ana González", -5, 9.0); // Edad negativa
        DPRINT(est10.mostrarEstudiante();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 11: Promedio negativo
    std::cout << "\n================= CASO DE PRUEBA 11 ================\n";
    try {
        Estudiante est11("Pedro López", 20, -3.5); // Promedio negativo
        DPRINT(est11.mostrarEstudiante();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 12: Promedio superior al máximo permitido
    std::cout << "\n================= CASO DE PRUEBA 12 ================\n";
    try {
        Estudiante est12("Sofía Ruiz", 22, 12.0); // Promedio superior a 10
        DPRINT(est12.mostrarEstudiante();)

        std::cout << "Test passed.\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        all_pased = false;
    }

    // Caso de prueba 13: Nombre vacío
    std::cout << "\n================= CASO DE PRUEBA 13 ================\n";
    try {
        Estudiante est13("", 20, 8.0); // Nombre vacío
        DPRINT(est13.mostrarEstudiante();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 14: Agregar materia duplicada
    std::cout << "\n================= CASO DE PRUEBA 14 ================\n";
    try {
        Estudiante est14("Diego Martínez", 21, 7.0);
        est14.agregarMateria("Programación");
        est14.agregarMateria("Programación"); // Materia duplicada
        DPRINT(est14.mostrarMaterias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 15: Registrar asistencia sin materias agregadas
    std::cout << "\n================= CASO DE PRUEBA 15 ================\n";
    try {
        Estudiante est15("Elena Sánchez", 20, 8.5);
        Asistencia asis8("2023-10-05", "Matemáticas", "Asistió");
        est15.registrarAsistencia(asis8); // Sin materias agregadas
        DPRINT(est15.mostrarAsistencias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 16: Asistencia con estado inválido
    std::cout << "\n================= CASO DE PRUEBA 16 ================\n";
    try {
        Estudiante est16("Fernando Díaz", 23, 6.5);
        est16.agregarMateria("Filosofía");
        Asistencia asis9("2023-10-06", "Filosofía", "Ausente"); // Estado no reconocido
        est16.registrarAsistencia(asis9);
        DPRINT(est16.mostrarAsistencias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 17: Fecha de asistencia vacía
    std::cout << "\n================= CASO DE PRUEBA 17 ================\n";
    try {
        Estudiante est17("Laura Moreno", 19, 7.5);
        est17.agregarMateria("Geografía");
        Asistencia asis10("", "Geografía", "Asistió"); // Fecha vacía
        est17.registrarAsistencia(asis10);
        DPRINT(est17.mostrarAsistencias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    // Caso de prueba 18: Materia con nombre vacío
    std::cout << "\n================= CASO DE PRUEBA 18 ================\n";
    try {
        Estudiante est18("Roberto Jiménez", 22, 8.0);
        est18.agregarMateria(""); // Nombre de materia vacío
        DPRINT(est18.mostrarMaterias();)

        std::cout << "Test failed.\n";
        all_pased = false;
    } catch (const std::exception& e) {
        std::cout << "Test pased: " << e.what() << "\n";
    }

    if (all_pased) {
        std::cout << "\nTodos los tests pasaron correctamente.\n" << std::endl;
    }

}