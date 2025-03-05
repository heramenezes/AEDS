#include <stdio.h>

int main (void){
    
    int pessoas, kilos, resto, ajuste;

    scanf("%d %d", &pessoas, &kilos);

    resto = kilos % pessoas;

    if (resto ==0){
        ajuste = 0;
    } else {
        ajuste = pessoas - resto;
    }

    printf("%d", ajuste);
}