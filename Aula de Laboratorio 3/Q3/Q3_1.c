
/*Retirar todos os elementos multiplos de k da pilha*/

#include"TP.c"

 void mult_k(TP *p, int k){
    //Criando uma pilha auxiliar para receber os valores não multiplos
    TP* p_aux = TP_inicializa();

    //Loop para percorrer a pilha retirando todos os seus valores e se não for multiplo, salva na auxiliar
    while(!TP_vazia(p)){
        int x = TP_pop(p);
        if(x % k != 0) TP_push(p_aux,x);
    }

    while(!TP_vazia(p_aux)){
        int x = TP_pop(p_aux);
        TP_push(p,x);
    }

    TP_libera(p_aux);
 }

 int main(void){
    int k;
    printf("Digite o numero do qual os multiplos serao tirados: ");
    scanf("%d", &k);
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    printf("A pilha original eh: \n");
    TP_imprime(p);
    printf("\n");

    mult_k(p,k);
    printf("A pilha sem os multiplos de k eh: \n");
    TP_imprime(p);
    printf("\n");

    TP_libera(p);

  return 0;
}