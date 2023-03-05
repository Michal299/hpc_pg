#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int numberToCheck;
    int numberOfProcesses, myProcessRank;
    int currentDivider;
    int result, globalResult;

    // Parse the input
    if (argc < 2) {
        printf("Please enter the number to check if is prime.");
        return -1;
    }
    numberToCheck = atoi(argv[1]);

    // Init the MPI
    MPI_Init(&argc, &argv);
    
    // Get info about the world
    MPI_Comm_rank(MPI_COMM_WORLD, &myProcessRank);
    MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcesses);

    result = 0;
    currentDivider = 2 + myProcessRank;
    while (currentDivider < numberToCheck) {
        if (numberToCheck % currentDivider == 0) {
            result = 1;
            break;
        }

        currentDivider += numberOfProcesses;
    }

    
    MPI_Reduce(&result, &globalResult, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myProcessRank == 0) {
        printf("Number: %d; isPrime: %d\n", numberToCheck, !globalResult);
    }
    // Close the app properly
    MPI_Finalize();
    return 0;
}