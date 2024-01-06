#include"TF.h"

struct fila{
    int n_elem;
    int ini;
    int vet[5];
};

TF* TF_inicializa(){
    TF* f = (TF*)malloc(sizeof(TF));
    f->n_elem = 0;
    f->ini= 0;
    return f;
}

int TF_vazia(TF* f){
    return (f->n_elem == 0);
}

int TF_retira(TF* f){
    if(TF_vazia(f)) exit(1);
    int x = f->vet[f->ini];
    f->ini++;
    f->n_elem--;
    return x;
}

void TF_insere(TF* f,int x){
    //Verifico se tem como inserir mais elementos
    if(f->n_elem == 5){
        printf("Prezado usuario: EXCEDEU O LIMITE DE NUMEROS PORRA!!!!");
        exit(1);
    }
    //Verifico se o inicio não está no primeiro, e se for o caso, jogo todos os valores para o início
    if(f->ini != 0){
        for(int i = 0; i < f->n_elem; i++){
            f->vet[i] = f->vet[f->ini];
            f->ini++;
        }
    }
    //Ao final tendo certeza que os elementos foram jogados para o começo, aponto ini para o 0
    f->ini = 0;

    //Agora tendo certeza que não há espaços no começo e ciente de que há espaco livro, basta inserir no fim
    f->vet[f->n_elem] = x;
    f->n_elem++;
} 

void TF_libera(TF* f){
    free(f);
}

void TF_imprime(TF* f){
    if(!TF_vazia(f)){
        for(int i = f->ini; i < f->n_elem+f->ini; i++){
            printf("%d ", f->vet[i]);
        }
    }
}
