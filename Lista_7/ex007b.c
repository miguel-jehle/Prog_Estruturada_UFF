/*Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).*/

//Vamos fazer um algortimo baseado no desloca!!!

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

void i_p (TLSE *l){
 if(!l || !l->prox) return;

 TLSE* c = l;
 int cont = 0;
 while(c->prox){
    c = c->prox;
    cont++;
 }

 TLSE* p = l;
 for(int i = 0; i <= cont; i++){
    if(p->info % 2 == 0){
        TLSE* troca = p;
        int x = p ->info;
        while(troca->prox){
            troca ->info = troca->prox->info;
            troca = troca ->prox;
        }
        troca->info = x;
    } else {
        p = p->prox;
    }
  }
  return;
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

  i_p(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l);

  TLSE_libera(l);

  return 0;
}