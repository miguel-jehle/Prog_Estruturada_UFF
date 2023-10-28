#include <stdio.h>
#include <stdlib.h>

void ordena(int *vetor, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(vetor[j+1] < vetor[j]){
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main(void){
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor1[n], vetor2[n];

    printf("Digite o vetor1: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vetor1[i]);
    }

    printf("Digite o vetor2: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vetor2[i]);
    }

    ordena(vetor1, n);
    ordena(vetor2, n);

    for(int i=0; i<n; i++){
        if (vetor1[i] != vetor2[i]){
            printf("Nao sao anagramas");
            return 0;
        }
    }

    printf("E anagrama");

    return 0;
}