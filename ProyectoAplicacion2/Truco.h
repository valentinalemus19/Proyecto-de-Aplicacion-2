#pragma once                   // Evita que el archivo se incluya múltiples veces en una sola compilación
#include "Carta.h"             // Incluye la definición de la clase base Carta

class Truco : public Carta {   // Define la clase Truco, que hereda de la clase Carta
private:
    string efecto;             // Almacena el tipo de efecto especial que tiene esta carta Truco

public:
    // Constructor que inicializa una carta de tipo Truco, con color "incoloro" y un efecto específico
    Truco(const string& efecto) : Carta("Truco", "incoloro"), efecto(efecto) {}

    // Implementación del método aplicarEfecto (vacío en este caso, ya que no tiene un efecto específico)
    void aplicarEfecto() override {
        // Aquí podría ir cualquier código relacionado con el efecto especial del truco,
        // pero actualmente está vacío.
    }
};
