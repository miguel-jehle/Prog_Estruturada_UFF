#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

TLSE * ins_ord(TLSE* l, int x){
    //Se for nula ou só tiver um único elemento, insere no início
    if((!l) || (l->info > x)) return ins_ini_TLSE(l,x);

    //Criamos dois ponteiros para percorrer, pois eles nos ajudarão a inserir no meio da lista
    TLSE* ant = NULL;
    TLSE* p = l;

    //Percorremos a LSE até encontrar a posição ideal para inserir o nó
    while(p->info <= x){
        ant = p;
        p = p->prox;
    }

    //Quando encontramos esta posição, vamos criar o novo nó, e então manda-lo apontar para onde p está e mandar o nó anterior apontar para o novo
    TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
    novo -> info = x;
    novo -> prox = p;
    ant-> prox =  novo;

    return l;
}