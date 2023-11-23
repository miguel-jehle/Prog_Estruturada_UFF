/*(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);*/

#include"alm.c"

TF* inv_fila (TF *f){
    //Criando a pilha auxiliar
    TP* pilha_aux = TP_inicializa();

    //Loop para retirar todos da fila e botar na pilha
    while(f->n > 0){
        int x  = TF_retira(f);
        TP_push(pilha_aux,x);
    }

    TF* resp = TF_inicializa();

    while(pilha_aux->topo){
        int x = TP_pop(pilha_aux);
        TF_insere(resp,x);
    }

    TP_libera(pilha_aux);

    return resp;
}

int main(void){
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

  TF* resp = inv_fila(f);
  printf("A pilha de resposta eh: \n");
  TF_imprime(resp);
  printf("\n");
  TF_libera(f);
  TF_libera(resp);
  return 0;
}