// Ejercicio 4: Sobrecarga de metodos
// Clase Calculadora con tres versiones de sumar()
#include <iostream>
using namespace std;

class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }

    int sumar(int a, int b, int c) {
        return a + b + c;
    }

    double sumar(double a, double b) {
        return a + b;
    }
};

int main() {
    cout << "=== Ejercicio 4: Sobrecarga de metodos ===" << endl;

    Calculadora calc;

    cout << "sumar(5, 7)        = " << calc.sumar(5, 7) << endl;
    cout << "sumar(3, 4, 10)    = " << calc.sumar(3, 4, 10) << endl;
    cout << "sumar(2.5, 3.75)   = " << calc.sumar(2.5, 3.75) << endl;

    return 0;
}
