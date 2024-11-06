#include "Jugador.h"    // Incluye la definición de la clase Jugador
#include <iostream>     // Incluye la biblioteca para imprimir en la consola

void Jugador::mostrarMano() const {
    // Muestra las cartas en la mano del jugador en formato visual
    cout << "\n=== Mano de " << nombre << " ===" << endl;  // Encabezado con el nombre del jugador
    for (size_t i = 0; i < mano.size(); ++i) {             // Recorre cada carta en la mano
        cout << " [" << i << "] ";                         // Muestra el índice de la carta
        cout << "| Tipo: " << mano[i]->getTipo()           // Muestra el tipo de la carta
            << " | Color: " << mano[i]->getColor() << " |"; // Muestra el color de la carta
        cout << endl;
    }
    cout << "======================" << endl;               // Línea para separar la sección
}

void Jugador::mostrarJardin() const {
    // Muestra las cartas en el jardín del jugador en formato visual
    cout << "\n=== Jardín de " << nombre << " ===" << endl; // Encabezado con el nombre del jugador
    for (size_t i = 0; i < jardin.size(); ++i) {            // Recorre cada carta en el jardín
        cout << " [" << i << "] ";                          // Muestra el índice de la carta
        cout << "| Tipo: " << jardin[i]->getTipo()          // Muestra el tipo de la carta
            << " | Color: " << jardin[i]->getColor() << " |"; // Muestra el color de la carta
        cout << endl;
    }
    cout << "======================" << endl;               // Línea para separar la sección
}

void Jugador::eliminarCartaDeMano(int index) {
    // Elimina una carta de la mano del jugador según el índice dado
    if (index >= 0 && index < mano.size()) {                // Verifica que el índice sea válido
        mano.erase(mano.begin() + index);                   // Elimina la carta en la posición indicada
    }
}
