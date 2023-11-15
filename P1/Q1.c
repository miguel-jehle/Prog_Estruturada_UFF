/*A questão se baseava em receber um vetor de ponteiro na função TP *retira_k(TP **vet,int k, int n) na qual cada um dos ponteiros destre vetor
aponta para uma struct. A struct padrão tem os campos char data_nasc, char nome e int ins, e devemos retornar para a main a k-ésima pessoa deste vetor
caso ele estivesse ordenado com os seguintes parâmetros:
1- Mais velhos primeiros
2- Ordem crescente de nome
3- Número de ins no SUS 

OBS: O vetor em si não pode ser ordenado e o elemento k no vetor ORIGINAL deve ser retirado (mete NULL no lugar)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definindo a struct
typedef  struct paciente{
    char nome[11];
    char data_nasc[9];
    int insc;
} TP;

//Cabeçalho das funções usadas
TP *retira_k(TP **vet,int k, int n);

int compara(const void *a, const void *b);



int main(void){
    //Inicializando e recebendo as variáveis que serão usadas
    int n, k;
    printf("Digite a quantidade de pacientes: ");
    scanf("%d", &n);

    printf("Digite o k-esimo paciente que deseja vacinar: ");
    scanf("%d", &k);

    //Criando o vetor que será preenchido com os ponteiros de structs
    TP **vet = (TP**)malloc(sizeof(TP*)*n);

    //Criando cada ponteiro e preenchendo as suas structs respectivas
    for(int i = 0; i < n; i++){
        vet[i] = (TP*)malloc(sizeof(TP));
        printf("Digite o nome do paciente %d: ", i);
        scanf("%s", vet[i]->nome);

        printf("Digite a data de nascimento(ddmmaaaa) do paciente %d: ", i);
        scanf("%s", vet[i]->data_nasc);

        printf("Digite o numero de insc do paciente %d: ", i);
        scanf("%d", &vet[i]->insc);

        printf("\n");
    }

    //Com o banco de dados feito, vamos chamar a função para pegar o k-ésimo paciente ordenado
    TP * paciente_k = retira_k(vet,k,n);

    //Printando o paciente_k que será vacinado    
    printf("O paciente %d eh o: %s, nascido em: %s, com numero de ins: %d ",k,paciente_k->nome,paciente_k->data_nasc,paciente_k->insc);

    //Vamos desalocar os vetores utilizados
    for(int i = 0; i < n; i++){
        free(vet[i]);
    }
    free(vet);

    return 0;
}



TP *retira_k(TP **vet,int k, int n){
    //Como não podemos ordenar o vetor original, vamos criar um aux e preencher com o anterior
    TP **vet_ord = (TP**)malloc(sizeof(TP*)*n); 

    for(int i = 0; i < n; i++){
        vet_ord[i] = (TP*)malloc(sizeof(TP));
        vet_ord[i] = vet[i];
    }

    //Vamos ordenar com o quick
    qsort(vet_ord,n,sizeof(TP*),compara);

    //Já com o vetor ordenado basta pegar o k-ésimo paciente
    //OBS: Não aloquei dinamicamente pois não teria onde dar free, tentei na main e não quis, então criei estatico mesmo
    TP *resp = vet_ord[k];

    //Antes de retornar precisamos descobrir onde está o k-ésimo na original e substituit por NULL
    for(int i = 0; i < n; i++){
        if(vet[i]==vet_ord[k]){
            vet[i] = NULL;
            break;
        }
    }

    //Feito somente como forma de verificação, não foi exigido pela questão
    printf("As ins ordenadas: \n");
    //Printando por verificação
    for(int i = 0; i < n; i++){
        printf("%d\n",vet_ord[i]->insc);
    }


    //Vamos desalocar o vetor auxiliar criado
    for(int i = 0; i < n; i++){
        free(vet_ord[i]);
    }
    free(vet_ord);

    //Enfim retornando a resposta
    return resp;
}



int compara(const void *a, const void *b){
    //Política de afirmação
    TP**pont_a = (TP**)a;
    TP**pont_b = (TP**)b;

    //Política de simplificação
    TP* pac_a = (*pont_a);
    TP* pac_b = (*pont_b);

    //Data por ano
    if(strcmp(&pac_a->data_nasc[4],&pac_b->data_nasc[4]) < 0) return -1;
    if(strcmp(&pac_a->data_nasc[4],&pac_b->data_nasc[4])> 0) return 1;

    //Data por mes
    if(strcmp(&pac_a->data_nasc[2],&pac_b->data_nasc[2]) < 0) return -1;
    if(strcmp(&pac_a->data_nasc[2],&pac_b->data_nasc[2]) > 0) return 1;

    //Data por dia
    if(strcmp(pac_a->data_nasc,pac_b->data_nasc) < 0) return -1;
    if(strcmp(pac_a->data_nasc,pac_b->data_nasc) > 0) return 1;

    //Por nome
    if(strcmp(pac_a->nome,pac_b->nome) < 0)return -1;
    if(strcmp(pac_a->nome,pac_b->nome) > 0)return 1;

    //Por inscrição
    if((pac_a->insc) < (pac_b->insc)) return -1;
    return 1;
}