//CORREÇÕES PRINCIPAIS FEITAS:
//      Linha 12: Mudança na condição inicial visto que, a usada na prova não servia como uma parada para a recursão
//      Linha 26: Dei o free apontado na correção

//COMENTÁRIOS: 
//      Foi a questão que mais tive de mudar, porque fiz de última hora na prova, então comentei linha por linha, para demosntrar meu raciocinio
//

#include "TLSE.c"

void ret_nao_mult_N(TLSE *l, int n){ // recursiva
    //if( l->info % n != 0) return;
    if ((!l) || (n <= 1) ) return; // Condicao de parada da recursao
    
    // Criar ponteiros auxiliares para nao perder a referencia do elemento a ser excluido
    TLSE *p = l->prox, *troca = l, *tmp;

    if(l->info % n != 0){
        // exclusao do while nao é necessário por conta da  recursao
        troca->info = p->info;
        // no auxiliar tmp recebe o elemento a ser excluido
        tmp = p;
        p = p->prox;
        troca->prox = p;
        // Uso do free para liberar o espaço de memoria do elemento excluido
        free(tmp);
        ret_nao_mult_N(l, n);
    }
    // remocao do bloco if(p->info % n != 0), análise desnecessaria de nao multiplos
    // Correçao do else antigo 'p = p->prox;'
    else ret_nao_mult_N(l->prox, n);
    return;
}

int main(void){
  TLSE *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLSE_insere(l, n);
  }while(1);

  scanf("%d", &n);
  ret_nao_mult_N(l, n);
  TLSE_imprime(l);
  printf("\n");

  TLSE_libera(l);
  return 0;
}
