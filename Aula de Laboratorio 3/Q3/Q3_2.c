
#include"TP.c"

TP* mult_k2(TP *p, int k){
    //Criando a pilha auxiliar e a pilha de resposta
    TP* p_aux = TP_inicializa();
    TP* resp = TP_inicializa();

    //Eliminando todos os valores da original
    while(!TP_vazia(p)){
        int x = TP_pop(p);
        if(x % k != 0) TP_push(p_aux,x);
    }

    //Passando os não multiplos para a resp para ficar na ordem certa
    while(!TP_vazia(p_aux)){
        int x = TP_pop(p_aux);
        TP_push(resp,x);
    }

    TP_libera(p_aux);
    return resp;
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

    TP* resp = mult_k2(p,k);
    printf("A pilha sem os multiplos de k eh: \n");
    TP_imprime(resp);
    printf("\n");

    TP_libera(resp);
    TP_libera(p);

  return 0;
}