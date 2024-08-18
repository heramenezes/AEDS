#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char sentenca[150];
  int quantos_char = 0;
  int quantas_maiusculas = 0;

  while (1) {
    scanf(" %[^\n]", sentenca); // le a linha ate o \n

    if (strcmp(sentenca, "FIM") == 0) {
      break; // encerra o loop se a string for FIM
    }

    quantos_char = strlen(sentenca); // achando o tamanho da string >:)

    quantas_maiusculas = 0; // reinicia a contagem de maiúsculas
    for (int i = 0; i < quantos_char; i++) { // loop de verificacao de caracteres da string
      if (sentenca[i] >= 'A' && sentenca[i] <= 'Z') { // se o caractere for maiusculo, conta pro contador 
        quantas_maiusculas++;
      }
    }

    printf("%d\n", quantas_maiusculas); // proxima linha
  }

  return 0;
}
