#include "stdio.h"

// Función para sumar
int suma(int a, int b) {
    return a + b;
}

// Función para restar
int resta(int a, int b) {
    return a - b;
}

// Función para multiplicar
int multiplica(int a, int b) {
    return a * b;
}

// Función para dividir
int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero no es permitida.\n");
        return 0;
    }
}

void main()
{
    int num1 = 10, num2 = 5;

    printf("Suma: %d\n", suma(num1, num2));
    printf("Resta: %d\n", resta(num1, num2));
    printf("Multiplicación: %d\n", multiplica(num1, num2));
    printf("División: %d\n", divide(num1, num2));
}