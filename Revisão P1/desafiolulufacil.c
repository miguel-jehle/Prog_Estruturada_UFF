#include<stdio.h>
#include<stdlib.h>

int *mat2vet(int **mat,int lin, int col){
    //Criando o vetor auxiliar que será retornado
    int *vet = (int*)malloc(sizeof(int)*lin*col);
    int indice = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            vet[indice] = mat[i][j];
            indice++;
        }
    }
    return vet;
}

int compara(const void *a, const void *b){
    int *num_1 = (int*)a;
    int *num_2 = (int*)b;

    if ((*num_1) < (*num_2)) return -1;
    if ((*num_1) > (*num_2)) return 1;
    return 0;
}

int main(void){
    int lin, col;

    printf("Digite o numero de linhas: \n");
    scanf("%d", &lin);

    printf("Digite o numero de colunas: \n");
    scanf("%d", &col);

    //Recebendo uma matriz
    int **mat = (int**)malloc(sizeof(int*)*lin);

    for(int i = 0; i<lin; i++){
        mat[i] = (int*)malloc(sizeof(int)*col);
    }

    printf("Digite os valores da matriz: \n");
    //Preenchendo a matriz
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int *vet_mat = mat2vet(mat, lin, col);

    qsort(vet_mat,lin*col,sizeof(int),compara);

    //Sobrescrevendo a matriz com o vetor ordenado
    int indice = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = vet_mat[indice];
            indice++;
        }
    }

    //Printando o vetor ordenado
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    //Desalocando
    for(int i = 0; i < lin; i++){
        free(mat[i]);
    }
    free(mat);
    free(vet_mat);

}