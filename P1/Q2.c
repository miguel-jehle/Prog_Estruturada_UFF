/*A questão era simples, e pedia para que fizessemos uma função(portanto uma main) que recebesse um valor n,
e então uma sequência de n valores, para que retornassemos o "tamanho"da maior sequência de números crescente.
Contudo não poderiamos utilizar vetores nem nada além dos tipos primitivos(int,char,float,double) e seus operadores.*/
#include<stdio.h>

int main(void){
    int n;
    printf("Digite a quantidade de valores inteiros: ");
    scanf("%d", &n);

    int cont_local = 0;
    int cont_global = 0;
    int atual, ant = 0;

    for(int i = 0; i < n; i++){
        printf("Digite um valor inteiro: ");
        scanf("%d", &atual);
        if(atual < ant)cont_local = 0;
        cont_local++;
        if(cont_local > cont_global) cont_global = cont_local;
        ant = atual;
        printf("\n");
    }
    printf("A maior sequencia foi de %d numeros", cont_global);

    return 0;
}


