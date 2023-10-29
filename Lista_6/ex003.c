/*(Q3) Considerando a definição de TALUNO da (Q2), escreva uma função que retorne a média
geral de uma determinada turma. O protótipo desta função é o seguinte: float media_geral
(TALUNO **mat, int n, char *turma).*/

#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

float media_geral(TALUNO **mat, int n, char *turma){
    float media = 0;
    int cont = 0;
    for(int i = 0; i < n; i++){
        if ((*mat[i] ->turma) == (*turma)){
            media += ((mat[i]->p1)+(mat[i]->p2))/2;
            cont += 1;
        }
    }
    media /= cont;

    return media;
}

int main(){
    int n;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    char turma;
    printf("Digite a turma que quer saber a media: ");
    scanf(" %c", &turma);


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

    
    float media = media_geral(mat_de_alunos, n, &turma);
    printf("A media geral da turma %c foi %.2f",turma,media );
    
    
    for(int i = 0; i < n; i++){
        free(mat_de_alunos[i]);
    }

    free(mat_de_alunos);

        return 0;
    
}