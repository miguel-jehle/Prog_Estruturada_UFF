#include<stdio.h>
#include<stdlib.h>
#include <limits.h>



/*Nossa ideia aqui, para que os conceitos sejam respeitados, será criar uma pilha auxiliar que receberá 
todos os elementos da fila mas se encontrará invertida, então criaremos a pilha de resposta que receberá
todos na ordem desejada
*/
typedef struct lse{
  int info;
  struct lse *prox;
} TLSE;

typedef struct fila TF;

typedef struct pilha TP;

struct pilha{
  TLSE *topo;
};

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

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
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

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}


struct fila{
	TLSE *ini;
	TLSE *fim;
};

TF *TF_inicializa(void){
	TF *f = (TF *)malloc(sizeof(TF));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int TF_vazia(TF *f){
	return !(f->ini); // 1 se vazia , 0 caso contrário
}

void TF_insere(TF *f, int elem){
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = elem;
	novo->prox = NULL; // INSERÇÃO NO FIM
	if (!TF_vazia(f))f->fim->prox = novo;
	else f->ini = novo;
	f->fim = novo;
}
	
int TF_retira(TF *f){
	if (TF_vazia(f)) exit(1);

	int resp = f->ini->info;

	TLSE *q = f->ini;
	f->ini=f->ini->prox;
	if (!f->ini) // esvaziou a fila
		f->fim = NULL;
	free(q);
	return resp;
}

void TF_libera(TF *f){
	TLSE *q, *p = f->ini;
	while(p){
		q = p;
		p = p->prox;
		free(q);
	}
	free(f);
}

void TF_imprime(TF *f){
 	TF *aux = TF_inicializa();
	while (!TF_vazia(f)){
		int x = TF_retira(f);
		printf("%d ",x);
		TF_insere(aux,x);
	}
	while(!TF_vazia(aux)) TF_insere(f, TF_retira(aux));
	TF_libera(aux);
}

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

void imprime(TP *p){
  if(TP_vazia(p)) return;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p)){
       int x = TP_pop(p);
       printf("%d ", x);
       printf("\n");
       TP_push(aux, x);
  }
  printf("\n");
  while(!TP_vazia(aux))
      TP_push(p, TP_pop(aux));
  TP_libera(aux);
}