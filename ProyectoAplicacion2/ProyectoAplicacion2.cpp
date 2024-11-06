#include "Juego.h"               // Incluye la definición de la clase Juego
#include <iostream>              // Incluye la biblioteca para manejo de entrada y salida en consola

using namespace std;

int main() {                     // Función principal del programa
    int cantidadJugadores;       // Variable para almacenar la cantidad de jugadores
    vector<string> nombres;      // Vector para almacenar los nombres de los jugadores

    // Solicita al usuario la cantidad de jugadores (entre 2 y 4)
    cout << "Ingrese la cantidad de jugadores (2-4): ";
    cin >> cantidadJugadores;

    // Ciclo para obtener los nombres de cada jugador
    for (int i = 0; i < cantidadJugadores; ++i) {
        string nombre;           // Variable temporal para almacenar el nombre de cada jugador
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> nombre;
        nombres.push_back(nombre); // Agrega el nombre al vector de nombres
    }

    // Crea un objeto de la clase Juego, inicializándolo con la cantidad de jugadores y sus nombres
    Juego juego(cantidadJugadores, nombres);

    // Genera el pool de cartas que estarán disponibles para el juego
    juego.generarPoolDeCartas();

    // Reparte cartas a cada jugador desde el pool generado
    juego.repartirCartas();

    // Inicia el juego, gestionando los turnos y el flujo general del juego
    juego.iniciarJuego();

    return 0;                    // Finaliza el programa
}
