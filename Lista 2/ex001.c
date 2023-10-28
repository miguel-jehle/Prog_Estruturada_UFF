#include <stdio.h>
#include <math.h>

/*Função para obter a quantidade de dígitos que o valor inserido tem*/
int ver_digitos(int num){
    int cont = 1;
    while ((num / 10) != 0){
        num = num/10;
        cont += 1;
    } 
    return cont;
}

int main(){
   int n, dig, a, z,resp1, resp2;
   printf("Insira o valor a ser verificado: ");
   scanf("%d", &n);
   dig = ver_digitos(n);

    /*Vamos obter os dois últimos digitos e os dois primeiros*/
    a = n / (int)pow(10,dig-2);
    z = n % 100;

    /*Concatenado*/
    resp1 = (a*100) + z;

    /*Quadrado da soma*/
    resp2 = (a+z)*(a+z);

    /*Verficação para resposta final*/
    if (resp1 == resp2){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}