/*(Q5) Escreva uma função que dadas duas strings, retorne UM se a primeira contém a segunda,
ignorando maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: int
cic (char *str1, char *str2).*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void min(char*str){
    for(int i = 0; i < strlen(str); i++){
        if((int)str[i] >= 65 && (int)str[i] <= 90) str[i] = (char)((int)str[i] + 32);
    }

}

int cic (char *str1, char *str2){
    min(str1);
    min(str2);

    inicio = 0
    for(int i = 0; i < strlen(str2); i++){

    }
}