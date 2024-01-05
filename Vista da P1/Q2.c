#include<stdio.h>

int main(void){
    int n;
    printf("Digite a quantidade de valores inteiros: ");
    scanf("%d", &n);

    while(n >= 0){
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
    printf("A maior sequencia foi de %d numeros\n", cont_global);

    int n;
    printf("Digite a quantidade de valores inteiros: ");
    scanf("%d", &n);

    return 0;
    }

    
}