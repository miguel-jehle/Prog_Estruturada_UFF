/*Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).*/

//NOTAS:
//A ideia central deste algorítmo se baseia em pegar os nós pares, na ordem que aparecem,
//inserir uma copia no final e então excluir o nó original que estava no começo, assim,
//preservando a ordem mas mandando eles para o final como solictiado

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

void i_p (TLSE *l){
    //Para inserir no fim precisamos demarcar o ultimo nó e lembrar de andar ele sempre que um novo for adicionado
    TLSE* ult = l;
    int cont = 1;
    while(ult->prox) {
        ult = ult ->prox;
        cont++;
    }
    //Com o ultimo demarcado, precisamos encontrar os nós pares
    TLSE *par = l;
    TLSE* ant = NULL;

    
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  i_p(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l);

  TLSE_libera(l);

  return 0;
}

