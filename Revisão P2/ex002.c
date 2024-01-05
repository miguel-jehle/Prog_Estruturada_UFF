/*Questao 2
Tenho uma pilha, e é passado um n qualquer. Dado este n, tenho que manter minha pilha original inalterada
 (com mesma ordem de elementos), e criar uma nova pilha (copia), onde a toda vez que encontrar o n,
  retirar o antecessor e predecessor desta copia, mantendo a ordem como fosse a pilha original, somente
   retirado os elementos pela regra do antecessor e sucessor.
*/

#include"TP.c"

TP* retira(TP* p, int k){
    TP *aux1 = TP_inicializa();
    TP *aux2 = TP_inicializa();
    TP *resp = TP_inicializa();
    int cont = 0;

    //Descobrindo quantos tem e já salvando os valores na aux1
    while(!TP_vazia(p)){
        int x = TP_pop(p);
        TP_push(aux1,x);
        cont++;
    }

    int ver = -1;
    int cont2 = 0;
    for(int i = 0;i < cont; i++){
        //Tem que pegar os valores de x e devolver pra orginal
        int x = TP_pop(aux1);
        TP_push(p,x);

        if(i != ver){
            cont2++;
            TP_push(aux2,x);
            if(x == k){
                ver = i+1;
            }
        }
    }

    ver = -1;
    for(int i = 0; i<cont2;i++){
        int x = TP_pop(aux2);
        if(i != ver){
            TP_push(aux1,x);
            if(x == k){
                ver = i+1;
            }
        }
    }

    while(!TP_vazia(aux1)){
        int x = TP_pop(aux1);
        TP_push(resp,x);
    }

    return resp;
}

int main(void){
    int k;
    printf("Digite o k: ");
    scanf("%d", &k);
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    printf("A pilha original eh: \n");
    TP_imprime(p);
    printf("\n");

    TP* resp = retira(p, k);
    printf("A pilha pos funcao eh: \n");
    TP_imprime(resp);
    printf("\n");

    TP_libera(p);
    TP_libera(resp);

  return 0;
}