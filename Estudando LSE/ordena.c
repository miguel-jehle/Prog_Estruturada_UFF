#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inicializa.c>
#include<inserir_ini.c>

typedef struct lse{
    int info;
    struct lse *prox;
} TLSE;

//USAMOS SELECTION SORT
TLSE* ordenada(TLSE*l, int x){
    //Criamos o prmeiro vetor que funcionará como "i"
    TLSE*p = l;
    //p começa no primeiro e percorre enquanto ele existir(não chegar no nulo) e irá andando pelo p->prox
    for(p = l; p; p = p->prox){
        //Crio o q que funcionará como "j" na mesma logica do "i", mas que sempre é incializado uma posição após  i para otimizar
        TLSE* menor = p;
        for(TLSE* q = p->prox; q; q = q-> prox ){
            //Se vemos que o valor percorrido for menor, que o valor menor salvo, o ponteiro menor apontára para este menor encontrado
            if(q->info < menor -> info) menor = q;
        }
        //Verificamos se o menor já não está na primeira posição para otimizar
        if(menor != p){
            //Caso não, faremos a troca, para jogar a menor informação para o primeiro nó
            int temp = p -> info;
            p -> info = menor -> info;
            menor ->info = temp;
        }
    }
    return l;
}