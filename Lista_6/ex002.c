/*(Q2) Dada a estrutura que representa o cadastro de um aluno numa disciplina:

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

Escreva uma função que imprima os nomes dos alunos aprovados por média em cada uma das
turmas. O aluno será considerado aprovado se a média aritmética das notas das suas provas for
maior ou igual a SEIS. O protótipo desta função é o seguinte: void imprime (TALUNO **mat,
int n).*/
#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

void imprime (TALUNO **mat,int n){
    for(int i = 0; i < n; i++){
       float media = ((mat[i] -> p1) + (mat[i] -> p2))/2;
       if (media >= 6.0){
        printf("O aluno %s da turma %s e matricla %s foi aprovado com media: %.2f \n", mat[i]->nome, mat[i]->turma, mat[i]->mat, media);
       }
       else{
         printf("O aluno %s da turma %s e matricla %s NAO foi aprovado com media: %.2f \n", mat[i]->nome, mat[i]->turma, mat[i]->mat, media);
       }
    }
}

int main(){
    int n;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    TALUNO **mat_de_alunos = (TALUNO**)malloc(sizeof(TALUNO*)*n);

    for(int i = 0; i < n; i++){
        mat_de_alunos[i] = (TALUNO*)malloc(sizeof(TALUNO));

        printf("Digite o nome do aluno: ");
        scanf("%s", mat_de_alunos[i]->nome);
        
        printf("Digite a matricula do aluno: ");
        scanf("%s", mat_de_alunos[i]->mat);

        printf("Digite a turma do aluno: ");
        scanf("%s", mat_de_alunos[i]->turma);

        printf("Digite a nota da p1 do aluno: ");
        scanf("%f", &mat_de_alunos[i]->p1);

        printf("Digite a nota da p2 do aluno: ");
        scanf("%f", &mat_de_alunos[i]->p2);
    }

    
    imprime(mat_de_alunos, n);
    
    
    for(int i = 0; i < n; i++){
        free(mat_de_alunos[i]);
    }

    free(mat_de_alunos);

        return 0;
    
}