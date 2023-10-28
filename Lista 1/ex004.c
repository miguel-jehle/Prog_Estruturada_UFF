#include <stdio.h>

int main(void){
    int n, f1, f2, menor;
    scanf("%d", &n);
    for(int i=0; i<n; i++){ // casos teste
        scanf("%d %d", &f1, &f2);
        menor = f1 >= f2 ? f2 : f1;
        for(int divisor=menor; divisor>=1; divisor--){
            if(f1 % divisor == 0 && f2 % divisor == 0){
                printf("%d\n", divisor);
                break;
            }
        }
    }
    return 0;
}