#include "stdio.h"

// Función para sumar
void suma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}

// Función para restar
void resta(int *a, int *b, int *resultado) {
    *resultado = *a - *b;
}

// Función para multiplicar
void multiplica(int *a, int *b, int *resultado) {
    *resultado = *a * *b;
}

// Función para dividir
void divide(int *a, int *b, int *resultado) {
    if (*b != 0) {
        *resultado = *a / *b;
    } else {
        printf("Error: División por cero no es permitida.\n");
        *resultado = 0;
    }
}

void main() {
    int num1 = 10, num2 = 5;
    int resultado;

    suma(&num1, &num2, &resultado);
    printf("Suma: %d\n", resultado);

    resta(&num1, &num2, &resultado);
    printf("Resta: %d\n", resultado);

    multiplica(&num1, &num2, &resultado);
    printf("Multiplicación: %d\n", resultado);

    divide(&num1, &num2, &resultado);
    printf("División: %d\n", resultado);

}