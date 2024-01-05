/*(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);*/

#include"alm.c"

/*Nossa ideia aqui é criar uma pilha para receber todos os elementos aos contrários da fila ao contrário, e então
com todos invertidos pela lógica de pilha e então a partir da pilha jogar para fila pra resp*/

TF* inv_fila (TF *f){
  //Criando a pilha auxiliar
  TP* pilha_aux = TP_inicializa();

  //Agora precisamos pegar os elementos da fila original e jogar na pilha
  while(!TF_vazia(f)){
      int x = TF_retira(f);
      TP_push(pilha_aux,x);
  }

  //Agora criamos a fila de resposta
  TF* fila_resp = TF_inicializa();

  while(!TP_vazia(pilha_aux)){
      int x = TP_pop(pilha_aux);
      TF_insere(fila_resp,x);
  }

  TP_libera(pilha_aux);
  return fila_resp;
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
  printf("A fila original eh: ");
  TF_imprime(f);
  printf("\n");

  TF* resp = inv_fila(f);
  printf("A pilha gerada eh: \n");
  TF_imprime(resp);
  TF_libera(resp);
  TF_libera(f);
  return 0;
}