#include<stdio.h>
#include<stdlib.h>

int contador(int k, int *vetor){

    int cont_max = 0;

    for (int i = 0; i < k; i++){
        int cont = 0;
        for (int j = i+1; j < k ; j++){
            if (vetor[i] != -1){
                if (vetor[i] == vetor[j]){
                    cont++;
                    vetor[j] = -1;
                    
                }
            }   
        }
        if (cont > 0) cont_max++;
    }
    return cont_max;
}

int main(){
    int n;
    int m;
    
    do{
    scanf("%d", &n);
    scanf("%d", &m);

    int vetor[m];
    for (int i = 0; i < m; i++){
        scanf("%d", &vetor[i]);
    }

    int valor = contador(m, vetor);

    printf("%d",valor);

    scanf("%d", &n);
    scanf("%d", &m);
    } while (m != 0 || n != 0);
    
    return 0;
}