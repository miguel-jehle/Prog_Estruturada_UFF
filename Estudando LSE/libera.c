#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

void libera_TLSE(TLSE* l){
    //Criamos o vetor que servirá como temporário
    TLSE* p = l;
    while(l){
        //Digo para o temporario apontar para o primeiro da lista a cada iteração
        p = l;
        //E mando l apontar para o seguinte
        l = l ->prox;
        //Então libero o antigo primeiro lugar
        free(p);
    }

}