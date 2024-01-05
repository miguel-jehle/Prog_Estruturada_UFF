#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
  int mat;
  char data_nasc[9];
  char nome[31];
}TP;

//OK

int compara (const void *a, const void *b){
  TP ** pessoa1 = (TP**) a;
  TP ** pessoa2 = (TP**) b;
  TP * p1 = (*pessoa1);
  TP * p2 = (*pessoa2);

  if(strcmp(&p1->data_nasc[4],&p2->data_nasc[4]) < 0) return -1;
  if(strcmp(&p1->data_nasc[4],&p2->data_nasc[4]) > 0) return 1;

  if(strcmp(&p1->data_nasc[2],&p2->data_nasc[2]) < 0) return -1;
  if(strcmp(&p1->data_nasc[2],&p2->data_nasc[2]) > 0) return 1;

  if(strcmp(&p1->data_nasc[0],&p2->data_nasc[0]) < 0) return -1;
  if(strcmp(&p1->data_nasc[0],&p2->data_nasc[0]) > 0) return 1;

  if(strcmp(p1->nome,p2->nome) < 0) return -1;
  if(strcmp(p1->nome,p2->nome) > 0) return 1;

  if(p1->mat < p2->mat) return -1;
  return 1;
}


TP * retira_k(TP **vet, int k, int n){
  TP **aux = (TP**)malloc(sizeof(TP*)*n);

  for(int i=0; i<n; i++){
    aux[i] = vet[i];
  }

  qsort(aux, n, sizeof(TP*), compara);

  TP * x = aux[k-1];
  printf("bbbbbbbbbbb");

  for(int i=0; i<n; i++){
    printf("OHHHHHHHHHHHHH");
    if(vet[i]->mat == aux[k-1]->mat){
        printf("AHHHHHHHHHHHHH");
        vet[i] = NULL;
        break;
    }
  }

  free(aux);
  return x;
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
