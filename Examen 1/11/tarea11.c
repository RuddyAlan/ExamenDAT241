#include "mpi.h"
#include "stdio.h"

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int vector1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vector2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(vector1) / sizeof(vector1[0]);
    int sum = 0;

    if (world_rank == 0) {
        // Procesador 0: Maestro
        int sum_impares, sum_pares;
        MPI_Send(vector1, n, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(vector2, n, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(vector2, n, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(vector1, n, MPI_INT, 2, 0, MPI_COMM_WORLD);
        
    } else if (world_rank == 1) {
        // Procesador 1: Suma posiciones impares
        MPI_Recv(vector1, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(vector2, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int res[];
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0) {
                res[i] = vector1[i] + vector2[i];
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d\n", res[i]);
        }
        
    } else if (world_rank == 2) {
        // Procesador 2: Suma posiciones pares
        MPI_Recv(vector1, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(vector2, n, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int res[];
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                res[i] = vector1[i] + vector2[i];
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d\n", res[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
