#include "TLSEV.h"

TLSEV *TLSEV_inicializa(int tam_vet_elem){
  TLSEV *l = (TLSEV *) malloc(sizeof(TLSEV));
  l->tam_vet_elem = tam_vet_elem;
  l->prim = -1;
  l->num_elem = 0;
  l->vet_elem = (TNO**) malloc(sizeof(TNO*) * tam_vet_elem);
  
  int i;
  for(i = 0; i < tam_vet_elem; i++) l->vet_elem[i] = NULL;
  return l;
}

void TLSEV_libera(TLSEV *l){
  int i;
  for(i = 0; i < l->tam_vet_elem; i++) 
    if(l->vet_elem[i] != NULL) 
      free(l->vet_elem[i]);
  free(l->vet_elem);
  free(l);
}

void TLSEV_imprime(TLSEV *l){
  int ind = l->prim;
  while(ind != -1){
    printf("[ind: %d] %d %.1f %s (prox: %d)\n", ind, l->vet_elem[ind]->mat, l->vet_elem[ind]->nota, l->vet_elem[ind]->nome, l->vet_elem[ind]->prox_no);
    ind = l->vet_elem[ind]->prox_no;
  }
}

void TLSEV_insere_inicio(TLSEV *l, int mat, float nota, char *nome){
  if(l->num_elem == l->tam_vet_elem){
    l->vet_elem = (TNO **) realloc(l->vet_elem, 2*l->tam_vet_elem*sizeof(TNO *));
    int i;
    for(i = l->tam_vet_elem; i < 2 * l->tam_vet_elem; i++) l->vet_elem[i] = NULL;
    l->tam_vet_elem *= 2;
  }
    
  int n;
  do{
    n = rand() % l->tam_vet_elem; //encontra uma posicao aleatoria...
    if(l->vet_elem[n] == NULL) break;
  }while(1);

  l->vet_elem[n] = (TNO*) malloc(sizeof(TNO));
  l->vet_elem[n]->mat = mat;
  l->vet_elem[n]->nota = nota;
  strcpy(l->vet_elem[n]->nome, nome);
  l->vet_elem[n]->prox_no = l->prim;
  l->prim = n;
  l->num_elem++;
}

