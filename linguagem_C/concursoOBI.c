#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* IDEIA DO CODIGO: eu pensei que como a nota de corte vai ser determinada pelo maior numero, e esse maior 
numero eh determinado por um "for" que vai me dizer a nota de corte. pra isso eu tenho que ordenar a minha
string*/

void swap (int* todas_notas, int a, int b){ // miha funcao de troca de posicao
    int tmp;

    tmp = todas_notas[a];
    todas_notas[a] = todas_notas[b];
    todas_notas[b] = tmp;
}


int main(){

    int qtd_notas = 0, ordem_max =0;

    scanf("%d", &qtd_notas);
    scanf("%d", &ordem_max);

    int* todas_notas = (int*)malloc(qtd_notas*sizeof(int)); // definindo o tamamho do meu array de notas

    int indice = (qtd_notas-1);
    int nota_corte = 0;

    for (int i=0; i<qtd_notas; i++){ // scaneando as notas
        scanf(" %d", &todas_notas[i]);
    }



    for (int i=0; i<qtd_notas-1; i++){ // fazendo minha ordenacao com selecao, pra ficar em ordem crescente
        int menor = i;
        for (int j = (i+1); j<qtd_notas; j++){
            if (todas_notas[j] < todas_notas[menor]){
                menor = j;
            }
        }
        swap(todas_notas, i, menor);
    } 

    while (ordem_max >0){ // determinando a minha nota de corte
        nota_corte = todas_notas[indice];
        indice--;
        ordem_max--;
    }

    printf("%d", nota_corte);

    return 0;

}