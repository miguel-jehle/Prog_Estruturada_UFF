//Q1) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
//um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
//solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
//somente uma vez).

#include<stdio.h>
#include<stdlib.h>

int cont_dig(int **mat){
    int lin = 9;
    int col = 9;
    //Vetor auxiliar que vai servir como contador de cada digito
    int vet_cont[9] = {0,0,0,0,0,0,0,0,0};
    
    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            vet_cont[mat[i][j]-1] += 1;
        }
    }
    for(int i = 0; i < 9; i++){
        if (vet_cont[i] != 9) return 0;
    }
    return 1;
}

int sum_linha(int **mat, int lin){
    int soma = 0;
    for(int i = 0; i < 9;  i++){
        soma +=  mat[lin][i];
    }
    return soma;
}



int sum_col(int **mat, int col){
    int soma = 0;
    for(int i = 0; i < 9; i++){
        soma += mat[i][col];
    }
    return soma;
}




int ver_soma(int **mat){
    for(int i = 0; i < 9; i++){
        if (sum_linha(mat,i) != 45) return 0;
    }

    for(int i = 0; i < 9; i++){
        if (sum_col(mat,i) != 45) return 0;
    }

    return 1;
}

int main(){
    //Criando as linhas
    int ** mat;
    int lin = 9, col = 9;
    mat = (int**) malloc (sizeof(int*)*lin);

    //Criando as colunas de cada linha
    for (int i = 0; i < lin; i++){
        mat[i] = (int*)malloc(sizeof(int)* col);
    }

    //Populando 
    for (int i = 0; i < lin; i++){
        for( int j = 0; j < lin; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    if (cont_dig(mat)){
        int resp = ver_soma(mat);
        if (resp) printf("E solucao");
        else printf("Nao e solucao");

    }else{
        printf("Nao e solucao");
    }

    //Desalocando
    for (int i = 0; i < lin; i++){
        free(mat[i]);
    }

    free(mat);

    return 0;
}