#include<stdio.h>

int ordenada_vetor(int k,int* v){
for (int i = 0; i < k-1; i++){
    for (int j = 0; j < k-1-i; j++){
      if(v[j]>v[j+1]){
        int temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }     
    }
}
return v;
}

int main(){
    int n;
    scanf("%d",&n);
    do{
        int v[n];
        int indice;
        for (int i = 0; i < n; i++){
            scanf("%d",&v[i]);
        }

        int *v_ord = ordenada_vetor(n,v);

        for (int i = 0; i < n; i++){
            if (v[i] == v_ord[1]){
                indice = i + 1 ;
            }
        }
        
        printf("%d",indice);

        scanf("%d",&n);

    } while (n>1);
    return 0;
}