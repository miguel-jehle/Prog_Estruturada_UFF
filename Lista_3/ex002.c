//Enunciado

/*Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x2+ 2x + 12 terá um
vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x 3+x2
+ 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *derivada(int *n, int *vet){
    //Inicializando o contador
    int qntd_zero = 0;

    //Percorremos o vetor, derivando seus indices e ja contando os zeros
    for (int i = 0; i < *n+1; i++){
        vet[i] = vet[i] * i;
        if(vet[i] == 0) qntd_zero++; 
    }

    //Criamos um vetor novo, de menor tamanho, excluindo os zeros
    int *resp = (int*)malloc(sizeof(int)*(*n+1-qntd_zero));
    
    //Povoamos o novo vetor sem os zeros
    int j;
    for (int i = 0; i < (*n+1-qntd_zero); i++){
        if(vet[i] != 0){
            resp[j] = vet[i];
            j++;
            //ESTA BOMBA AQU!!! TA PEGANDO LIXO!!!!
        } 
    }
    //Tentamos usar artificio de ponteiro para retornar o tamanho do vetor e o vetor
    *n -= qntd_zero;
    return resp;
}

int main(){
    //Recebo grau pela primeira vez fora do while
    int grau;
    
    do{

        printf("Insira o grau do polinomio: ");
        scanf("%d\n", &grau);

        //Criando e povando o vetor
        int *polinomio = (int*)malloc(sizeof(int)*(grau+1));
        for (int i = 0; i < grau+1; i++){
            scanf("%d", &polinomio[i]);
        }
        
        int *vet_d = derivada(&grau, polinomio);

        //Printando, excluindo os zeros como no enunciado
        for (int i = 0; i < grau; i++){
            printf("%d ",vet_d[i]);
        }

        free(polinomio);
        free(vet_d);
    } while (grau > 0);
    
    return 0;
}
