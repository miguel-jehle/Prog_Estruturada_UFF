#include <stdio.h>
#include <stdlib.h>

int **aloca(int lin, int col){
  int **resp = (int **) malloc(sizeof(int *) * lin), i;
  for(i = 0; i < lin; i++)
    resp[i] = (int *) malloc(sizeof(int) * col);
  return resp; 
}

void desaloca(int **mat, int lin){
  int i;
  for(i = 0; i < lin; i++) free(mat[i]);
  free(mat);
}

int* misc(int **mat, int lin, int col, int* tam){
  int cont = 0;
  int ver1 = 0;
  int ver2 = 0;
  int ver3 = 0;
  int ver4 = 0;

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

    //Vendo quantas caracteristicas foram obtidas
    if(ver1) cont++;
    if(ver2) cont++;
    if(ver3) cont++;
    if(ver4) cont++;

    //Criando o vetor de resposta
    int *resp = (int*)malloc(sizeof(int)*(cont+1));
    resp[0] = cont;

    //Preenchendo com as caracteristicas que foram obtidas
    for(int i = 1; i < cont+1; i++){
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
    //Enviando o tamanho por meio do cont
    (*tam) = cont;

    //Com o vetor de resposta feito, basta retorná-lo
    return resp;
}


int main(void){
  int n, m;
  while(1){
    scanf("%d%d", &n, &m);
    if((n <= 0) && (m <= 0)) return 0;
    if((n < 2) || (m < 2)) continue;

    int **mat = aloca(n, m), i, j;
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++) scanf("%d", &mat[i][j]);

    //ÚNICA OPERAÇÃO VÁLIDA => RETIRAR OS COMENTÁRIOS ABAIXO:
    
    int tam, *resp; 
    resp = misc(mat, n, m, &tam);
    for(i = 0; i < tam+1; i++) printf("%d ", resp[i]);
    printf("\n");
    free(resp); 

  
    desaloca(mat, n);
  } 
}
