/*verificar se os elementos que estão nas posições pares e ímpares são pares e ímpares, respectivamente:
int misc (TLSE *l);*/

#include "TLSE.c"

int misc (TLSE *l){
    //Vamos setar um ponteiro para o inicio e também instanciar uma variavel para o indice
    TLSE* p = l;
    int i = 0;
    int ver = 1;

    while(p->prox){
        if(((p->info % 2 == 0) && (i % 2 == 0)) || ((p->info % 2 != 0) && (p->info % 2 != 2))){
            p = p->prox;
            i++;
        } else {
            ver = 0;
            break;
        }
    }
    return ver;
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

  int resp = misc(l);
  if(resp) printf("Todos os ind pares estao ocupadas por pares e as impares por valores impares.");
  else printf("Not");

  TLSE_libera(l);

  return 0;
}