#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

//Aqui inicizlizamos a lista de forma a criar somente o ponteiro "l", que sempre apontará para o primeiro elemento da nossa LSE
TLSE * ini_TLSE(void){
    return NULL;
}

int main(){
    TLSE *l = ini_TLSE();
    return 0;
}