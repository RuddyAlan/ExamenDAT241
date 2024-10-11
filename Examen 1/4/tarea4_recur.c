#include <stdio.h>

void pi_recursivo(int iteracion, int max_iteraciones, double *pi, double denominador, int signo)
{
    if (iteracion < max_iteraciones) {
        *pi += signo * (4.0 / denominador);
        pi_recursivo(iteracion + 1, max_iteraciones, pi, denominador + 2.0, -signo);
    }
}

int main() {
    int iteraciones;
    printf("Ingrese el número de iteraciones: ");
    scanf("%d", &iteraciones);

    double pi = 0.0;
    pi_recursivo(0, iteraciones, &pi, 1.0, 1);

    printf("El valor aproximado de pi es: %f\n", pi);

    return 0;
}
