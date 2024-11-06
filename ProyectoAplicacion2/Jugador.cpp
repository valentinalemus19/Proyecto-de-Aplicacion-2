#include "Jugador.h"    // Incluye la definici�n de la clase Jugador
#include <iostream>     // Incluye la biblioteca para imprimir en la consola

void Jugador::mostrarMano() const {
    // Muestra las cartas en la mano del jugador en formato visual
    cout << "\n=== Mano de " << nombre << " ===" << endl;  // Encabezado con el nombre del jugador
    for (size_t i = 0; i < mano.size(); ++i) {             // Recorre cada carta en la mano
        cout << " [" << i << "] ";                         // Muestra el �ndice de la carta
        cout << "| Tipo: " << mano[i]->getTipo()           // Muestra el tipo de la carta
            << " | Color: " << mano[i]->getColor() << " |"; // Muestra el color de la carta
        cout << endl;
    }
    cout << "======================" << endl;               // L�nea para separar la secci�n
}

void Jugador::mostrarJardin() const {
    // Muestra las cartas en el jard�n del jugador en formato visual
    cout << "\n=== Jard�n de " << nombre << " ===" << endl; // Encabezado con el nombre del jugador
    for (size_t i = 0; i < jardin.size(); ++i) {            // Recorre cada carta en el jard�n
        cout << " [" << i << "] ";                          // Muestra el �ndice de la carta
        cout << "| Tipo: " << jardin[i]->getTipo()          // Muestra el tipo de la carta
            << " | Color: " << jardin[i]->getColor() << " |"; // Muestra el color de la carta
        cout << endl;
    }
    cout << "======================" << endl;               // L�nea para separar la secci�n
}

void Jugador::eliminarCartaDeMano(int index) {
    // Elimina una carta de la mano del jugador seg�n el �ndice dado
    if (index >= 0 && index < mano.size()) {                // Verifica que el �ndice sea v�lido
        mano.erase(mano.begin() + index);                   // Elimina la carta en la posici�n indicada
    }
}
