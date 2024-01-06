#include<stdio.h>
#include<stdlib.h>

typedef struct fila TF;

TF* TF_inicializa();
int TF_vazia(TF* f);
int TF_retira(TF*f);
void TF_insere(TF* f, int x);
void TF_libera(TF* f);
void TF_imprime(TF* f);