#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

//Aqui nós criamos um novo nó, que será preenchido com a info no parametro, e apontará para onde antes l apontava, e então retornamos, para que l aponte para esse novo nó que agora se encontra no começo
TLSE * ins_ini_TLSE(TLSE *l, int x){
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    novo -> info = x;
    novo -> prox = l;
    return novo;
}

//Inicializamos chamando a função criada no outro arquivo e chamamos a função de ins ini passando como parâmetro l e a info dsejada
int main(){
    TLSE *l = ini_TLSE();
    l = ins_ini_TLSE(l,5);
}