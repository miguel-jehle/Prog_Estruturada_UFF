/*(2) Dado um tipo produto com os seguintes componentes:
-> String de 51 caracteres, onde os primeiros 8 caracteres indicam a data do produto (no formato ddmmaaaa), e os demais 42 indicam o nome do produto; e
-> preço (float).

Ordene seguindo os seguintes critérios:
(a) 1- nome do produto em ordem crescente; havendo empates, 2- ordem crescente de data; ocorrendo empates, 3- maior preço primeiro:

void ordena_a(TPROD **vet, int n);
onde:
  typedef struct prod{
    char misc[51];
    float preco;
  }TPROD;*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prod{
    char misc[51];
    float preco;
}TPROD;

int compara(const void *a, const void *b){
    //Politica de afirmação
    TPROD **pont_a = (TPROD**) a;
    TPROD **pont_b = (TPROD**) b;

    //Simplificação
    TPROD *prod_a = (*pont_a);
    TPROD *prod_b = (*pont_b);

    //OBS: O strcmp compara ambos e retorna -1 caso o primeiro seja maior, 0 se forem iguais e 1 se o segundo for maior
    
    //OBS: Nós só usamos o "&" pois como estamos passando um trecho especifico do mis, precisamos pegar o endereço deste trecho em específico

    //comparar nome
    if(strcmp(&prod_a->misc[8],&prod_b->misc[8]) > 0)return -1;
    if(strcmp(&prod_a->misc[8],&prod_b->misc[8]) < 0)return 1;

    //compara ano
    if(strcmp(&prod_a->misc[4],&prod_b->misc[4]) > 0) return -1;
    if(strcmp(&prod_a->misc[4],&prod_b->misc[4]) < 0) return 1;

    //compara mes
    if(strcmp(&prod_a->misc[2],&prod_b->misc[2]) > 0) return -1;
    if(strcmp(&prod_a->misc[2],&prod_b->misc[2]) < 0) return 1;

    //compara dia
    if(strcmp(&prod_a->misc[0],&prod_b->misc[0]) > 0) return -1;
    if(strcmp(&prod_a->misc[0],&prod_b->misc[0]) < 0) return 1;

    //compara compara
    if((prod_a->preco) > (prod_b->preco)) return -1;
    if((prod_a->preco) < (prod_b->preco)) return 1;

    return 0;
}

void ordena_a(TPROD **vet, int n){
    qsort(vet, n, sizeof(TPROD*), compara);
}

int main(void){
  int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);

  TPROD **vet = (TPROD **) malloc(sizeof(TPROD *) * n);
  int i;
  for(i = 0; i < n; i++){
    vet[i] = (TPROD *) malloc(sizeof(TPROD));
    scanf(" %50[^\n]", vet[i]->misc);
    scanf("%f", &vet[i]-> preco);
  }
  ordena_a(vet, n);
  for(i = 0; i < n; i++){
    printf("%s\t%f\n", vet[i]->misc, vet[i]-> preco);
    free(vet[i]);
  }
  free(vet);

  return 0;
}