#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//min -> max - 32
//min -> min + 32
void shift_troca_string(char *str){
    for (int i = 0; i < strlen(str); i++){
        if ((int)str[i] >= 65 && (int)str[i] <= 90){
            (int)str[i] + 32 - 1;
            if ((int)str[i] == 96) str[i] = (char)122;
        if (97 <= (int)str[i] <= 122){
            (int)str[i] - 32 -1;
            if ((int)str[i] == 64) str[i] = (char)90;
        }
        } 
    }
}

int main(){
    char palavra[50];
    printf("Insira a palvrada que sera shiftada: ");
    scanf("%s", palavra);
    shift_troca_string(palavra);
    printf("A palavra shiftada fica: %s", palavra);
}