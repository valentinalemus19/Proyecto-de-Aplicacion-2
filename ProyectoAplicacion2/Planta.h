#pragma once                   // Evita que el archivo se incluya m�ltiples veces en una sola compilaci�n
#include "Carta.h"             // Incluye la definici�n de la clase base Carta

class Planta : public Carta {  // Define la clase Planta, que hereda de la clase Carta
public:
    // Constructor que inicializa una carta de tipo Planta con un color espec�fico
    Planta(const string& color) : Carta("Planta", color) {}

    // Implementaci�n del m�todo aplicarEfecto (vac�o en este caso, ya que no tiene un efecto espec�fico)
    void aplicarEfecto() override {
        // Implementaci�n espec�fica de Planta si es necesario.
        // Aqu� podr�a ir cualquier c�digo relacionado con el efecto especial de la planta,
        // pero actualmente est� vac�o.
    }
};
