#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

TLSE* retira(TLSE* l, int x){
    //Inicializamos os vetores que irão percorrer 
    TLSE* ant = NULL;
    TLSE* p = l;
    //Enquanto não encontramos o valor ou a lista acabar, continuamos percorrendo
    while((p->info != x) && (p)){
        ant = p;
        p = p-> prox;
    }
    //
    //Se chegou no final, e não achou o valor, retorna l e um bj
    if(!p) return l;
    //Se ant for nulo, so existia um valor e ele foi removido, então precisamos que l aponte para nulo para n dar ruim
    if(!ant) l = l->prox;
    //Se n tivermos nenhum desses casos, mando o ant do nó que será excluido apontar para o seguinte ao mesmo e ai sim podemos apagar ele
    else ant -> prox = p -> prox;
    free(p);

    return l;
}