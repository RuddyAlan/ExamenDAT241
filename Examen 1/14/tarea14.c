#include <mpi.h>
#include <stdio.h>

#define N 2

void multiMatrices(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];

    if (rank == 0) {
        // Enviar matrices A y B a los otros procesos
        for (int i = 1; i < size; i++) {
            MPI_Send(&A, N*N, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&B, N*N, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        // Multiplicar matrices en el proceso 0
        multiMatrices(A, B, C);
        printf("Proceso %d: Matriz C:\n", rank);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    } else {
        // Recibir matrices A y B
        MPI_Recv(&A, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&B, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // Multiplicar matrices en otros procesos
        multiMatrices(A, B, C);
        printf("Proceso %d: Matriz C:\n", rank);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}
