//Enunciado: 

/*Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o
método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2
e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscam-
se todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se
encontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos
à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A
figura seguinte apresenta o método para n = 40.*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    //Inicializando variaveis
    int n;
    scanf("%d", &n);
    int *vet = (int*)malloc(sizeof(int)*(n-1));

    //Povoando o vetor
    for (int i = 2; i < n; i++){
        vet[i-2] = i;
    }

    //Aplicando o algortimo por meio da troca dos elementos multiplos por um valor inadequado "-1"
    for (int i = 0; i < n-1; i++){
        if (vet[i] != 1){
            for (int j = i+1; j < n-2; j++){
                if (vet[j] % vet[i] == 0){
                    vet[j] = 1;
                }
            }   
        }
    }
    //printando o vetor todo, exceto os valores 1
    for (int i = 0; i < n-2; i++){
        if (vet[i] != 1){
            printf("%d\n", vet[i]);
        } 
    }
    free(vet);
    return 0;
}