/*(e) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p).*/

/*Neste caso como o primeiro a ser retirado a pilha é o topo, e o primeiro a ser recebido a fila será 
o início, basta pegar os elementos da pilha e jogar na fila criada*/

#include"alm.c"

TF* p2f (TP *p){
    //Criando a fila de retorno
    TF* fila_resp = TF_inicializa();
    //Loop para pegar todos os valores da pilha
    while(!TP_vazia(p)){
        //Pegando o valor por meio do pop
        int x = TP_pop(p);
        //E então inserindo o valor pego na fila
        TF_insere(fila_resp,x);
    }
    return fila_resp;
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
    imprime(p);
    printf("\n");

    TF* resp = p2f(p);
    printf("A fila eh: \n");
    TF_imprime(resp);
    printf("\n");

    TP_libera(p);
    TF_libera(resp);

  return 0;
}