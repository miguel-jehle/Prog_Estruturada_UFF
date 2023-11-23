#include "TF.h"

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
