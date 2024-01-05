#include"TF.c"

TF* mult_k4(TF *f, int k){
    //Criando a fila de resposta
    TF* resp = TF_inicializa();

    //Passando os valores não multiplos de k para a resp
    while(!TF_vazia(f)){
        int x = TF_retira(f);
        if(x % k != 0) TF_insere(resp,x);
    }
    return resp;
}

int main(void){
    int k;
    printf("Digite o numero do qual os multiplos serao tirados: ");
    scanf("%d", &k);
    TF *f = TF_inicializa();
    printf("f:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(f, n);
    }
    printf("A fila original eh: \n");
    TF_imprime(f);
    printf("\n");

    TF* resp = mult_k4(f,k);
    printf("A pilha sem os multiplos de k eh: \n");
    TF_imprime(resp);
    printf("\n");

    TF_libera(resp);
    TF_libera(f);

  return 0;
}