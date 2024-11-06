#pragma once                     // Evita que el archivo se incluya m�ltiples veces en una sola compilaci�n
#include <vector>                // Incluye la biblioteca para usar el contenedor vector
#include <string>                // Incluye la biblioteca para usar cadenas de texto (string)
#include "Jugador.h"             // Incluye la definici�n de la clase Jugador
#include "Carta.h"               // Incluye la definici�n de la clase base Carta

using namespace std;

class Juego {                    // Define la clase principal Juego, que gestiona el flujo del juego
private:
    vector<Carta*> poolDeCartas; // Vector que almacena todas las cartas disponibles en el juego
    vector<Jugador> jugadores;   // Vector que almacena los jugadores en el juego

public:
    // Constructor que inicializa el juego con la cantidad de jugadores y sus nombres
    Juego(int cantidadJugadores, const vector<string>& nombres);

    // M�todo para generar el pool de cartas del juego
    void generarPoolDeCartas();

    // M�todo para repartir cartas a cada jugador desde el pool
    void repartirCartas();

    // M�todo para iniciar y gestionar el flujo completo del juego
    void iniciarJuego();

    // M�todo que representa el turno de un jugador espec�fico
    void turno(Jugador& jugador);

    // M�todo para verificar si alg�n jugador ha cumplido la condici�n de victoria
    bool verificarCondicionVictoria();

    // M�todo para mostrar el estado actual del juego en la consola
    void mostrarEstadoJuego() const;

    // M�todo para verificar si hay plantas en los jardines de los jugadores
    bool hayPlantasEnJardines() const;
};
