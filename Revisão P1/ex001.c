//Questão de ordenação usada como exemplo no quadro da aula de Struct

//1- Descresnte de média
//2- Crescente de nome
//3- Crescente de matricula

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno
{
    char nome[31], mat[10], email[31];
    float p1,p2;

} TALUNO;

int compara(const void *a, const void*b){
    TALUNO **pont_a = (TALUNO**) a;
    TALUNO **pont_b = (TALUNO**) b;

    TALUNO *aluno_a = (*pont_a);
    TALUNO *aluno_b = (*pont_b);

    if(((aluno_a->p1+aluno_a->p2)/2) > ((aluno_b->p1+aluno_b->p2)/2)) return -1;
    if(((aluno_a->p1+aluno_a->p2)/2) < ((aluno_b->p1+aluno_b->p2)/2)) return 1;

    //A strcmp retorna "1" se o primeiro é maior e "-1" se o segundo é maior
    if(strcmp(aluno_a->nome,aluno_b->nome) > 0) return 1;
    if(strcmp(aluno_a->nome,aluno_b->nome) < 0) return -1;

    if(strcmp(aluno_a->mat,aluno_b->mat) > 0) return 1;
    if(strcmp(aluno_a->mat,aluno_b->mat) < 0) return -1;

    return 0;
}

void ordenada_aluno(TALUNO **turma, int n){
    qsort(turma, n, sizeof(TALUNO*), compara);
}
