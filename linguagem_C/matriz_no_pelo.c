#include <stdio.h>
#include <stdlib.h>

void ler_matriz(int *matriz, int linhas, int colunas, int indice_linhas, int indice_colunas){
    if (indice_linhas<linhas){
        if(indice_colunas<colunas){
            scanf("%d%*c", (matriz + (indice_linhas*colunas) + indice_colunas));
            ler_matriz(matriz, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            ler_matriz(matriz, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

void printar_matriz(int *matriz, int linhas, int colunas, int indice_linhas, int indice_colunas){
    if (indice_linhas < linhas){
        if (indice_colunas < colunas){
            printf("%d ", *(matriz + (indice_linhas * colunas) + indice_colunas));
            printar_matriz(matriz, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            printf("\n");
            printar_matriz(matriz, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

void duplicar_matriz(int *matriz, int *matriz2, int linhas, int colunas, int indice_linhas, int indice_colunas){
    if (indice_linhas < linhas){
        if (indice_colunas < colunas){
            *(matriz2 + (indice_linhas*colunas) + indice_colunas) = (*(matriz + (indice_linhas*colunas) + indice_colunas)*2);
            duplicar_matriz(matriz, matriz2, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            printf("\n");
            duplicar_matriz(matriz, matriz2, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

void transpor_matriz(int* matriz, int* matriz2, int linhas, int colunas, int indice_linhas, int indice_colunas){
     if (indice_linhas < linhas){
        if (indice_colunas < colunas){
            *(matriz2 + (indice_colunas*linhas) + indice_linhas) = *(matriz + (indice_linhas*colunas) + indice_colunas);
            transpor_matriz(matriz, matriz2, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            transpor_matriz(matriz,matriz2, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

void espelhar_matriz_horizontal(int* matriz, int* matriz2, int linhas, int colunas, int indice_linhas, int indice_colunas){
     if (indice_linhas < linhas){
        if (indice_colunas < colunas){
            *(matriz2 + indice_linhas*colunas + (colunas - indice_colunas - 1)) = *(matriz + indice_linhas*colunas + indice_colunas);
            espelhar_matriz_horizontal(matriz, matriz2, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            espelhar_matriz_horizontal(matriz,matriz2, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

void espelhar_matriz_vertical(int* matriz, int* matriz2, int linhas, int colunas, int indice_linhas, int indice_colunas){
     if (indice_linhas < linhas){
        if (indice_colunas < colunas){
            *(matriz2 + (linhas - indice_linhas - 1)*colunas +indice_colunas) = *(matriz + indice_linhas*colunas + indice_colunas);
            espelhar_matriz_vertical(matriz, matriz2, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            espelhar_matriz_vertical(matriz,matriz2, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

void espelhar_matriz_diagonal(int* matriz, int* matriz2, int linhas, int colunas, int indice_linhas, int indice_colunas){
     if (indice_linhas < linhas){
        if (indice_colunas < colunas){
            *(matriz2 + ((linhas - indice_linhas -1)*colunas) + (colunas -indice_colunas - 1)) = *(matriz + indice_linhas*colunas + indice_colunas);
            espelhar_matriz_diagonal(matriz, matriz2, linhas, colunas, indice_linhas, indice_colunas+1);
        } else {
            espelhar_matriz_diagonal(matriz,matriz2, linhas, colunas, indice_linhas+1, 0);
        }
    }
}

int main(){
    int linhas=0,  colunas=0,  opcao=0;

    scanf("%d", &linhas);
    scanf("%d", &colunas);
    scanf("%d", &opcao);

    int *matriz = malloc(linhas*colunas*sizeof(int *));
    int *matriz2 = malloc(colunas*linhas*sizeof(int *));

    ler_matriz(matriz, linhas, colunas, 0, 0);

        switch (opcao){
            case 1:
            duplicar_matriz(matriz, matriz2, linhas, colunas, 0, 0);
            printar_matriz(matriz2, linhas, colunas, 0, 0);
            break;

            case 2:
            transpor_matriz(matriz, matriz2, linhas, colunas, 0, 0);
            printar_matriz(matriz2, colunas, linhas, 0, 0);
            break;

            case 3:
            espelhar_matriz_horizontal(matriz, matriz2, linhas, colunas, 0, 0);
            printar_matriz(matriz2, linhas, colunas, 0, 0);
            break;

            case 4: 
            espelhar_matriz_vertical(matriz, matriz2, linhas, colunas, 0, 0);
            printar_matriz(matriz2, linhas, colunas, 0, 0);
            break;

            case 5: 
            espelhar_matriz_diagonal(matriz, matriz2, linhas, colunas, 0, 0);
            printar_matriz(matriz2, linhas, colunas, 0, 0);
            break;
        }
    return 0;
}

