/*Q5) Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
Seu protótipo O protótipo desta função é o seguinte: TLSE* rto (TLSE* l, int elem).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE* rto (TLSE* l, int elem){
    TLSE* p = l;
    TLSE* ant = NULL;

    //Verifico se a lista é nula
    if(!p) return l;

    //Encontrando o primeiro termo sem ser o elemento desejado, para não ter estresses com casos de elementos seguidos no começo
    while(p){
        if(!ant && p->info == elem){
            TLSE* tmp = p;
            l = p->prox;
            p = l;
            free(tmp);
        }else break;
    }

    //Tendo certeza que agora não temos nenhum elemento a ser retirado no começo, seguimos o algoritmo normal e sem estresse
    while(p){
        
        if(p->info == elem){
            TLSE* tmp = p;
            ant -> prox = p -> prox;
            p = p->prox;
            free(tmp);
        }else{
            ant = p;
            p = p ->prox;
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