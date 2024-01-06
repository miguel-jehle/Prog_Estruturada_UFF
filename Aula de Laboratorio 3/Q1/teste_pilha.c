#include"TP.c"

void retira_pares (TP *p){
    //Crio a pilha auxiliar
    TP* pilha_aux = TP_inicializa();

    //Loop para percorrer toda a pilha
    while(!TP_vazia(p)){
        //Apaga e pega
        int x = TP_pop(p);
        //Se for par joga para aux
        if(x % 2 != 0){
            TP_push(pilha_aux,x);
        }
    }
    //Devolve para a original
    while(!TP_vazia(pilha_aux)){
        int x = TP_pop(pilha_aux);
        TP_push(p, x);
    }

    return;
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
    printf("A pilha original eh: \n");
    TP_imprime(p);
    printf("\n");

    retira_pares(p);
    printf("A pilha sem os pares eh: \n");
    TP_imprime(p);
    printf("\n");

    TP_libera(p);

  return 0;
}
