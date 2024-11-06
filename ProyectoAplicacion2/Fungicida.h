#pragma once                    // Evita que el archivo se incluya múltiples veces en una sola compilación
#include "Carta.h"              // Incluye la definición de la clase base Carta

class Fungicida : public Carta { // Define la clase Fungicida, que hereda de la clase Carta
public:
    // Constructor que inicializa una carta de tipo Fungicida con un color "incoloro"
    Fungicida() : Carta("Fungicida", "incoloro") {}

    // Implementación del método aplicarEfecto (vacío en este caso, ya que no tiene un efecto específico)
    void aplicarEfecto() override {
        // Aquí podría ir cualquier código relacionado con el efecto especial del fungicida,
        // pero actualmente está vacío.
    }
};
