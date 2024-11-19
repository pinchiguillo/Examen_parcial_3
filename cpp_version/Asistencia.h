//
// Created by pinchiguillo on 19/11/2024.
//

#ifndef ASISTENCIA_H
#define ASISTENCIA_H

#include <string>
#include <iostream>

class Asistencia {
private:
    std::string fecha;
    std::string materia;
    std::string estado; // "Asistió", "Falta", "Tardanza"

public:
    // Constructor
    Asistencia(const std::string& fecha, const std::string& materia, const std::string& estado);

    // Método para mostrar la asistencia
    void mostrarAsistencia() const;

    // Getters
    const std::string& getFecha() const;
    const std::string& getMateria() const;
    const std::string& getEstado() const;
};

#endif // ASISTENCIA_H
