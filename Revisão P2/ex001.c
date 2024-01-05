/*Vamos receber uma LSE e um x, caso x sej apar, retira o proximo nó, caso seja impar, retira o anterior*/

#include"TLSE.c"

TLSE* retira(TLSE *l, int x){
    /////////////////////PARTE DA COPIA //////////////////
    //Primeiro precisamos copiar toda a LSE para usá-la como retorno
    TLSE* resp = TLSE_inicializa();
    TLSE * aux = TLSE_inicializa();

    TLSE* a = l;
    while(a){
        aux = TLSE_insere(aux,a->info);
        a = a->prox;
    }

    TLSE *r = aux;
    while(r){
        resp = TLSE_insere(resp,r->info);
        r = r->prox;
    }


    //////////////////////ALGORITMO DE FATO ///////////////
    //Parte ímpar
    if(x % 2 != 0){
        TLSE* q = resp->prox;
        TLSE* ant = resp;
        //Tratando caso tenha que retirar o primeiro
        while(q->info == x){
            TLSE* temp = ant;
            ant =  ant ->prox;
            q = q ->prox;
            resp = ant;
            free(temp);
        }
        while(q->prox){
            if(q->prox->info == x){
                TLSE* temp = q;
                ant ->prox = q->prox;
                q = q ->prox;
                free(temp);
            } else {
                q = q ->prox;
                ant = ant ->prox;
            }
        }
    } else {
    //Parte par (retira depois)
        TLSE* q = resp;
        while(q->prox){
            if(q->info == x) {
                TLSE* temp = q ->prox;
                q ->prox = temp->prox;
                q =  temp ->prox;
                free(temp);
            }
            else  q = q-> prox;
        }
    }
    return resp;
}

int main(void){
  int n;
  printf("Digite o n: ");
  scanf("%d", &n);
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

  TLSE* resp = retira(l,n);
  printf("A lista pos funcao: ");
  TLSE_imprime(resp);

  TLSE_libera(l);
  TLSE_libera(resp);
  return 0;
}