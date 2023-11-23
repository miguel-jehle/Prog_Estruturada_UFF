#include "TLSE.h"
#include "TP.h"

struct pilha{
  TLSE *topo;
};	

TP *TP_inicializa(void){
  TP *p = (TP *)malloc(sizeof(TP));
  p->topo = NULL;
  return p;
}
	
int TP_vazia(TP *p){
  return (p->topo == NULL);
}
	
void TP_push(TP *p,int elem){
  p->topo = TLSE_insere(p->topo, elem);
  /*
  TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = p->topo;
  p->topo = novo;
  */
}

int TP_pop(TP *p){
  if (!TP_vazia(p)){
    TLSE *aux = p->topo;
    int x = aux->info;
    p->topo = aux->prox;
    free(aux);
    return x;
  }
  else{ // pilha vazia
    exit(1);
  }
}

void TP_libera(TP *p){
  TLSE_libera(p->topo);
  /*
  TLSE *q = p->topo,*r ;
  while(q){
    r = q;
    q = q->prox;
    free(r);
  }
  */
  free(p);
}

void TP_imprime(TP *p){
  TP *aux = TP_inicializa();
  int ind = 1;
  while (!TP_vazia(p)){
    int x = TP_pop(p);
    printf("%d -> %d\n", ind++, x);
    TP_push(aux,x);
  }
  while(!TP_vazia(aux)) TP_push(p, TP_pop(aux));
  TP_libera(aux);
}
