#include <stdio.h>
#include "ProcessUserArray.h"

void ProcessUserArray(int* array, int size)
{
    int i = 0;
    for (i = 0; i < size - 1; i++) if (array[i]%3==0) array[i] = 1;
}

void OutputArray(int* array, int size) {
    int i = 0;
    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
}

