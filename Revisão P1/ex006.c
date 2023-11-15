/*
(Q3) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "prefixo" da cadeia s de tamanho n (isto é, retire os n primeiros caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_inicio_n (char *str, int
n).
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void retira_inicio_n (char *str, int n){
    int indice = 0;
    for (int i = n; i < strlen(str); i++){
        str[indice] = str[i];
        indice++;
    }
    
    str[strlen(str)-n] = '\0';
}
int main(void){
    char palavra[50]; int n;
    
    printf("Digite o n: ");
    scanf("%d", &n);

    printf("Digite a string: ");
    scanf("%s", palavra);

    if(strlen(palavra) >= n){
        retira_inicio_n(palavra, n);
        printf("%s", palavra);
    }
    else printf("Erro!"); 

    return 0;
}