/*Q6) Defina uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída,
os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos
aparecem em l. Ao final da execução desta função, a lista resultante terá todos os
elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles
aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função
é o seguinte: TLSE* i_p (TLSE *l).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE* i_p (TLSE *l){
    //Vamos criar uma LSE nova, para receber os valores da original na ordem desejada
    TLSE* aux = NULL;

    //Agora criaremos o ponteiro que irá percorrer toda a LSE original em busca dos impares
    TLSE* imp = l;
    while(imp){
        if(imp->info % 2 != 0){
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo -> info = imp ->info;
            novo -> prox = aux;
            aux = novo;
            imp = imp ->prox;
        }else imp = imp ->prox;
    }
    //Agora um para os elementos pares
    TLSE* par = l;
    while (par){
        if(par->info % 2 == 0){
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo -> info = par -> info;
            novo -> prox = aux;
            aux = novo;
            par = par ->prox;
        }else par = par ->prox;
    }

    //Como inserimos no começo, a LSE se encontrar ao contrário, logo iremos inverte-la
    //Como não sou de ferro adicionie a Q1 no TLSE.c e só chamei
    TLSE_inverte(aux);
    
    return aux;
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

  TLSE* resp = i_p(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(resp);

  TLSE_libera(l);
  TLSE_libera(resp);

  return 0;
}