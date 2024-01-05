//CORREÇÕES REALIZADAS:
//    Linha 15: Colocando o conteúdo de posição como zero, para caso a lista seja nula tenha algo em pos,como pedido
//    Linha 29: Adicionei um if para evitar o erro de segmentação

//COMENTÁRIOS:
//    Professora, foram só duas linhas adicionadas, o erro principal, relacionado a segmentação, mas que foi prevenido
//    somente com um if, por favor tente reconsiderar pensando nisso, por favor!!!. Além disso, sobre o erro de dizer que 
//    o conteúdo de pos é zero, foi pelo fato de achar que como não havia lista (nula), não haveria posição alguma. Foi por pura questão
//    de interpretação, mas pela linha 18, dá pra ver que eu pensei nesse caso, mas sabia que era necessário pensar no pos cuidado sobre a lista ser nula ou não, por favor considere isso!!! 



#include"TLSE.c"

TLSE *meio (TLSE *l, int *pos){
    (*pos) = 0;
    int cont = 0;
    if(!l) return l;
    if(!l->prox){
        (*pos) = cont;
        return l;
    }
    TLSE *p = l;
    TLSE *q = p->prox;
    while(q->prox){
        q = q ->prox->prox;
        p = p->prox;
        cont++;
        //correção para não dar erro desegmentação
        if(!q) break;
    }
    (*pos) = cont;
    return p;
}

int main(void){
  TLSE *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLSE_insere(l, n);
  }while(1);

  int pos;
  TLSE *resp = meio(l, &pos);
  if(resp) 
    printf("O elemento do meio da lista (info: %d) esta na pos %d\n", resp->info, pos); 
  TLSE_libera(l);
  return 0;
}