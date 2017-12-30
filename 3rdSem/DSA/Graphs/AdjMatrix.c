#include <stdio.h>
#include <stdlib.h>

int **adjMatrix;

void createMatrix(int);
void printMatrix(int);
void addConnection(int, int);

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createMatrix(n);
    int vertex1, vertex2;
    int repeat;
    while (repeat){
        printf("enter vertex1: ");
        scanf("%d", &vertex1);
        printf("enter vertex2: ");
        scanf("%d", &vertex2);
        addConnection(vertex1, vertex2);
        scanf("%d", &repeat);
    }

    printMatrix(n);
    printf("\n");
    return 0;
}

void createMatrix(int n){
    adjMatrix = (int **)malloc(sizeof(int *)*n);
    int i;
    for (i = 0; i < n; i++){
        adjMatrix[i] = (int *)malloc(sizeof(int)*n);
    }
    int j;
    for (i = 0; i < n; i++){
        for (j = 0 ; j < n; j++){
           adjMatrix[i][j] = 0;
        }
        printf("\n");
    }
}

void printMatrix(int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0 ; j < n; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void addConnection(int vertex1, int vertex2){
    adjMatrix[vertex1][vertex2] = 1;
    adjMatrix[vertex2][vertex1] = 1;
}