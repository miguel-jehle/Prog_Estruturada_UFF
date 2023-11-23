/*Q3) Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLSE*
desloca (TLSE* l, int n).*/
#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

TLSE* desloca (TLSE* l, int n){
  
    //COPIANDO O VETOR ORIGINAL

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

    //ALGORITMO DA QUESTÃO DE FATO
    //Caso ímpar
    if(n % 2 != 0){
        //Vamos descobrir o último elemento da lista para salvá-lo
        TLSE* penultimo = copia;
        TLSE* ultimo = penultimo->prox;
        while(ultimo->prox){
            ultimo = ultimo ->prox;
            penultimo = penultimo ->prox;
        }

        //Agora basta indicar criar um novo nó que será encaixado no começo
        TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
        novo ->info = ultimo->info;
        novo ->prox = copia;
        copia = novo;

        //Vamos dar free no ultimo nó para faze-lo deixar de existir
        free(ultimo);
        free(l_aux);
        
        //E então o antigo penultimo apontar para null
        penultimo ->prox = NULL;

        //E finalmente retornar a deslocada para direita
        return copia;
    }
    else{
      //Caso par: basta pegar o primeiro nó e encaixar no final
      TLSE* primeiro = copia;
      TLSE* segundo = copia->prox;

      //Vamos descobrir o último elemento da lista para salvá-lo
      TLSE* ultimo = copia;
      while(ultimo->prox) ultimo = ultimo ->prox;

      //Com todas essas informações, criamos um novo nó
      TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
      //Preencho com as informações do primeiro nó
      novo -> info = primeiro ->info;
      //Faço ele apontar para NULL
      novo -> prox = ultimo ->prox;
      //Mando o até então ultimo apontar para este nó, inserindo ele ao final
      ultimo -> prox = novo;
      //Então mando meu ponteiro inicial, apontar para o segundo
      copia = segundo;
    }
    return copia;
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x,n;
  printf("Digite o tamanho da lista que sera inserida: ");
  scanf("%d", &n);
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  TLSE* deslocada = desloca(l,n);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(deslocada);

  TLSE_libera(l);
  TLSE_libera(deslocada);

  return 0;
}