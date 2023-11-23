/*Q4) Implemente uma função que copie uma lista. A lista original deve permanecer
inalterada. O protótipo da função é o seguinte: TLSE *copia (TLSE *l).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE *copia (TLSE *l){
     //Vamos copiar o vetor para não alterar o original, usando um auxiliar que irá receber as informações invertidas e então inverter ela
    TLSE* l_aux = NULL;
    TLSE* aux = l;
    while(aux){
      TLSE* no_aux = (TLSE*)malloc(sizeof(TLSE));
      no_aux -> info = aux->info;
      no_aux ->prox = l_aux;
      l_aux = no_aux;
      aux = aux->prox;
    }

    //Com ela toda copiada , mas invertida, basta passar pra outra, que será nossa cópia de fato
    TLSE* copia = NULL;
    TLSE* aux_2 = l_aux;
    while(aux_2){
      TLSE* no_copia = (TLSE*)malloc(sizeof(TLSE));
      no_copia -> info = aux_2 -> info;
      no_copia -> prox = copia;
      copia = no_copia;
      aux_2 = aux_2 ->prox;
    }
    return copia;
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

  TLSE* copiada = copia(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(copiada);

  TLSE_libera(l);
  TLSE_libera(copiada);

  return 0;
}