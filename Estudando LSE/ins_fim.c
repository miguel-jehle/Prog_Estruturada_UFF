#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

TLSE* ins_fim(TLSE* l, int x){
    //Verificamos se a lsta está vazia, caso esteja, basta inserir no inicio
    if (!l) return ins_ini_TLSE(l,x);
    //Criamos um outro ponteiro para percorrer a lista com ele, pois não percorremos com o "l" para n perder o inicio
    TLSE *p = l;
    //Usamos um loop para percorrer todo o vetor, enquanto o seguinte a ele for diferente de nulo, o ponteiro irá para o próximo
    while(p->prox) p = p->prox;
    //Criamos o novo nó
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    //Fazemos o antigo ultimo apontar para o novo criadp
    p -> prox = novo;
    //Preenchemos o campo de informação
    novo -> info = x;
    //Fazemos o novo criado, agora como ultimo, apontar para NULL
    novo ->prox = NULL;
    //Realizamos o retorno para o l apontar para a lista modificada
    return l;
}