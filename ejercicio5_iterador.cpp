// Ejercicio 5: Coleccion con iterador
// vector de Vehiculo* recorrido con un iterador del lenguaje
#include <iostream>
#include <string>
#include <vector>
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
    cout << "=== Ejercicio 5: Coleccion con iterador ===" << endl;

    vector<Vehiculo*> flota;
    flota.push_back(new Auto("Nissan", "Versa", 175, 4));
    flota.push_back(new Motocicleta("Italika", "FT150", 110, 150));
    flota.push_back(new Auto("Volkswagen", "Jetta", 200, 4));
    flota.push_back(new Motocicleta("Kawasaki", "Ninja 400", 190, 399));
    flota.push_back(new Auto("Ford", "Mustang", 250, 2));

    // Recorrido con iterador
    int i = 1;
    for (vector<Vehiculo*>::iterator it = flota.begin(); it != flota.end(); ++it) {
        cout << i++ << ". ";
        (*it)->mostrarInfo();
    }

    // Liberar memoria
    for (vector<Vehiculo*>::iterator it = flota.begin(); it != flota.end(); ++it) {
        delete *it;
    }
    flota.clear();

    return 0;
}
