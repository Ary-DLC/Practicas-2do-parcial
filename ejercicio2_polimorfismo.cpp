// Ejercicio 2: Polimorfismo en accion
// Arreglo de punteros a Vehiculo que mezcla Autos y Motocicletas
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
    cout << "=== Ejercicio 2: Polimorfismo en accion ===" << endl;

    const int N = 4;
    Vehiculo* vehiculos[N] = {
        new Auto("Toyota", "Corolla", 180, 4),
        new Motocicleta("Yamaha", "R3", 190, 321),
        new Auto("Mazda", "MX-5", 210, 2),
        new Motocicleta("Honda", "CB500F", 185, 471)
    };

    // Todos son tratados como Vehiculo*, pero cada uno responde distinto
    for (int i = 0; i < N; i++) {
        vehiculos[i]->mostrarInfo();
    }

    for (int i = 0; i < N; i++) {
        delete vehiculos[i];
    }

    return 0;
}
