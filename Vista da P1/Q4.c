#include "TLSEV.c"

TNO* meio(TLSEV *l, int *pos){
  int inicio = l->prim;
  for(int i = 0; i < l->num_elem/2;i++){
    inicio = l->vet_elem[inicio]->prox_no;
    (*pos) = inicio;
  }
  return l->vet_elem[inicio];
}

int main(void){
  int n;
  scanf("%d", &n);
  if(n <= 0) return 0;
  TLSEV *l = TLSEV_inicializa(n);
  int i;
  int mat;
  float nota;
  char nome[31];
  for(i = 0; i < n; i++){
    scanf("%d%f", &mat, &nota);
    scanf(" %30[^\n]", nome);
    TLSEV_insere_inicio(l, mat, nota, nome);
  }
  printf("Lista:\n");
  TLSEV_imprime(l);
  int pos = -1;
  TNO *elem_meio;
  elem_meio = meio(l, &pos);
  if(pos != -1){
    printf("Elemento do meio esta na posicao %d: ", pos);
    printf("%d %.1f %s\n", elem_meio->mat, elem_meio->nota, elem_meio->nome);
  }
  TLSEV_libera(l);
  return 0;  
}
