#pragma once                   // Evita que el archivo se incluya múltiples veces en una sola compilación
#include "Carta.h"             // Incluye la definición de la clase base Carta

class Hongo : public Carta {   // Define la clase Hongo, que hereda de la clase Carta
private:
    int grado;                 // Atributo para almacenar el grado del hongo (1, 2 o fatal)

public:
    // Constructor que inicializa una carta de tipo Hongo, con color incoloro y un grado específico
    Hongo(int grado) : Carta("Hongo", "incoloro"), grado(grado) {}

    // Implementación del método aplicarEfecto (vacío en este caso, ya que no tiene un efecto específico)
    void aplicarEfecto() override {
        // Aquí podría ir cualquier código relacionado con el efecto especial del hongo,
        // pero actualmente está vacío.
    }

    // Método para obtener el grado del hongo
    int getGrado() const { return grado; }
};
