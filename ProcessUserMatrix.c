#include <stdio.h>
#include "math.h"
#include "ProcessUserMatrix.h"

void ProcessUserMatrix(int *matrix, int sizeA, int sizeB)
{
    int i = 0, j = 0;

    for (i = 0; i < sizeA; i++) 
        for (j = 0; j < sizeB; j++) 
            if (*(matrix+i*sizeB+j) % 3 == 0) *(matrix + i * sizeB + j) = 1;
}

void OutputMatrix(const int *matrix, int sizeA, int sizeB) {
    int i = 0, j = 0;

    for (i = 0; i < sizeA; i++) {
        printf("\n");
        for (j = 0; j < sizeB; j++)
            printf("%d\t", *(matrix + i * sizeB + j));
    }
}