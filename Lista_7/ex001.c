#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"


void inverte(TLSE *l){
    //Vamos descobrir quantos elementos tem a lista
    TLSE *p = l;
    int tamanho = 0;
    for(p = l; p; p = p->prox) tamanho++;

    int fim = tamanho-1;
    p = l;
    //Com o tamanho descoberto poderemos usá-lo pra limitar os for's e aplicar a lógica de trocar o primeiro com o último e etc

    //Neste primeiro for, usaremos o i para limitar que o "p" só percorra metade da LSE, pois seus elementos serão trocados com da metade final
    for(int i = 0; i < tamanho/2; i++){
        TLSE* q = p;
        //Já este for, queremos que o "q" chegue até o último elemento da lista, descontando os já trocados, ou seja, na 1 iteração, q vai até o ultimo, na 2 até o penultimo, usando o j para limitar e controlar isso
        for(int j = 0; j < fim; j++){
            q = q->prox;
        }
        //Com p e q devidamente posicionados, realizamos a troca
        int temp = p->info;
        p->info = q ->info;
        q->info = temp;
        //Troca feita atualizamos o valor de fim para que o "q" não alcance um nó já trocado
        fim -= 2;
        //
        p = p->prox;
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

  inverte(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l);

  return 0;
}
