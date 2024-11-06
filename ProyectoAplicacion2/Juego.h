#pragma once                     // Evita que el archivo se incluya múltiples veces en una sola compilación
#include <vector>                // Incluye la biblioteca para usar el contenedor vector
#include <string>                // Incluye la biblioteca para usar cadenas de texto (string)
#include "Jugador.h"             // Incluye la definición de la clase Jugador
#include "Carta.h"               // Incluye la definición de la clase base Carta

using namespace std;

class Juego {                    // Define la clase principal Juego, que gestiona el flujo del juego
private:
    vector<Carta*> poolDeCartas; // Vector que almacena todas las cartas disponibles en el juego
    vector<Jugador> jugadores;   // Vector que almacena los jugadores en el juego

public:
    // Constructor que inicializa el juego con la cantidad de jugadores y sus nombres
    Juego(int cantidadJugadores, const vector<string>& nombres);

    // Método para generar el pool de cartas del juego
    void generarPoolDeCartas();

    // Método para repartir cartas a cada jugador desde el pool
    void repartirCartas();

    // Método para iniciar y gestionar el flujo completo del juego
    void iniciarJuego();

    // Método que representa el turno de un jugador específico
    void turno(Jugador& jugador);

    // Método para verificar si algún jugador ha cumplido la condición de victoria
    bool verificarCondicionVictoria();

    // Método para mostrar el estado actual del juego en la consola
    void mostrarEstadoJuego() const;

    // Método para verificar si hay plantas en los jardines de los jugadores
    bool hayPlantasEnJardines() const;
};
