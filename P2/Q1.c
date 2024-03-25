
#include"TLSE.c"
#include<stdlib.h>

void misc(TLSE* l, int x){
    //Primeiro precisamos verificar se l é nula 
    if( x < 2 || !l ) return;
    //Vamos tratar caso o 1° nó seja "x"
    TLSE* aux = NULL;
    if(l->info == x){
        aux = l;
        //Vamos criar um for que vai adicionar n-1 nós na frente deste e trocar a info do primeiro para     
        for(int i = x; i > 1; i--){
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo ->info = i;
            novo ->prox = aux ->prox;
            aux ->prox =  novo;
        }
        //Seto o primeiro nó como 1
        aux->info = 1;
        while(aux->info != x) aux = aux->prox; //Encontro novamente o nó e aplico a mesma lógica para inserir depois
        //Inserindo após agora tomando cuidado de inserir os blocos com n-1 e 0 de limite
        for(int i = x-1; i > 0; i--){
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo ->info = i;
            novo ->prox = aux->prox;
            aux->prox = novo;
        }

    }
    //Verificar se foi feito o tratamento do primeiro caso, para não encontrar o valor que antes estava no começo denovo
    TLSE* p;
    if(!aux)  p = l; //CORREÇÃO: Com o aux inicializado fora do if, não teremos mais problemas aqui
    else p = aux;
    while(p->prox){
        if(p->prox->info == x){
            for(int i = x-1; i > 0; i--){
                TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
                novo->info = i;
                novo ->prox = p->prox;
                p->prox = novo;
            }
            while(p->info != x) p = p ->prox;
            for(int i = x-1; i > 0; i--){
                TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
                novo ->info = i;
                novo -> prox = p ->prox;
                p->prox =  novo;
            }
        }
        else p = p->prox;
    }
}

int main(void){
  TLSE *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLSE_insere(l, n);
  }while(1);

  scanf("%d", &n);
  misc(l, n);
  TLSE_imprime(l);
  printf("\n");

  TLSE_libera(l);
  return 0;
}