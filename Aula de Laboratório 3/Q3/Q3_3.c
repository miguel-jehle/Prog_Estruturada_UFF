#include "TF.c"

void mult_k3(TF *f, int k){
    //Inicializando a fila auxiliar
    TF* f_aux = TF_inicializa();

    //Retirar os elementos de f e jogar os não multiplos para f_aux
    while(!TF_vazia(f)){
        int x = TF_retira(f);
        if(x % k != 0) TF_insere(f_aux,x);
    }

    //Devolver para a original
    while(!TF_vazia(f_aux)){
        int x = TF_retira(f_aux);
        TF_insere(f,x);
    }
}

int main(void){
    int k;
    printf("Digite o numero do qual os multiplos serao tirados: ");
    scanf("%d", &k);
    TF *p = TF_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TF_insere(p, n);
    }
    printf("A fila original eh: \n");
    TF_imprime(p);
    printf("\n");

    mult_k3(p,k);
    printf("A fila sem os multiplos de k eh: \n");
    TF_imprime(p);
    printf("\n");

    TF_libera(p);

  return 0;
}