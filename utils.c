// create array
// delete array

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int n)
{
    int *(*matrix);	
    int *arr[n]; 

    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));

        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        memset(arr, 0, sizeof *arr * n);
    }

    matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy the addresses of the rows from arr to matrix
    for (int i = 0; i < n; i++) {
        matrix[i] = arr[i];
    }

    return matrix;
}


void delete_matrix(int **matrix, int n) 
{
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }

    free(matrix);
}
