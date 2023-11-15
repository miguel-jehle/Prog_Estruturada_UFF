/*(Q2) Implemente uma função em C que receba uma string como parâmetro e retorne uma nova string
com todos os caracteres minúsculos substituídos pelo caracter ‘?’. Por exemplo, se for passada a
string “740-Charitas-Leme”, a função deve retornar a string “740-Ch?r?t?s-L?m?”. A assinatura desta
função deve ser char * codifica (char *str). A string passada como parâmetro não pode ser alterada.
O espaço de memória para a nova string deve ser alocado dinamicamente.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Fazendo para minusculas

// Lembretes e aprendizados, quando for fazer uma copia para retorno, o tamanho será o tamanho da antiga mais um.
// Ao final da nova, sempre colocar \0 na ultima posição, podemos fazer isso dentro do for vendo se o i = 

char *codifica (char *str){
    char *resp = (char*)malloc(sizeof(char)*(strlen(str)+1));
    for(int i = 0; i < strlen(str); i++){
        if((int)str[i] >= 97 && (int)str[i] <= 122){
          resp[i] = '?';  
        }
        else resp[i] = str[i];

    }
    resp[strlen(str)] = '\0';

    return resp;
}

int main(void){
    char *string = (char*)malloc(sizeof(char)*50);

    scanf(" %49[^\n]", string);

    char *codificada = codifica(string);

    printf("%s\n", codificada);
    
    free(string);
    free(codificada);
    return 0;
}