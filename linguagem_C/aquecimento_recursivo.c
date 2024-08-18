#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contando (int contador, char* sentenca, int tamanho, int indice){
  if (indice == tamanho){
    return contador;
  }
  else{
    if (sentenca[indice] >= 'A' && sentenca[indice] <= 'Z') { // se o caractere for maiusculo 
      return contando (contador+1, sentenca, tamanho, indice+1);
    }
    else{
      return contando (contador, sentenca, tamanho, indice+1);
    }
  }
}

int main(void) {

  char sentenca[150];
  int quantos_char = 0;
  int quantas_maiusculas = 0;

  while (1) {
    scanf(" %[^\n]", sentenca); // le a linha ate o \n

    quantos_char = strlen(sentenca);

    if (strcmp(sentenca, "FIM") == 0) { // comparando se a minha string eh igual a string FIM
      break; 
    }
    
    printf("%d\n", contando(0, sentenca, quantos_char, 0)); 
  }

  return 0;
}
