//(c) 1- maior preço primeiro; havendo empates, 2- nome do produto em ordem crescente; e, ocorrendo empates, 3- ordem crescente de data: void ordena_c(TPROD **vet, int n)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prod{
    char misc[51];
    float preco;
}TPROD;

int compara(const void *a, const void *b){
    //Aqui nós criamos um ponteiro para o ponteiro de struct passado, e ai por isso nas duas primeiras linhas temos dois asteristicos. Vale lembrar que após a igualdade colocamos um "casting" para confirmar o seu tipo, por ser inicialmente const void
    TPROD **pont_a = (TPROD**) a;
    TPROD **pont_b = (TPROD**) b;

    //Aqui nós estmoas buscando simplificar as coisas, pois como temos um ponteiro de ponteiro de struct, fica ruim de trabalhar, então criamos um novo ponteiro de struct que irá apontar para o conteudo do nosso ponteiro de ponteiro de struct criado nas linjas acima, assim, nos dando uma maior facilidade de trabalhar, pois agora seria so como um ponteiro de struct
    TPROD *prod_a = (*pont_a);
    TPROD *prod_b = (*pont_b);

    //Compara preço
    if ((prod_a->preco) > (prod_b->preco)) return -1;
    if ((prod_a->preco) < (prod_b->preco)) return 1;

    //Compara nome
    if(strcmp(&prod_a->misc[8],&prod_a->misc[8]) < 0) return -1;
    if(strcmp(&prod_a->misc[8],&prod_a->misc[8]) > 0) return 1;

    //Compara ano
    if(strcmp(&prod_a->misc[4],&prod_a->misc[4]) < 0) return -1;
    if(strcmp(&prod_a->misc[4],&prod_a->misc[4]) > 0) return 1;

    //Compara mês
    if(strcmp(&prod_a->misc[2],&prod_a->misc[2]) < 0) return -1;
    if(strcmp(&prod_a->misc[2],&prod_a->misc[2]) > 0) return 1;

    //Compara dia
    if(strcmp(&prod_a->misc[0],&prod_a->misc[0]) < 0) return -1;
    if(strcmp(&prod_a->misc[0],&prod_a->misc[0]) > 0) return 1;
}

void ordena_c(TPROD **vet, int n){
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
  ordena_c(vet, n);
  for(i = 0; i < n; i++){
    printf("%s\t%f\n", vet[i]->misc, vet[i]-> preco);
    free(vet[i]);
  }
  free(vet);

  return 0;
}

