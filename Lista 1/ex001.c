#include<stdio.h>
#include<math.h>

int eh_primo (int valor){
    int div = 0;
    for ( int j = valor; j > 0; j--){
        if (valor % j == 0){
            div++;
        }
        if (div > 2){
            return 0;
        }
    }
    if (div == 2){
        return 1;
    } 
}

int main(){
    int num, cont = 0;
    
     printf("Insira a quantidade de primos que deseja que sejam imprimidos: ");
     scanf("%d",&num);
    while (num > 0){
        for (int i = 2; cont < num; i++){
            if (eh_primo(i) == 1){
                printf("%d ", i);
                cont++;
            }
        }
        printf("Insira a quantidade de primos que deseja que sejam imprimidos: ");
        scanf("%d \n",&num);
        cont = 0;
    }
    return 0;
}