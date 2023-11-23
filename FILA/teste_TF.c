#include <limits.h>
#include "TF.h"

int main(void){
  TF *f = TF_inicializa();
  printf("f:\n");
  int n;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    TF_insere(f, n);
  }
  TF_imprime(f);
  printf("\n");
  TF_libera(f);
  return 0;
}
