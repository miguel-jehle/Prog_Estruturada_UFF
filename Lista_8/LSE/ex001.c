/*(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);*/

#include"alm.c"

/*Nossa ideia aqui, para que os conceitos sejam respeitados, será criar uma pilha auxiliar que receberá 
todos os elementos da fila mas se encontrará invertida, então criaremos a pilha de resposta que receberá
todos na ordem desejada
*/


TP* f2p (TF *f){
    //Criando a pilha auxiliar
    TP* pilha_aux = TP_inicializa();

    //Loop para pegar os elementos e jogar na pilha auxiliar
    while(f->ini){
        int x = TF_retira(f);
        TP_push(pilha_aux, x);
    }
    //Agora vamos criar a pilha de resposta
    TP* pilha_resp = TP_inicializa();

    //Loop para pegar os elementos da pilha auxiliar e jogar na resp
    while(pilha_aux->topo){
        int x = TP_pop(pilha_aux);
        TP_push(pilha_resp,x);
    }

    //Liberando a memoria pra não dar ruim
    TP_libera(pilha_aux);
    TF_libera(f);

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
  printf("A fila original eh: ");
  TF_imprime(f);
  printf("\n");

  TP* resp = f2p(f);
  printf("A pilha gerada eh: \n");
  TP_imprime(resp);
  TF_libera(f);
  return 0;
}
