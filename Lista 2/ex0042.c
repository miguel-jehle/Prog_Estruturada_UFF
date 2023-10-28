#include<stdio.h>
#include<stdlib.h>

int *ordena_vetor(int k, int* v){

    //Criando o vetor novo por meio do Malloc, para que o original não seja alterado
    int *vet_aux = (int*)malloc(sizeof(int)*k);

    // Copiando os elementos no vetor auxiliar
    for(int i = 0; i < k; i++){
        vet_aux[i] = v[i];
    }

    //Ordenando por meio do bubble sort
    for (int i = 0; i < k-1; i++){
        for (int j = 0; j < k-1-i; j++){
            if (v[j+1] > v[j]){
            int temp = vet_aux[j];
            vet_aux[j] = vet_aux[j+1];
            vet_aux[j+1] = temp;
            }
        }
    }
    return vet_aux;
}

int main(){
    //Declarando as variáveis
    int n;
    scanf("%d",&n);
    int vetor[n];
    int indice = 0;

    //Recebendo os valores armazenados no vetor
    for (int i = 0; i < n; i++){
        scanf("%d",&vetor[i]);
    }
    
    //Chamando a função para criar uma cópia do vetor ordenado
    int *vet_ord = ordena_vetor(n, vetor);

    //Agora que temos o vetor ordenado e o original, podemos encontrar o indice do segundo mais suspeito, e então comparar com o vetor original para encontramos seu índice na outra lista
    for (int i = 0; i < n; i++){
        if (vetor[i] == vet_ord[1]){
            indice = i + 1;
        }
    }
    //Agora que obtemos o indice do segundo mais suspeito na primeira lista, podemos printar
    printf("%d",indice);

    free(vet_ord);

    return 0;
}