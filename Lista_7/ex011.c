/*Q11) Defina uma função em C que, dada uma lista l qualquer, ordene os elementos de l
em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O
protótipo da função desta função é o seguinte: TLSE * ordena (TLSE* l).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE * ordena (TLSE* l){
    //Como não podereos alterar a original precisaremos fazer uma copia desta
    TLSE* l_ord = TLSE_copia(l);

    for(TLSE*p = l_ord; p; p = p->prox){
        TLSE* menor = p;
        for(TLSE*q = p->prox; q; q = q ->prox){
            if(menor -> info > q ->info) menor = q;
        }
        if(menor != p){
        int tmp = p -> info;
        p -> info = menor ->info;
        menor -> info = tmp;
        }
    }
    return l_ord;
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  TLSE* resp = ordena(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(resp);

  TLSE_libera(l);
  TLSE_libera(resp);

  return 0;
}