/*(3) Retirar todos os múltiplos de k de um vetor de inteiros.
Se o seu vetor é composto por {2, 3, 5, 4, 6, 8, 7, 9, 1},
 com tamanho 9, e k = 2, seu vetor deve se transformar em {3, 5, 7, 9, 1},
  com tamanho igual a 5.  O protótipo dessa função é o que segue: 
  void retira_mult_k(int *vet, int *novo_tam_vet, int k). 
  NÃO PODEMOS CRIAR VETORES AUXILIARES PRA RESOLVER ESSA QUESTÃO: USE SOMENTE ÍNDICES!!!*/

void retira_mult_k(int *vet, int *novo_tam_vet, int k){
    int tamanho_vet = sizeof(vet)/sizeof(int);
    int indice = 0;
    for(int i = 0; i < tamanho_vet; i++){
        if(vet[i] % k != 0){
            vet[indice] = vet[i];
            indice++;
        }
    }
    (*novo_tam_vet) = indice;
}