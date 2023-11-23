#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct fila TF;

void TF_insere(TF *f, int elem);
int TF_vazia(TF *f);
void TF_libera(TF *f);
TF *TF_inicializa(void);
int TF_retira(TF *f);
void TF_imprime(TF *f);

struct fila{
  int n, ini, tam;
  int *vet;
};

TF *TF_inicializa (void){
  TF *f = (TF *) malloc(sizeof (TF));
  f->tam = 1;
  f->vet = (int *) malloc(sizeof(int) * f->tam);
  f->n = f->ini = 0;
  return f;
}

int incr (int ind, int n){
  return (ind + 1) % n;
}

int TF_vazia (TF *f){
  return f->n == 0;
}

int TF_retira (TF *f){
  if(TF_vazia(f)) exit(1);
  int resp = f->vet[f->ini];
  f->ini = incr(f->ini, f->tam);
  f->n--;
  return resp;
}

void TF_libera (TF *f){
  free(f->vet);
  free(f);
}

void TF_insere (TF *f, int x){
  if(f->n == f->tam){
    int *vet = (int *) malloc(sizeof(int) * f->n * 2);
    int i = f->ini, j = 0;
    while(j < f->n){
      vet[j++] = f->vet[i];
      i = incr(i, f->tam);
    }
    f->ini = 0;
    f->tam *= 2;
    int *aux = f->vet;
    f->vet = vet;
    free(aux);
  }
  int fim = (f->ini + f->n++) % f->tam;
  f->vet[fim] = x;
}

void TF_imprime(TF *f){
  int ind = f->ini, i;
  for(i = 0; i < f->n; i++){
    printf("%d -> %d\n", i + 1, f->vet[ind]);
    ind = incr(ind, f->tam);
  }
}



typedef struct pilha TP;

void TP_push(TP *p, int elem);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);

struct pilha{
  int topo, n;
  int *vet;
};	

TP *TP_inicializa (void){
  TP *p = (TP *) malloc(sizeof (TP));
  p->topo = 0;
  p->n = 1;
  p->vet = (int *) malloc(sizeof(int) * p->n);
  return p;
}
 
int TP_vazia (TP *p){
  return p->topo == 0;
}

int TP_pop(TP *p){
  if(TP_vazia(p)) exit(1);
  int resp = p->vet[--p->topo];
  return resp;
}

void TP_libera(TP *p){
  free(p->vet);
  free(p);
}

void TP_push(TP *p, int x){
  if(p->topo == p->n){
    p->n *= 2;
    p->vet = realloc(p->vet, p->n * sizeof(int));
  }
  p->vet[p->topo++] = x;
}

void TP_imprime(TP *p){
  int i;
  for(i = p->topo - 1; i >= 0; i--)
    printf("%d -> %d\n", p->topo - i, p->vet[i]);
}