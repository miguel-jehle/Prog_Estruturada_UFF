/*Q7) Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).*/

//NOTAS:
//A ideia central deste algorítmo se baseia em pegar os nós pares, na ordem que aparecem,
//inserir uma copia no final e então excluir o nó original que estava no começo, assim,
//preservando a ordem mas mandando eles para o final como solictiado

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

void i_p (TLSE *l){
    //Para inserir no fim precisamos demarcar o ultimo nó e lembrar de andar ele sempre que um novo for adicionado
    TLSE* ult = l;
    TLSE* fim = l;
    while(ult->prox) {
        ult = ult ->prox;
        fim = fim ->prox;
    }
    //Criando o ponteiro que servirá para limitar nosso while
    
    //Com o ultimo demarcado, precisamos encontrar os nós pares
    TLSE *par = l;
    TLSE* ant = NULL;

    //Lembrar de verificar se o primeiro for par, pra não dar merda com o ant = NULL
    while(!ant && par->info % 2 == 0){
            //Demarco para destruir
            TLSE* tmp = par;
            //Crio o novo nó e preencho
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo -> info = par ->info;
            //Coloco ele no fim
            novo ->prox = ult ->prox;
            ult -> prox = novo;
            //Mando l apontar para o seguinte
            l = par ->prox;
            //Ando com o par para não perdelo
            par = par -> prox;
            //Destruo o nó original
            free(tmp);
            //Atualizo o ultimo para usá-lo em futuras trocas
            ult = ult ->prox;
    }
    
    while(par != fim){
        
        if(par->info % 2 == 0){
            //Demarco para destruir
            TLSE* tmp = par;
            //Crio novo nó e preencho 
            TLSE* novo = (TLSE*)malloc(sizeof(TLSE));
            novo ->info = par ->info;
            //Encaixo no fim
            novo->prox = ult->prox;
            ult->prox = novo;

            //Mando anterior apontar para o depois do marcado
            ant ->prox = par->prox;
            //Percorro par para não perde-lo
            par = par ->prox;
            //Destruo o demarcado que foi copiado e jogado para o final
            free(tmp);
            //E atualizo o vetor ultimo, para usá-lo na proxima atualização
            ult = ult ->prox;
        }else{
            ant = par;
            par = par ->prox;
        }
    }
    printf("l-> info %d\nl->prox->info %d\nl->prox->prox->info %d \nl->prox->prox->prox->info %d\n ",l->info, l->prox->info, l->prox->prox->info, l->prox->prox->prox->info);
    return;
}

int main(void){
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

  i_p(l);
  printf("Agora o resultado da funcao criada: ");
  TLSE_imprime(l);

  TLSE_libera(l);

  return 0;
}

