#pragma once                      // Evita que el archivo se incluya múltiples veces en una sola compilación
#include <vector>                 // Incluye la biblioteca para usar el contenedor vector
#include <string>                 // Incluye la biblioteca para usar cadenas de texto (string)
#include "Carta.h"                // Incluye la definición de la clase base Carta

using namespace std;

class Jugador {                   // Define la clase Jugador, que representa a cada jugador en el juego
private:
    string nombre;                // Nombre del jugador
    vector<Carta*> mano;          // Vector que almacena las cartas en la mano del jugador
    vector<Carta*> jardin;        // Vector que almacena las cartas en el jardín del jugador

public:
    // Constructor que inicializa al jugador con un nombre específico
    Jugador(const string& nombre) : nombre(nombre) {}

    // Devuelve el nombre del jugador
    const string& getNombre() const { return nombre; }

    // Agrega una carta a la mano del jugador
    void agregarCartaAMano(Carta* carta) { mano.push_back(carta); }

    // Agrega una carta al jardín del jugador
    void agregarCartaAJardin(Carta* carta) { jardin.push_back(carta); }

    // Muestra las cartas en la mano del jugador
    void mostrarMano() const;

    // Muestra las cartas en el jardín del jugador
    void mostrarJardin() const;

    // Devuelve un vector con las cartas en la mano del jugador
    const vector<Carta*>& getMano() const { return mano; }

    // Devuelve un vector con las cartas en el jardín del jugador
    const vector<Carta*>& getJardin() const { return jardin; }

    // Elimina una carta de la mano según el índice
    void eliminarCartaDeMano(int index);
};
