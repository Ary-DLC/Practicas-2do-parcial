// Ejercicio 1: Jerarquia simple
// Clase base Vehiculo y dos derivadas: Auto y Motocicleta
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidadMax;

public:
    Vehiculo(string marca, string modelo, int velocidadMax)
        : marca(marca), modelo(modelo), velocidadMax(velocidadMax) {}

    virtual void mostrarInfo() const {
        cout << "Vehiculo: " << marca << " " << modelo
             << " | Vel. max: " << velocidadMax << " km/h" << endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int numPuertas;

public:
    Auto(string marca, string modelo, int velocidadMax, int numPuertas)
        : Vehiculo(marca, modelo, velocidadMax), numPuertas(numPuertas) {}

    void mostrarInfo() const override {
        cout << "[AUTO] " << marca << " " << modelo
             << " | Vel. max: " << velocidadMax << " km/h"
             << " | Puertas: " << numPuertas << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string marca, string modelo, int velocidadMax, int cilindrada)
        : Vehiculo(marca, modelo, velocidadMax), cilindrada(cilindrada) {}

    void mostrarInfo() const override {
        cout << "[MOTO] " << marca << " " << modelo
             << " | Vel. max: " << velocidadMax << " km/h"
             << " | Cilindrada: " << cilindrada << " cc" << endl;
    }
};

int main() {
    cout << "=== Ejercicio 1: Jerarquia simple ===" << endl;

    Vehiculo v("Generico", "Base", 100);
    Auto a("Toyota", "Corolla", 180, 4);
    Motocicleta m("Yamaha", "R3", 190, 321);

    v.mostrarInfo();
    a.mostrarInfo();
    m.mostrarInfo();

    return 0;
}
