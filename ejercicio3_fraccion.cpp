// Ejercicio 3: Sobrecarga de operadores
// Clase Fraccion con operador + (suma) y == (equivalencia)
#include <iostream>
using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;

    static int mcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void simplificar() {
        int d = mcd(numerador, denominador);
        if (d != 0) {
            numerador /= d;
            denominador /= d;
        }
        if (denominador < 0) {   // signo siempre en el numerador
            numerador = -numerador;
            denominador = -denominador;
        }
    }

public:
    Fraccion(int num = 0, int den = 1) : numerador(num), denominador(den) {
        if (denominador == 0) {
            cout << "Error: denominador 0, se usa 1" << endl;
            denominador = 1;
        }
        simplificar();
    }

    // a/b + c/d = (ad + cb) / bd
    Fraccion operator+(const Fraccion& otra) const {
        int num = numerador * otra.denominador + otra.numerador * denominador;
        int den = denominador * otra.denominador;
        return Fraccion(num, den);
    }

    // a/b == c/d  si  a*d == c*b
    bool operator==(const Fraccion& otra) const {
        return numerador * otra.denominador == otra.numerador * denominador;
    }

    void mostrar() const {
        cout << numerador << "/" << denominador;
    }
};

int main() {
    cout << "=== Ejercicio 3: Sobrecarga de operadores ===" << endl;

    Fraccion f1(1, 2);
    Fraccion f2(1, 3);
    Fraccion suma = f1 + f2;

    f1.mostrar(); cout << " + "; f2.mostrar(); cout << " = "; suma.mostrar();
    cout << endl;

    Fraccion f3(2, 4);
    Fraccion f4(3, 5);

    f1.mostrar(); cout << " == "; f3.mostrar();
    cout << " ? " << (f1 == f3 ? "Si, son equivalentes" : "No son equivalentes") << endl;

    f1.mostrar(); cout << " == "; f4.mostrar();
    cout << " ? " << (f1 == f4 ? "Si, son equivalentes" : "No son equivalentes") << endl;

    return 0;
}
