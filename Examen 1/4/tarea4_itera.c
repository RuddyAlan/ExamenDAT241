#include "stdio.h"

void calculo_pi(int iteraciones, double *pi) {
    double denominador = 1.0;
    int signo = 1;
    *pi = 0.0;

    for (int i = 0; i < iteraciones; i++) {
        *pi += signo * (4.0 / denominador);
        denominador += 2.0;
        signo = -signo;
    }
}

int main() {
    int iteraciones;
    printf("Ingrese el número de iteraciones: ");
    scanf("%d", &iteraciones);

    double pi;
    calculo_pi(iteraciones, &pi);

    printf("El valor aproximado de pi es: %f\n", pi);

    return 0;
}
