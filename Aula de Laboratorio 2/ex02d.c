//(d) mesmos critérios de (c): void ordena_d(TPROD *vet, int n);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prod{
    char misc[51];
    float preco;
}TPROD;

int compara(const void *a, const void *b){
    TPROD *prod_a = (TPROD*) a;
    TPROD *prod_b = (TPROD*) b;

    //Compara preço
    if((&prod_a->preco) > (&prod_b->preco)) return -1;
    if((&prod_a->preco) < (&prod_b->preco)) return 1;

    //Compara nome
    if(strcmp(&prod_a->misc[8],&prod_b->misc[8]) < 0) return -1;
    if(strcmp(&prod_a->misc[8],&prod_b->misc[8]) > 0) return 1;

    //Compara ano
    if(strcmp(&prod_a->misc[4],&prod_b->misc[4]) < 0) return -1;
    if(strcmp(&prod_a->misc[4],&prod_b->misc[4]) > 0) return 1;

    //Compara mes
    if(strcmp(&prod_a->misc[2],&prod_b->misc[2]) < 0) return -1;
    if(strcmp(&prod_a->misc[2],&prod_b->misc[2]) > 0) return 1;

    //Compara dia
    if(strcmp(&prod_a->misc[0],&prod_b->misc[0]) < 0) return -1;
    if(strcmp(&prod_a->misc[0],&prod_b->misc[0]) > 0) return 1;
}

void ordena_d(TPROD *vet, int n){
    qsort(vet, n, sizeof(TPROD), compara);
}

int main(void){
  int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);

  TPROD *vet = (TPROD *) malloc(sizeof(TPROD) * n);
  int i;
  for(i = 0; i < n; i++){
    scanf(" %50[^\n]", vet[i].misc);
    scanf("%f", &vet[i].preco);
  }
  ordena_b(vet, n);
  for(i = 0; i < n; i++){
    printf("%s\t%f\n", vet[i].misc, vet[i].preco);
  }
  free(vet);

  return 0;
}