#include<stdio.h>
#include<stdlib.h>

typedef struct pilha TP;

TP* TP_inicializa();
int TP_vazia(TP* p);
int TP_pop(TP* p);
void TP_libera(TP* p);
void TP_push(TP* p, int x);
void TP_imprime(TP* p);