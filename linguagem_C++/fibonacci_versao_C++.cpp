#include <iostream>
using namespace std; 
int main() {
  int numero_atual = 0, proximo_numero = 1, guardador_numero = 0, quantos_numeros_sequencia = 0;  // declaracao de variaveis para problema + definicao de valor para nao dar problema em outros compiladores (as duas primeiras variaveis começam com 0 e 1 porque são os dois primeiros numeros da sequencia de fibonacci)

  cin>>quantos_numeros_sequencia; // lendo quantos numeros o usuario quer da sequencia

  // loop da para determinar a minha sequencia, sendo que ela encerra quando o meu número de ciclos for maior que a quantidade de numeros que o usuário quer em sua sequencia
  for (int i=0; i<quantos_numeros_sequencia; i++){ 
    cout<<numero_atual<<"\n"; // printando na tela do usuário o numero que estamos analizando em cada loop
    guardador_numero = numero_atual; // guardando o valor do numero atual
    numero_atual = proximo_numero; // atualizando o valor do numero atual para a próxima execução (ou seja, o proximo numero)
    proximo_numero = guardador_numero + numero_atual; // definindo o valor do próximo número para próxima execução (sendo ele sempre a soma do valor atual com seu antecessor)
  }
}