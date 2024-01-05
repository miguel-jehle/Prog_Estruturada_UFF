//CORREÇÕES REALIZADAS:
//    Linha 15: Mudei a inicialização do contador para "= 0"    
//    Linha 37 e 38: Inicializei as variáveis dentro do for mais externo
//    Linha 43 até 56: São trechos desnecessários, como conversamos, mas fiz por pura segurança, por favor, considera
//                     que apesar de inútil, ela não quebra meu código. Falei disso na linha 42.
//    Linha 59 até 70: Trecho que corrigimos juntos em sala, por favor reconsidere!!!


#include "TP.c"
#include<limits.h>

TP *merge(TP **vetp, int n){
  //////////////////Criando a copia/////////////////////////
  TP * copia[n];
  int cont_val = 0;
  for(int i = 0; i < n; i++){
    copia[i] = TP_inicializa();
    TP* bckp = TP_inicializa();
    while(!TP_vazia(vetp[i])){
      int x = TP_pop(vetp[i]);
      TP_push(copia[i],x);
      cont_val++;
      TP_push(bckp,x);
    }
    //Devolve
    while(!TP_vazia(bckp)){
      int x  = TP_pop(bckp);
      TP_push(vetp[i],x);
    }
    TP_libera(bckp);
  }
  ///////////////////////////////////////////////

  //Com a copia feita vamos inicializar e iniciar o processo de achar as maiores
  TP *resp =  TP_inicializa();
  for(int i = 0; i < cont_val; i++){
    int ind;
    int maior = INT_MIN;
    for(int j = 0; j < n; j++){
      TP* bckp = TP_inicializa();

        //Deixei essa parte desnecessária para mostrar que mesmo sendo burrice, foi consciente e funciona (esta mensagem foi solicitada por você :)) por favor não ver como ofensa!!!
        while(!TP_vazia(copia[j])){
          int x = TP_pop(copia[j]);
          if(x > maior){
            maior = x;
            ind = j;
          }
          TP_push(bckp,x);
        }
        //Devolve
        while(!TP_vazia(bckp)){
          int x = TP_pop(bckp);
          TP_push(copia[j],x);
        }
        TP_libera(bckp);
      
      }
        //Procura e retira o maior da sua pilha
        // TP *save = TP_inicializa();
        // while(!TP_vazia(copia[ind])){
        //   int x = TP_pop(copia[ind]);
        //   if( x == maior ) break;
        //   TP_push(save,x);
        // }
        // while(!TP_vazia(save)){
        //   int x = TP_pop(save);
        //   TP_push(copia[ind],x);
        // }
        // TP_libera(save);
      TP_push(resp, maior);
      TP_pop(copia[ind]);
    }
    //Libera as pilhas a copia
    for(int i = 0; i < n; i++){
      TP_libera(copia[i]);
    }
  return resp;
  }


int main(void){
  int n;
  printf("Digite o numero de pilhas... ");
  scanf("%d", &n);
  if(n <= 0) return 0;
  
  TP **vetp = (TP **) malloc(sizeof(TP*) * n);
  int i;
  for(i = 0; i < n; i++) vetp[i] = TP_inicializa();

  i = 0;
  while(i < n){
    printf("Digite a pilha %d em ordem decrescente... Quando for fornecido um elemento fora de ordem, a pilha não receberá mais elementos...\n", i + 1);
    int ant;
    scanf("%d", &ant);
    TP_push(vetp[i], ant);
    while(1){
      int aux;
      scanf("%d", &aux);
      if(aux > ant) break;
      TP_push(vetp[i], aux);
      ant = aux;
    }
    i++;
  }

  TP *resp = merge(vetp, n);
  TP_imprime(resp);
  TP_libera(resp);
  for(i = 0; i < n; i++) TP_libera(vetp[i]);
  free(vetp);
  return 0;
}
