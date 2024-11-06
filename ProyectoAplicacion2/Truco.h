#pragma once                   // Evita que el archivo se incluya m�ltiples veces en una sola compilaci�n
#include "Carta.h"             // Incluye la definici�n de la clase base Carta

class Truco : public Carta {   // Define la clase Truco, que hereda de la clase Carta
private:
    string efecto;             // Almacena el tipo de efecto especial que tiene esta carta Truco

public:
    // Constructor que inicializa una carta de tipo Truco, con color "incoloro" y un efecto espec�fico
    Truco(const string& efecto) : Carta("Truco", "incoloro"), efecto(efecto) {}

    // Implementaci�n del m�todo aplicarEfecto (vac�o en este caso, ya que no tiene un efecto espec�fico)
    void aplicarEfecto() override {
        // Aqu� podr�a ir cualquier c�digo relacionado con el efecto especial del truco,
        // pero actualmente est� vac�o.
    }
};
