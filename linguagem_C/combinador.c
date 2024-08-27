#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sequencia_1[80];
    char sequencia_2[80];

    while (1) {
        if (scanf("%79s", sequencia_1) != 1 || strcmp(sequencia_1, "EOF") == 0) {
            break;
        }

        
        if (scanf("%79s", sequencia_2) != 1 || strcmp(sequencia_2, "EOF") == 0) {
            break;
        }

        int tamanho_1 = strlen(sequencia_1);
        int tamanho_2 = strlen(sequencia_2);

        char *resultado = (char *)malloc((tamanho_1 + tamanho_2 + 1) * sizeof(char));

        int i = 0, j = 0, k = 0;


        while (i < tamanho_1 && j < tamanho_2) {
            resultado[k++] = sequencia_1[i++];
            resultado[k++] = sequencia_2[j++];
        }

      
        while (i < tamanho_1) {
            resultado[k++] = sequencia_1[i++];
        }

        
        while (j < tamanho_2) {
            resultado[k++] = sequencia_2[j++];
        }

        resultado[k] = '\0';  

        printf("%s\n", resultado);

        free(resultado); 
    }

    return 0;
}

