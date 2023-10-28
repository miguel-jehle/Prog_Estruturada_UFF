#include<stdio.h>
#include<math.h>

int inversor(int n, int d){
    int resto = n, resp = 0, pot1 = 0, pot2 = 1;
    for (int i = 0; i < d; i++)
    {
        resp += (resto/(int)(pow(10,(d-pot2)))) * (pow(10,pot1));
        resto = resto % (int)(pow(10,(d-pot2)));
        pot1++;
        pot2++;
    }
    printf("%d\n", resp);
    return resp;
}

int ver_digitos(int n){
    int cont = 1;
    while ((n / 10) != 0){
        n = n/10;
        cont += 1;
    } 
    return cont;
}

int main(){
    int num, inv, dig;
    printf("Insira o valor a ser verificado: ");
    scanf("%d", &num);
    dig = ver_digitos(num);
    inv = inversor(num,dig);
    if (num == inv){
        printf("VERDADEIRO");
    }else{
        printf("FALSO");
    }
    return 0;
}