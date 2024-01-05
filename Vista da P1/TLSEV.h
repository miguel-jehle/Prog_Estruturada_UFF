#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  int mat;
  float nota;
  char nome[31];
  int prox_no;
}TNO;

typedef struct lse_com_vetor{
  int tam_vet_elem, prim, num_elem; 
  TNO** vet_elem;
}TLSEV;

TLSEV *TLSEV_inicializa(int tam_vet_elem);
void TLSEV_libera(TLSEV *l);
void TLSEV_imprime(TLSEV *l);
void TLSEV_insere_inicio(TLSEV *l, int mat, float nota, char *nome);

