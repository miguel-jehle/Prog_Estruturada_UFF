#include "TLSE.c"

void ret_nao_mult_N(TLSE *l, int n) {
    if (!l || !l->prox) {
        return;
    }

    if (l->info % n != 0) {
        TLSE *troca = l->prox;
        while (troca && troca->info % n != 0) {
            troca = troca->prox;
        }

        if (troca) {
            int tmp = l->info;
            l->info = troca->info;
            troca->info = tmp;
        }
    }

    ret_nao_mult_N(l->prox, n);
}

int main(void){
  TLSE *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLSE_insere(l, n);
  }while(1);

  scanf("%d", &n);
  ret_nao_mult_N(l, n);
  TLSE_imprime(l);
  printf("\n");

  TLSE_libera(l);
  return 0;
}