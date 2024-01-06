#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compara(const void *a, const void *b){
    char *letra_1 = (char*)a;
    char *letra_2 = (char*)b;

    if(strcmp(letra_1,letra_2) < 0) return -1;
    if(strcmp(letra_1,letra_2) > 0) return 1;
    return 0;
}

int main(){
    //Recebendo a palavra
    char str[50];
    printf("Digite a string para ordenar: ");
    scanf("%s", str);

    qsort(str,strlen(str),sizeof(char),compara);

    printf("A string ordenada ficou assim: %s", str);

    return 0;
}