#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int procesador, t;
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &t);

    int vector_t = 10;
    char vector[vector_t] = {
        "dato0", "dato1", "dato2", "dato3", "dato4",
        "dato5", "dato6", "dato7", "dato8", "dato9"
    };

    if (procesador == 0) {
        // Procesador 0 envía el vector a los otros procesadores
        MPI_Send(vector, vector_t, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Send(vector, vector_t, MPI_CHAR, 2, 0, MPI_COMM_WORLD);
    } else if (procesador == 1) {
        // Procesador 1 recibe el vector y despliega posiciones pares
        char recv_vector[vector_t];
        MPI_Recv(recv_vector, vector_t, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Procesador 1 - Posiciones pares:\n");
        for (int i = 0; i < vector_t; i += 2) {
            printf("%s\n", recv_vector[i]);
        }
    } else if (procesador == 2) {
        // Procesador 2 recibe el vector y despliega posiciones impares
        char recv_vector[vector_t];
        MPI_Recv(recv_vector, vector_t, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Procesador 2 - Posiciones impares:\n");
        for (int i = 1; i < vector_t; i += 2) {
            printf("%s\n", recv_vector[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
