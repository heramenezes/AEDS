#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){

	int quantidadeNumeros = 0;

	scanf("%d", &quantidadeNumeros); // lendo quantos numeros vai ter

	getchar(); // pulando o \n
	
	FILE *arquivo = fopen("arquivoc.txt", "wt"); // abrindo arquivo pra escrever
	
	float numero = 0.0;

	for (int i = 0; i<quantidadeNumeros; i++){ // loop pra ler todos os numeros que user me passar
		scanf("%f", &numero);

		getchar();

		fprintf(arquivo, "%f\n", numero); // escrevendo no meu arquivo
	
	}

	fclose(arquivo); // fechando meu arquivo

	numero = 0.0;

	arquivo = fopen("arquivoc.txt","rt"); // abrindo pra leitura

	fseek(arquivo, 0, SEEK_END); // indo pro final do arquivo

	int localizador = ftell(arquivo)-8;
	
	for (int i=0; i< quantidadeNumeros; i++){

		while (localizador>=0 && fgetc(arquivo) != '\n'){ // vai fazer eu ir dde tras pra frente e nao  detectar as quebras de linha

			localizador--;
			fseek(arquivo,localizador,SEEK_SET);

		}

		fseek(arquivo,-1,SEEK_CUR);

		fscanf(arquivo, "%f" ,&numero);

		printf("%g\n", numero);
		
		localizador--;

		fseek(arquivo, localizador, SEEK_SET);
	}

	fclose(arquivo);
	return 0;
}
