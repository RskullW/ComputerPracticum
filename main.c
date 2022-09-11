#include <stdio.h>
#include <windows.h>
#include <time.h>
#define A 76
#define Ba 5
#define Bb 6

void LoadRun(const char* const s, int i, int* array, int *matrix, int size, int sizeA, int sizeB);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int array[A], matrix[Ba][Bb], i = 0, j = 0;
    
    printf("Array[%d] =  ", A);
    
    for (i = 0; i < A; i++) {
        array[i] = rand() % 101 - 50;
        printf("%d ", array[i]);
    }
    
    printf("\n\nMatrix[%d][%d]\n", Ba, Bb);
    
    for (i = 0; i < Ba; i++) {
        
        for (j = 0; j < Bb; j++) {
            matrix[i][j] = rand() % 101 - 50;
            printf("%d\t", matrix[i][j]);
        }
        
        printf("\n");
    }
    
    i = 0;
    
    while (i != 5)
    {
        printf("\n1-set array\n2-set matrix\n3 - output array\n4 - output matrix\n5-exit\n");
        scanf_s("%d", &i);
        
        switch (i) {
            case 1:
                LoadRun("ProcessUserArray.dll", i, array, (int *) matrix, A, Ba, Bb);
                break;
            case 2:
                LoadRun("ProcessUserMatrix.dll", i, array, (int *) matrix, A, Ba, Bb);
                break;
            case 3:
                LoadRun("ProcessUserArray.dll", i, array, (int *) matrix, A, Ba, Bb);
                break;
            case 4: 
                LoadRun("ProcessUserMatrix.dll", i, array, (int *) matrix, A, Ba, Bb);
                break;
            default:
                break;
        }
    }
    
    return 0;
}


void LoadRun(const char* const s, int i, int* array, int *matrix, int size, int sizeA, int sizeB)   {

    void* lib;
    void (*fun1)(int* array, int size);
    void (*fun2)(int *matrix, int sizeA, int sizeB);
    lib = LoadLibrary(s);
    
    if (!lib) {
        printf("cannot open library '%s'\n", s);
        return;
    }
    
    if (i == 1) {

        fun1 = (void (*)(int* array, int size))GetProcAddress((HINSTANCE)lib, "ProcessUserArray");

        if (fun1 == NULL) {
            printf("cannot load function \n");
        }
        else {
            fun1(array, size);
        }
    }
    else if (i == 2) {

        fun2 = (void (*)(int *matrix, int sizeA, int sizeB))GetProcAddress((HINSTANCE)lib, "ProcessUserMatrix");

        if (fun2 == NULL) {
            printf("cannot load function \n");
        }
        else {
            fun2(matrix, sizeA, sizeB);
        }
    }
    
    else if (i ==3) {
        fun1 = (void (*)(int* array, int size))GetProcAddress((HINSTANCE)lib, "OutputArray");

        if (fun1 == NULL) {
            printf("cannot load function \n");
        }
        else {
            fun1(array, size);
        }
    }

    else if (i == 4) {

        fun2 = (void (*)(int *matrix, int sizeA, int sizeB))GetProcAddress((HINSTANCE)lib, "OutputMatrix");

        if (fun2 == NULL) {
            printf("cannot load function \n");
        }
        else {
            fun2(matrix, sizeA, sizeB);
        }
    }

    FreeLibrary((HINSTANCE)lib);
}