//(1) Escreva uma função em C que transforme uma matriz num vetor: int *mat2vet(int **mat, int lin, int col);

#include<stdio.h>
#include<stdlib.h>

int *mat2vet(int **mat, int lin, int col){
    int indice = 0;
    int *vetor = (int*)malloc(sizeof(int)*lin*col);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            vetor[indice] = mat[i][j];
            indice++;
        }
    }
    return vetor;
}

