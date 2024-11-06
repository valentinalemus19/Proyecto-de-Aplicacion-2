#pragma once                   // Evita que el archivo se incluya m�ltiples veces en una sola compilaci�n
#include "Carta.h"             // Incluye la definici�n de la clase base Carta

class Hongo : public Carta {   // Define la clase Hongo, que hereda de la clase Carta
private:
    int grado;                 // Atributo para almacenar el grado del hongo (1, 2 o fatal)

public:
    // Constructor que inicializa una carta de tipo Hongo, con color incoloro y un grado espec�fico
    Hongo(int grado) : Carta("Hongo", "incoloro"), grado(grado) {}

    // Implementaci�n del m�todo aplicarEfecto (vac�o en este caso, ya que no tiene un efecto espec�fico)
    void aplicarEfecto() override {
        // Aqu� podr�a ir cualquier c�digo relacionado con el efecto especial del hongo,
        // pero actualmente est� vac�o.
    }

    // M�todo para obtener el grado del hongo
    int getGrado() const { return grado; }
};
