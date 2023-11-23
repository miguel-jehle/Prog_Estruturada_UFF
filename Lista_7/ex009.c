/*Q9) Implemente uma função em C que, dadas duas listas, faça a concatenação das
mesmas ao final de l1. O protótipo da função é o seguinte: TLSE* junta_listas (TLSE*
l1, TLSE* l2).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE* junta_listas (TLSE*l1, TLSE* l2){
    //Vamos encontrar o ultimo nó da primeira lista
    TLSE* ult_l1 = l1;
    while(ult_l1->prox) ult_l1 = ult_l1 ->prox;

    //Com o final da primeira encontrado basta este apontar para onde l2 aponta
    ult_l1 ->prox = l2;

    return l1;
}

int main(void){
  TLSE *l1 = TLSE_inicializa();
  TLSE *l2 = TLSE_inicializa();
  int x,y;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l1 = TLSE_insere(l1, x);
  }while(1);
  do{
    scanf("%d", &y);
    if(y < 0) break;
    l2 = TLSE_insere(l2, y);
  }while(1);
  printf("As listas originais: ");
  TLSE_imprime(l1);
  printf(" e ");
  TLSE_imprime(l2);
  printf("\n");
  

  TLSE* resp = junta_listas(l1,l2);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(resp);
  

  TLSE_libera(l1);

  return 0;
}

