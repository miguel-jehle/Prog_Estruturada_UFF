#include "TP.h"

void imprime(TP *p){
  if(TP_vazia(p)) return;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p)){
       int x = TP_pop(p);
       printf("%d ", x);
       TP_push(aux, x);
  }
  printf("\n");
  while(!TP_vazia(aux))
      TP_push(p, TP_pop(aux));
  TP_libera(aux);
}

int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    imprime(p);
    printf("\n");
    TP_libera(p);

  return 0;
}
