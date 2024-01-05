#include "TLSE.c"

void mult_k5(TLSE *l, int k){
    //Preciso tratar caso o primeiro elemento já seja um multiplo ou se não 
    if(l->info % k == 0){
        TLSE* q = l->prox;
        while(q){
            if(q->info % k != 0){
                int temp = q->info;
                q->info = l->info;
                l->info = temp;
                break;
            }else q = q->prox;
        }
        //Se não houve algum numero não multiplo para trocar e tratar, quer dizer que toda a lista sera tirada, logo podemos dar free nela e encerrar o programa
        if(!q){
            printf("Agora o resultado da funcao criada: TODOS OS ELEMENTOS FORAM RETIRADOS");
            TLSE_libera(l);
            exit(1);
        }
    }

    //Tendo certeza que o primeiro elemento não é mais um multiplo de k, podemos criar ant e p sem este problema
    TLSE* ant = l;
    TLSE* p = l->prox;
    while(p){
        if(p->info % k == 0){
            TLSE* temp = p;
            ant ->prox = p ->prox;
            p = p->prox;
            free(temp);
        } else {
            ant = ant ->prox;
            p = p->prox;
        }
    }
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

  mult_k5(l,k);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l);

  TLSE_imprime(l);

  return 0;
}