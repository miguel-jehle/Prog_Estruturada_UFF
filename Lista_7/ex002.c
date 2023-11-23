/*Q2) Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE* inverte (TLSE* l){
    //Vamos criar a LSE auxiliar na qual jogaremos os elementos da original
    TLSE *l_inv = NULL;

    //Criamos um for e baseado no "p" que irá percorrer a LSE original, pegaremos este nó e copiaremos sua info em um novo criado para a l_inv
    for(TLSE* p = l; p; p = p->prox){

        //Vamos mallocar um novo nó para cada "p" analisado
        TLSE* novo = (TLSE*)malloc(sizeof(TLSE));

        //Então iremos preencher este com a informação do "p"  da iteração respectiva
        novo ->info = p ->info;

        //Faremos o novo nó apontar para onde "l" apontava
        novo ->prox = l_inv;

        //E então mandamos "l" apontar para o nosso novo "l"
        l_inv = novo;
    }

    //Ao final deste for, toda a lista terá sido copiada, contudo, de trás para frente, já que os elementos copiados sempre entram na frente do anteior, invertendo a LSE
    return l_inv;
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

  TLSE* l_invertida = inverte(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l_invertida);

  TLSE_libera(l);
  TLSE_libera(l_invertida);

  return 0;
}