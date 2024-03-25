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