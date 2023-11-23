#include "TLSE.h"

TLSE* TLSE_inicializa(){
  return NULL;
}

TLSE* TLSE_insere(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLSE_imp_rec(TLSE *l){
  if(l){
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox);
  }
}

void TLSE_imp_rec_rev(TLSE *l){
  if(l){
    TLSE_imp_rec_rev(l->prox);
    printf("%d ", l->info);
  }
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

void TLSE_lib_rec(TLSE *l){
  if(l){
    TLSE_lib_rec(l->prox);
    printf("liberando o elemento %d...\n", l->info);
    free(l);
  }
}

TLSE* TLSE_retira(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_retira_rec(TLSE *l, int elem){
  if(!l) return l;
  if(l->info == elem){
    TLSE *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = TLSE_retira_rec(l->prox, elem);
  return l;
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

TLSE* TLSE_busca_rec(TLSE *l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLSE_busca_rec(l->prox, elem);
}

TLSE *TLSE_copia (TLSE *l){
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

void TLSE_inverte(TLSE *l){
    TLSE *p = l;
    int tamanho = 0;
    for(p = l; p; p = p->prox) tamanho++;
    int fim = tamanho-1;
    p = l;
    for(int i = 0; i < tamanho/2; i++){
        TLSE* q = p;
        for(int j = 0; j < fim; j++){
            q = q->prox;
        }
        int temp = p->info;
        p->info = q ->info;
        q->info = temp;
        fim -= 2;
        p = p->prox;
    }
 
    return;
}

