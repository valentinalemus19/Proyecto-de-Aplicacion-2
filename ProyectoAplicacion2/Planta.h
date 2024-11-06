#pragma once                   // Evita que el archivo se incluya múltiples veces en una sola compilación
#include "Carta.h"             // Incluye la definición de la clase base Carta

class Planta : public Carta {  // Define la clase Planta, que hereda de la clase Carta
public:
    // Constructor que inicializa una carta de tipo Planta con un color específico
    Planta(const string& color) : Carta("Planta", color) {}

    // Implementación del método aplicarEfecto (vacío en este caso, ya que no tiene un efecto específico)
    void aplicarEfecto() override {
        // Implementación específica de Planta si es necesario.
        // Aquí podría ir cualquier código relacionado con el efecto especial de la planta,
        // pero actualmente está vacío.
    }
};
