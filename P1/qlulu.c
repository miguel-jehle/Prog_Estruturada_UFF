#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *resp = (int **mat, int linha, int coluna){
    int ver=1, cont=0;
    int soma;
    int *aux = (int*)malloc(sizeof(int)*5);
    for(int i=0; i<5; i++) aux[i] = 0;

    //1° habilidade (nenhum aluno pode acertar tudo)
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[i][j];
        }
        if(soma == 3){
            ver =0;
            break;
        }
    }
    if (ver){
        aux[1] = 1;
        cont++;
    }

    //2° habilidade (nenhum pode errar tudo)
    ver = 1;
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[i][j];
        }
        if(soma == 0){
            ver =0;
            break;
        }
    }
    if (ver){
        aux[2] = 2;
        cont++;
    }

    //3° habilidade (nenhum problema pode ser resolvido por todos)
    ver = 1;
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[j][i];
        }
        if(soma == 3){
            ver =0;
            break;
        }
    }
    if (ver){
        aux[3] = 3;
        cont++;
    }

    //4° habilidade (nenhum problema pode ficar sem solução)
    ver = 1;
    for(int i=0; i<linha; i++){
        soma =0;
        for(int j=0; j<coluna; j++){
            soma += mat[j][i];
        }
        if(soma == 3){
            ver =0;
            break;
        }
    }
    if (ver){
        aux[4] = 4;
        cont++;
    }

    aux[0] = cont;
    int indice=0;

    int *resp = (int*)malloc(sizeof(int)*cont);
    for(int i=0; i<5; i++){
        if(aux[i] != 0){
            resp[indice] = aux[i];
            indice++;
        }
    }
    

    for(int i=0; i<5; i++) free(aux[i]);
    free(aux);
    

    return resp;
}



int main(){
    int linha, coluna;

    printf("Quantidade de linhas: ");
    scanf("%d", &linha);
    printf("Quantidade de colunas: ");
    scanf("%d", &coluna);

    int **vet = (int**)malloc(sizeof(int*)*linha);
    for(int i=0; i<linha; i++) vet[i] = (int*)malloc(sizeof(int)*coluna);

    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            scanf("%d", &vet[i][j]);
        }
    }

    int *result = resp(vet, linha, coluna);

    for(int i=0; i<result[0]; i++) printf("%d ", result[i]);

    return 0;
}