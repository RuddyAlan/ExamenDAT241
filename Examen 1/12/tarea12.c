#include <omp.h>
#include <stdio.h>

int main() {
    int n = 10;
    int fibonacci[n];

    #pragma omp parallel for shared(fibonacci)
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            fibonacci[i] = 0;
        else if (i == 1)
            fibonacci[i] = 1;
        else
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    // Imprime la serie
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci[i]);
    }

    return 0;
}
