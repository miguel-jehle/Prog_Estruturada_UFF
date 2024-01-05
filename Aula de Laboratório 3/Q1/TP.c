#include"TP.h"

struct pilha{
    int topo;
    int vet[5];
};

TP* TP_inicializa(void){
    TP *p = (TP*)malloc(sizeof(TP));
    p->topo = 0;
    return p;
}

int TP_vazia(TP* p){
    if(p->topo == 0) return 1;
    return 0;
}

void TP_push(TP* p, int x){
    if(p->topo >= 5){
        printf("Prezado usuário: EXCEDEU O LIMITE DE NUMEROS PORRA!!!!!");
        exit(1);
    }
    p->vet[p->topo] = x;
    p->topo++;
    return;
}

int TP_pop(TP* p){
    if(TP_vazia(p)) exit(1);
    int x = p->vet[p->topo-1];
    p->topo--;
    return x;
}

void TP_libera(TP* p){
    free(p);
}

void TP_imprime(TP* p){
    if(TP_vazia(p)) return;
    for(int i = p->topo-1; i >= 0;i--){
        printf("%d\n", p->vet[i]);
    }
}
