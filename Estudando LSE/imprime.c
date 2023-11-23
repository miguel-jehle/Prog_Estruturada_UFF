#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

void imprime(TLSE* l){
    //Criamos o ponteiro que vai percorrer a lista e printamos todos os valores que ele percorrer até ele chegar no NULL
    TLSE* p = l;
    while(p){
        print("%d", p->info);
        p = p ->prox;
    }
}