# Prácticas 2do parcial – Herencia y polimorfismo (C++)

**Materia:** Programación Orientada a Objetos – UAG
**Profesor:** Manuel Balderas Victoria
**Alumna:** Ary Gabriela De La Cruz Peralta (5188130)

Cinco ejercicios que van de una jerarquía simple de clases hasta colecciones polimórficas recorridas con iteradores.

| # | Ejercicio | Tema |
|---|-----------|------|
| 1 | [Jerarquía simple](ejercicio1_jerarquia/) | Clase base `Vehiculo` y derivadas `Auto` y `Motocicleta` con `mostrarInfo()` sobrescrito |
| 2 | [Polimorfismo en acción](ejercicio2_polimorfismo/) | Arreglo de `Vehiculo*` que mezcla autos y motos; cada objeto responde distinto |
| 3 | [Sobrecarga de operadores](ejercicio3_fraccion/) | Clase `Fraccion` con `+` (suma) y `==` (equivalencia) |
| 4 | [Sobrecarga de métodos](ejercicio4_calculadora/) | Clase `Calculadora` con tres versiones de `sumar()` |
| 5 | [Colección con iterador](ejercicio5_iterador/) | `std::vector<Vehiculo*>` recorrido con `iterator` |

## Cómo compilar y ejecutar

Cada ejercicio es un solo archivo `.cpp`. Desde la carpeta del ejercicio:

```bash
g++ -std=c++11 -Wall ejercicio1_jerarquia.cpp -o ejercicio1
./ejercicio1
```

(Cambia el nombre del archivo según el ejercicio.)
