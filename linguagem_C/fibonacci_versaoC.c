#include <stdio.h>
#include <stdlib.h>
int main(void) {

  // EXEMPLO SEQUENCIA: 0 1 1 2 3 5 8 13 ...
  
  int numero_atual_sequencia = 0, proximo_numero_sequencia = 1, guardador_de_numeros = 0, quantos_numeros_da_sequencia = 0; // declaracao de variaveis para problema + definicao de valor para nao dar problema em outros compiladores (as duas primeiras variaveis começam com 0 e 1 porque são os dois primeiros numeros da sequencia de fibonacci)

  scanf("%d", &quantos_numeros_da_sequencia); // lendo o input do usuario de quantos numeros da sequencia ele quer que apareca

  // loop da para determinar a minha sequencia, sendo que ela encerra quando o meu número de ciclos for maior que a quantidade de numeros que o usuário quer em sua sequencia
  for (int i=0; i<quantos_numeros_da_sequencia; i++){ 
    printf("%d\n", numero_atual_sequencia); // printando na tela do usuário o numero que estamos analizando em cada loop
    guardador_de_numeros = numero_atual_sequencia; // guardando o valor do numero atual
    numero_atual_sequencia = proximo_numero_sequencia; // atualizando o valor do numero atual para a próxima execução (ou seja, o proximo numero)
    proximo_numero_sequencia = guardador_de_numeros + numero_atual_sequencia; // definindo o valor do próximo número para próxima execução (sendo ele sempre a soma do valor atual com seu antecessor)
  }
  
  return 0; // encerramento do programa
}