#include <stdio.h>
#include <stdlib.h>

typedef struct pilha TP;

void TP_push(TP *p, int elem);
int TP_pop(TP *p);
int TP_vazia(TP *p);
TP *TP_inicializa(void);
void TP_libera(TP *p);
void TP_imprime(TP *p);

