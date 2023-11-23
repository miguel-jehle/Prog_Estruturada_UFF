/*(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);*/

#include"alm.c"

TP* f2p (TF *f){
    //Criando a pilha auxiliar
    TP* pilha_aux = TP_inicializa();

    //Jogar todos os elementos da fila para a pilha_aux
    while(f->n > 0){
        int x = TF_retira(f);
        TP_push(pilha_aux,x);
    }

    //Criando a pilha de resposta
    TP *pilha_resp = TP_inicializa();

    while(pilha_aux->topo){
        int y = TP_pop(pilha_aux);
        TP_push(pilha_resp,y);
    }
    TP_libera(pilha_aux);

   

    return pilha_resp;
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

  TP* resp = f2p(f);
  printf("A pilha de resposta eh: \n");
  TP_imprime(resp);
  printf("\n");
  TF_libera(f);
  return 0;
}
