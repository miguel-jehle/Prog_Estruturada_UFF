/*Q5) Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
Seu protótipo O protótipo desta função é o seguinte: TLSE* rto (TLSE* l, int elem).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE* rto (TLSE* l, int elem){
    //ALGORÍTIMO DA FUNÇÃO DE FATO
    TLSE*ant = NULL;
    TLSE*p = l;
    while(p){
        ant = ant-> prox;
        p = p->prox;
        if(p->info == elem){
            ant->prox = p->prox;
            TLSE* copia = rto(p->prox,elem);
            free(p);
        }
    }   
    return l;
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x,n;
  printf("Digite o valor que será retirada: ");
  scanf("%d", &n);
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  TLSE* resp = rto(l,n);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(resp);

  TLSE_libera(l);
  TLSE_libera(resp);

  return 0;
}