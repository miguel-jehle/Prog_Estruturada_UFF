/*(Q1) Considere a existência de uma estrutura que representa um ponto no espaço 2D. Escreva
uma função que indique se um ponto p está dentro de um retângulo, retornando um e, zero, caso
contrário. O retângulo é definido com dois vértices: o inferior esquerdo e o superior direito. O
protótipo desta função é o seguinte: int dentroRet (TPTO2D *inf, TPTO2D *sup,
TPTO2D *p).*/
#include<stdio.h>
#include<stdlib.h>

typedef struct infos
    {
        int x;
        int y;
    } TPTO2D;

int dentroRet (TPTO2D *inf, TPTO2D *sup,
TPTO2D *p){
    if (((p -> x) >= (inf -> x)) && ((p -> x) <= (sup -> x)) && ((p -> y) >= (inf -> y)) && ((p -> y) <= (sup -> y)) ) return 1;
    else return 0; 
}

int main(){
    TPTO2D inf;
    TPTO2D sup;
    TPTO2D p;

    printf("Digite as coordenadas do canto inferior esquerdo: ");
    scanf("%d", &inf.x);
    scanf("%d", &inf.y);

    printf("Digite as coordenadas do canto superior direito: ");
    scanf("%d", &sup.x);
    scanf("%d", &sup.y);

    printf("Digite as coordenadas do ponto: ");
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    
    if (dentroRet(&inf, &sup, &p)) printf("Esta dentro");
    else printf("Nao esta dentro");

    return 0;
}