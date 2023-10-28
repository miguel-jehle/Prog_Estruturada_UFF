#include <stdio.h>
#include <stdlib.h>

int* ins_antes_depois_x(int *vet, int n, int x, int *tam_vet_resposta){
    int i,j;
    
    for( j=0; j<n; j++){
            if (vet[j] == x){
                (*tam_vet_resposta) += 2;
            }
        }

    int *vet_novo = (int*)malloc(sizeof(int)*(*tam_vet_resposta));
    
    j = 0;
    for(i=0; i< n; i++){
        if (vet[i] != x){
            vet_novo[j] = vet[i]; j++;
        }else{
            vet_novo[j] = (x-1);
            vet_novo[j+1] = x;
            vet_novo[j+2] = (x+1);
            j += 3;
        }
    }
    return vet_novo;
}

int main(){
    int numero, x;

    printf("Digite o tamanho do vetor original: ");
    scanf("%d", &numero);
    
    if(numero > 0){
        int vetor[numero];
        
        printf("Digite o vetor original: ");
        for(int i=0; i<numero; i++){
            scanf("%d", &vetor[i]);
        }
        
        printf("Digite o X: ");
        scanf("%d", &x);
        
        int tam_novo = numero;
        
        int *resp = ins_antes_depois_x(vetor, numero, x, &tam_novo);
        
        // depois de já ter o vetor novo
        
        int i;
        for(i=0; i<tam_novo; i++){
            printf("%d ", resp[i]);
        }
        
        free(resp);
        
    }
}