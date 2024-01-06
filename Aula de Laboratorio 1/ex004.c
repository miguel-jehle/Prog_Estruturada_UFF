/*(4) Escreva o método k_str que retorna todas as k strings, onde k é menor que
o tamanho da String original. Se sua string é "abc" e k for igual a 2, seu
código deve imprimir na tela as substrings "aa", "ba", "ca", "ab", "bb", "cb",
"ac", "bc" e "cc". Se sua string for "abc" e k for igual a 1, seu código deve
imprimir na tela as substrings "a", "b", "c". O protótipo dessa função é o que
segue: void k_str(char *str, int k).
DICA: USE RECURSÃO PARA RESOLVER ESSE PROBLEMA!!!*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void k_str(char *str, int k);

void k_str_2(char *str, int k, char *ant);

int main(){
    int tamanho;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    char palavra[tamanho];

    printf("Digite a string: ");
    scanf("%s", palavra);

    k_str(palavra, tamanho-1);
}

void k_str(char *str, int k){
    if (k > strlen(str)) printf("Prezado usuário, ta viajando!");

    char R[k];

    for (int L=0; L<(strlen(str)); L++){
        R[0] = str[L];
        k_str_2(str, k-1, &R[1]);
    }
}

void k_str_2(char *str, int k, char *ant){
    if (k==0) printf("%s", ant);
    else {
        for (int L=0; L<(strlen(str)); L++){
            ant[0] = str[L];
            k_str_2(str, k-1, &ant[1]);
        }
    }

}