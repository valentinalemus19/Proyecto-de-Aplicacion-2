#pragma once               // Asegura que el archivo solo se incluya una vez por compilaci�n
#include <string>          // Incluye la biblioteca para usar cadenas de texto (string)

using namespace std;

class Carta {               // Clase base para representar una carta gen�rica
protected:
    string tipo;            // Almacena el tipo de la carta (por ejemplo, "Planta", "Hongo", etc.)
    string color;           // Almacena el color de la carta (por ejemplo, "rojo", "amarillo", etc.)

public:
    // Constructor que inicializa el tipo y color de la carta
    Carta(const string& tipo, const string& color) : tipo(tipo), color(color) {}

    // Destructor virtual: se asegura de que se llame al destructor correcto en clases derivadas
    virtual ~Carta() {}

    // Funci�n que devuelve el tipo de la carta
    string getTipo() const { return tipo; }

    // Funci�n que devuelve el color de la carta
    string getColor() const { return color; }

    // Funci�n virtual pura para aplicar el efecto de la carta
    // Esto obliga a las clases derivadas (como "Planta" o "Hongo") a definir c�mo funciona su efecto
    virtual void aplicarEfecto() = 0;
};
