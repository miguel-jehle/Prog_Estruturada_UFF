/*A questão era uma do beecrowd adptada, na qual havia um contexto de maratona de programação, na qual desejava-se
obter as seguintes caractrísticas:
1- Nenhum competir conseguir fazer todas as questões
2- Todos os problemas terem ao menos uma pessoa que tenha feito
3- Nenhum problema tenha sido feito por todos os competidores
4- Todos os competidores tenham feito ao menos uma questão

A função exigida era int *resp(int **mat, int lin, int col) na qual deveriamos retornar um vetor contendo quantas destas
características foram obtidas e quais delas foram obtidas, nesta ordem.

A matriz recebida se trata de uma matriz de tamanho variável na qual caso tenha 1 na posição i,j significa que o jogador
i resolveu o problema j, e 0 caso não.

OBS: Como conclusão da interpretação, temos que:
1- Não pode ter linha de "1"
2- Não pode ter coluna de "0"
3- Não pode ter coluna de "1"
4- Não pode ter linha de "0"
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Cabeçalho das funções que serão utilizadas
int *resposta(int **mat, int lin, int col);

//FUNÇÃO PRINCIPAL
int main(void){
    int lin, col;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &lin);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &col);

    //Criando a matriz e preenchendo
    int **mat = (int**)malloc(sizeof(int*)*lin);

    for(int i = 0; i < lin; i++){
        mat[i] = (int*)malloc(sizeof(int)*col);
    }

    printf("Digite os numeros da matriz: ");
    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    //Agora com a matriz preenchida, vamos chamar a função que nos retornará a resposta
    int *resp = resposta(mat,lin, col);

    //Aqui uma malandragem para printar já que não temos mais acesso a variavel cont
    /*int i = 0;
    while(resp[i]){ //Vamos percorrer o vetor printando cada elemento até chegar no nulo(\0)
        printf("%d ",resp[i]);
        i++;
    }*/
    
    //Desalocando os vetores utilizados na questão
    for(int i = 0; i <  lin; i++){
        free(mat[i]);
    }
    free(mat);
    free(resp);

    return 0;
}


//FUNÇÃO SOLICITADA
int *resposta(int **mat, int lin, int col){
    //Criando o contador de caracteristicas e um verificador para cada uma dela;
    int ver1 = 0;
    int ver2 = 0;
    int ver3 = 0;
    int ver4 = 0;
    int cont = 0;

    //Verificando a primeira caracteristica(Se não tem linha de "1");
    for(int i = 0; i < lin; i++){
        ver1 = 1;
        for(int j = 0; j < col; j++){
            ver1 += mat[i][j];
        }
        if(ver1 == col+1){
            ver1 = 0;
            break;
        } 
    }

    //Verificando a segunda caracteristica(Se não tem coluna de "0")
    for(int i = 0; i < lin; i++){
        ver2 = 0;
        for(int j = 0; j < col; j++){
            ver2 += mat[j][i];
        }
        if(ver2 == 0){
            ver2 = 0; //Puro preciosismo
            break;
        }
    }

    //Verificando a terceira caracteristica(Se não tem coluna de "1")
    for(int i = 0; i < lin; i++){
        ver3 = 1;
        for(int j = 0; j < col; j++){
            ver3+= mat[j][i];
        }
        if(ver3 == lin+1){
            ver3 = 0;
            break;
        }
        
    }

    //Verificando a quarta caracteristica(Se não tem linha de "0")
    for(int i = 0; i < lin; i++){
        ver4 = 0;
        for(int j = 0; j < col; j++){
            ver4 += mat[i][j];
        }
        if (ver4 == 0){
            ver4 = 0;
            break;
        }
        
    }

    printf("Os verificadores: %d, %d, %d, %d\n", ver1,ver2,ver3,ver4);

    //Vendo quantas caracteristicas foram obtidas
    if(ver1) cont++;
    if(ver2) cont++;
    if(ver3) cont++;
    if(ver4) cont++;

    //Criando o vetor de resposta
    int *resp = (int*)malloc(sizeof(int)*cont);
    resp[0] = cont;

    //Preenchendo com as caracteristicas que foram obtidas
    for(int i = 1; i < cont; i++){
        if(ver1 != 0){
            resp[i] = 1;
            i++;
        }
        if(ver2 != 0){
            resp[i] = 2;
            i++;
        }
        if(ver3 != 0){
            resp[i] = 3;
            i++;
        }
        if(ver4 != 0){
            resp[i] = 4;
            i++;
        }
    }

    printf("A resposta eh: ");
    for(int i = 0; i < lin; i++){
        printf("%d ", resp[i]);
    }

    //Com o vetor de resposta feito, basta retorná-lo
    return resp;
}
