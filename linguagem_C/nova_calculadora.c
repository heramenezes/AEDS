#include <stdio.h>

int contagem_algarismos(
    int numero_x,
    int contador) { // cria um loop onde quando o numero_x for passando por
                    // todas as casinhas (algarismos), vai adicionando no meu
                    // contador de contador, que é o numero de casas que o
                    // numero_x tem
  if (numero_x == 0) {
    printf("%d", contador);
  } else {
    return contagem_algarismos(numero_x / 10, contador + 1);
  }
}

int remover_algarismo(int numero1, int indice) {
  if (numero1 == 0) {
    return 0;
  } else if (indice == 0) {
    return remover_algarismo(numero1 / 10, -1) * 10;
  } else {
    int digito = numero1 % 10;
    return (remover_algarismo(numero1 / 10, indice - 1) * 10) + digito;
  }
}

int adicionar_algarismo(int numero1, int indice, int novo_numero) {
  if (numero1 == 0) {
    return novo_numero;
  } else if (indice == 0) {
    return (adicionar_algarismo(numero1 / 10, -1, novo_numero) * 10) +
           (numero1 % 10);
  } else {
    return (adicionar_algarismo(numero1 / 10, indice - 1, novo_numero) * 10) +
           (numero1 % 10);
  }
}
int main() {
  int numero_x = 0, numero_y = 0, opcao = 0, indice = 0, novo_numero = 0;
  scanf("%d%*c", &numero_x);
  scanf("%d%*c", &opcao);
  while (opcao != 0) {
    switch (opcao) {
    case 1:
      // REMOVER ALGARISMO
      scanf("%d%*c", &indice);
      numero_x = remover_algarismo(numero_x, indice);
      //
    case 2:
      // ADICIONAR ALGARISMO
      scanf("%d%*c", &indice);
      scanf("%d%*c", &novo_numero);
      numero_x = adicionar_algarismo(numero_x, indice, novo_numero);
      break;
    //
    case 3:
      // QUANTOS ALGARISMOS DE X
      contagem_algarismos(numero_x, 0);
      break;
    //
    case 11:
      printf("%d", numero_x);
      break;
    }
    scanf("%d%*c", &opcao);
  }
  return 0;
}