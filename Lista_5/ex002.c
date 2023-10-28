/*Q2) Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1
representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e
m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda
matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a
primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int
**mat2)*/

#include<stdio.h>
#include<stdlib.h>

int** mult (int lin1, int col1, int **mat1, int lin2, int col2, int
**mat2){
    //Criando a matriz resposta que será retornada usando alocação dinâmica
    int **resp = (int**)malloc(sizeof(int*)*lin1);


    for(int i = 0; i < col2; i++){
        resp[i] = (int*)malloc(sizeof(int)*col2);
    }

    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col2; j++){
            resp[i][j] = 0;
            for(int k = 0; k < col1; k++){
                 resp[i][j] += mat1[i][k]*mat2[k][j];
            }  
        }
    }

    return resp;
}

int main(){
    //Aqui analisa se col2 == lin1

    //recebendo matriz 1
    int lin1, col1, lin2, col2;
    scanf("%d", &lin1);
    scanf("%d", &col1);

    int **mat1 = (int**)malloc(sizeof(int*)*lin1);
    for(int i=0; i<col1; i++) mat1[i] = (int*)malloc(sizeof(int)*col1);

    for(int i=0; i<lin1; i++){
        for(int j=0; j<col1; j++) scanf("%d", &mat1[i][j]);
    }

    //recebendo matriz 2
    scanf("%d", &lin2);
    scanf("%d", &col2);

    int **mat2 = (int**)malloc(sizeof(int*)*lin2);
    for(int i=0; i<col1; i++) mat2[i] = (int*)malloc(sizeof(int)*col2);

    for(int i=0; i<lin2; i++){
        for(int j=0; j<col2; j++) scanf("%d", &mat2[i][j]);
    }

    //recebendo o vetor final
    int **resp = mult(lin1, col1, mat1, lin2, col2, mat2);

    for(int i=0; i< lin1; i++){
        for(int j=0; j< col2 ; j++){
            printf("%d ", resp[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < lin1; i++) free(mat1[i]);
    free(mat1);

    for (int i = 0; i < lin2; i++) free(mat2[i]);
    free(mat2);

    for(int i=0; i<lin1; i++) free(resp[i]);
    free(resp);

    return 0;
}