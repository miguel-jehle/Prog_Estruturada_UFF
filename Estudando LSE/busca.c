#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;


//FEITO POR MIM E PELA LU
int busca(TLSE *l, int x){
    //Criamos o contador de pos
    int resp = 0;
    //Criamos o ponteiro que irá percorrer a lista
    TLSE *p = l;
    //Percorremos o vetor até ele acabar ou achar o valor desejado, somando um valor ao resp para identificar a pos
    while((p) && p->info != x){
        p = p ->prox;
        resp++;
    }
    //Verificamos se o p é nulo, e retornamos ele caso seja
    if(!p) return -1;
    return resp;
}

