#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
  int mat;
  char data_nasc[9];
  char nome[31];
}TP;

int compara(const void *a, const void*b){
  TP** pont_a = (TP**)a;
  TP** pont_b = (TP**)b;

  TP* pac_a = (*pont_a);
  TP* pac_b = (*pont_b);

  //Data por ano
    if(strcmp(&pac_a->data_nasc[4],&pac_b->data_nasc[4]) < 0) return -1;
    if(strcmp(&pac_a->data_nasc[4],&pac_b->data_nasc[4])> 0) return 1;

    //Data por mes
    if(strcmp(&pac_a->data_nasc[2],&pac_b->data_nasc[2]) < 0) return -1;
    if(strcmp(&pac_a->data_nasc[2],&pac_b->data_nasc[2]) > 0) return 1;

    //Data por dia
    if(strcmp(pac_a->data_nasc,pac_b->data_nasc) < 0) return -1;
    if(strcmp(pac_a->data_nasc,pac_b->data_nasc) > 0) return 1;

    //Por nome
    if(strcmp(pac_a->nome,pac_b->nome) < 0)return -1;
    if(strcmp(pac_a->nome,pac_b->nome) > 0)return 1;

    //Por inscrição
    if((pac_a->mat) < (pac_b->mat)) return -1;
    return 1;
}

TP* retira_k(TP **vet, int n, int k){
  //Criando o vetor
  TP** vet_ord = (TP**)malloc(sizeof(TP*)*n);
  //Preenchendo
  for(int i = 0; i<n; i++) vet_ord[i] = vet[i];

  //Agora com o vetor copiado iremos ordená-lo
  qsort(vet_ord,n,sizeof(TP*), compara);

  //Pegando o k-ésimo elemento do ordenado
  TP* resp = vet_ord[k-1];

  //Pegando o k-ésimo elemento da ordenada, encontrando na normal e colocando NULL no lugar
  for(int i = 0; i < n;i++){
    if(vet[i]->mat == vet_ord[k-1]->mat){
      vet[i] = NULL;
      break;
    }
  }

  free(vet_ord);
  return resp;
}



int main(void){
  int n;
  printf("Digite o tamanho do vetor... ");
  scanf("%d", &n);
  if(n <= 0) return 0;
  TP* elem, *vet[n];
  int i = 0;
  while(i < n){
    elem = (TP *) malloc(sizeof(TP));
    printf("Digite os dados (insc, data e nome) do candidato...\n");
    scanf("%d", &elem->mat);
    scanf(" %8[^\n]", elem->data_nasc);
    scanf(" %30[^\n]", elem->nome);
    vet[i++] = elem;
  }
  printf("Digite a posicao do elemento a ser retirado... ");
  int k;
  scanf("%d", &k);
  elem = NULL;
  elem = retira_k(vet, n, k);
  free(elem);
  printf("Depois de retira_k:\n");
  for(i = 0; i < n; i++) 
    if(vet[i]) printf("%d %s %s\n", vet[i]->mat, vet[i]->data_nasc, vet[i]->nome);
  for(i = 0; i < n; i++) 
    free(vet[i]);
  return 0; 
}
