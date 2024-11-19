//
// Created by pinchiguillo on 19/11/2024.
//

#include <iostream>
#include <exception>

#include "Estudiante.h"
#include "materias.h"
#include "tests.cpp"

// Listado predefinido de materias
const std::vector<std::string> materiasDisponibles = {
    "Matemáticas", "Física", "Química", "Historia", "Arte", "Biología", "Literatura", "Inglés"
};

int main() {

    run_Tests();

    return 0;
}
