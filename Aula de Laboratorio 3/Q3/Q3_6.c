
#include"TLSE.c"


TLSE* mult_k6(TLSE *l, int k){
    //Criando a lista de resposta
    TLSE* resp = TLSE_inicializa();
    TLSE* aux = TLSE_inicializa();

    //Passando os não multiplos para o aux
    TLSE* p = l;
    while(p){
        if(p->info % k != 0) aux = TLSE_insere(aux,p->info);
        p = p->prox;
    }

    //Passando eles para a resp agora em ordem
    TLSE* q = aux;
    while(q){
        resp = TLSE_insere(resp, q->info);
        q = q->prox;
    }

    TLSE_libera(aux);
    return resp;
}

int main(void){
  int k;
  printf("Digite o valor dos quais os multiplos serao retirados: ");
  scanf("%d", &k);
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  TLSE* resp = mult_k6(l,k);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(resp);

  TLSE_libera(l);
  TLSE_libera(resp);

  return 0;
}