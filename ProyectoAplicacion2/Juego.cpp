#include "Juego.h"      // Incluye la definición de la clase Juego
#include "Planta.h"     // Incluye la definición de la carta Planta
#include "Hongo.h"      // Incluye la definición de la carta Hongo
#include "Fungicida.h"  // Incluye la definición de la carta Fungicida
#include "Truco.h"      // Incluye la definición de la carta Truco
#include <iostream>     // Biblioteca para entrada y salida en consola
#include <algorithm>    // Biblioteca para usar el shuffle
#include <random>       // Biblioteca para generar números aleatorios

using namespace std;

Juego::Juego(int cantidadJugadores, const vector<string>& nombres) {
    // Agrega cada jugador a la lista de jugadores usando sus nombres
    for (const auto& nombre : nombres) {
        jugadores.emplace_back(nombre);
    }
}

void Juego::generarPoolDeCartas() {
    // Añade diferentes cartas al pool (mazo general) con colores y tipos específicos
    for (int i = 0; i < 4; ++i) {
        poolDeCartas.push_back(new Planta("rojo"));
        poolDeCartas.push_back(new Planta("amarillo"));
        poolDeCartas.push_back(new Planta("azul"));
    }
    for (int i = 0; i < 10; ++i) poolDeCartas.push_back(new Hongo(1));   // Agrega hongos de grado 1
    for (int i = 0; i < 5; ++i) poolDeCartas.push_back(new Hongo(2));    // Agrega hongos de grado 2
    for (int i = 0; i < 3; ++i) poolDeCartas.push_back(new Hongo(3));    // Agrega hongos de grado 3 (fatal)
    for (int i = 0; i < 3; ++i) poolDeCartas.push_back(new Fungicida()); // Agrega fungicidas
    for (int i = 0; i < 3; ++i) poolDeCartas.push_back(new Truco("trasplantar")); // Truco para trasplantar
    for (int i = 0; i < 2; ++i) poolDeCartas.push_back(new Truco("intercambio")); // Truco para intercambio

    // Mezcla el pool de cartas para asegurar aleatoriedad
    random_device rd;
    mt19937 g(rd());
    shuffle(poolDeCartas.begin(), poolDeCartas.end(), g);

    // Muestra las cartas en el pool (opcional, solo para verificar)
    cout << "Pool de cartas generado:\n";
    for (const auto& carta : poolDeCartas) {
        cout << "- " << carta->getTipo() << " (" << carta->getColor() << ")\n";
    }
    cout << endl;
}

void Juego::repartirCartas() {
    // Reparte 4 cartas a cada jugador desde el pool de cartas
    for (auto& jugador : jugadores) {
        for (int i = 0; i < 4 && !poolDeCartas.empty(); ++i) {
            jugador.agregarCartaAMano(poolDeCartas.back()); // Añade la carta a la mano del jugador
            poolDeCartas.pop_back(); // Remueve la carta del pool
        }
    }
}

void Juego::turno(Jugador& jugador) {
    // Maneja el turno de un jugador, permitiendo jugar o pasar
    cout << "Turno de " << jugador.getNombre() << endl;
    jugador.mostrarJardin(); // Muestra el jardín del jugador
    jugador.mostrarMano();   // Muestra la mano del jugador

    int opcion;
    do {
        cout << "Seleccione una acción:\n";
        cout << "1. Jugar una carta\n";
        cout << "2. Pasar turno\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            // Elige y juega una carta de la mano
            cout << "Selecciona la carta a jugar (0 - " << jugador.getMano().size() - 1 << "): ";
            int cartaIndex;
            cin >> cartaIndex;
            if (cartaIndex >= 0 && cartaIndex < jugador.getMano().size()) {
                Carta* carta = jugador.getMano()[cartaIndex];
                cout << "Jugando carta de tipo " << carta->getTipo() << " con color " << carta->getColor() << endl;
                jugador.agregarCartaAJardin(carta); // Mueve la carta al jardín
                jugador.eliminarCartaDeMano(cartaIndex); // La elimina de la mano
            }
        }
    } while (opcion != 1 && opcion != 2); // Continúa hasta que elija jugar o pasar

    // Reabastece la mano del jugador si tiene menos de 4 cartas
    while (jugador.getMano().size() < 4 && !poolDeCartas.empty()) {
        jugador.agregarCartaAMano(poolDeCartas.back());
        poolDeCartas.pop_back();
    }
    cout << "Presiona enter para continuar";
    cin.ignore();
    cin.get();
}

void Juego::iniciarJuego() {
    // Inicia el juego y alterna turnos hasta que alguien gane
    bool juegoTerminado = false;
    int turnoActual = 0;

    while (!juegoTerminado) {
        mostrarEstadoJuego(); // Muestra el estado de todos los jugadores
        turno(jugadores[turnoActual]); // Turno del jugador actual
        if (verificarCondicionVictoria()) {
            juegoTerminado = true; // Termina el juego si alguien gana
        }
        turnoActual = (turnoActual + 1) % jugadores.size(); // Cambia al siguiente jugador
    }
    cout << "Juego terminado." << endl;
}

bool Juego::verificarCondicionVictoria() {
    // Verifica si algún jugador tiene 3 plantas de colores diferentes en su jardín
    for (const auto& jugador : jugadores) {
        int rojo = 0, amarillo = 0, azul = 0;
        for (const auto& carta : jugador.getJardin()) {
            if (carta->getColor() == "rojo") rojo = 1;
            if (carta->getColor() == "amarillo") amarillo = 1;
            if (carta->getColor() == "azul") azul = 1;
        }
        if (rojo + amarillo + azul == 3) {
            cout << "¡El jugador " << jugador.getNombre() << " ha ganado!" << endl;
            return true;
        }
    }
    return false;
}

void Juego::mostrarEstadoJuego() const {
    // Muestra el estado actual de los jugadores y el pool de cartas
    cout << "\n--- Estado del Juego ---\n";
    cout << "Cartas restantes en el pool: " << poolDeCartas.size() << endl;
    for (const auto& jugador : jugadores) {
        cout << "Jugador: " << jugador.getNombre() << endl;
        jugador.mostrarJardin(); // Muestra las plantas en el jardín del jugador
        jugador.mostrarMano();   // Muestra las cartas en la mano del jugador
    }
    cout << "------------------------\n";
}

bool Juego::hayPlantasEnJardines() const {
    // Verifica si hay plantas en el jardín de algún jugador
    for (const auto& jugador : jugadores) {
        if (!jugador.getJardin().empty()) {
            return true;
        }
    }
    return false;
}
