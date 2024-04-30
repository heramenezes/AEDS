#include <stdio.h>

int main() {
  int angulo = 0;

  scanf("%d", &angulo);

  // Ver se angulo está no eixo
  if (angulo % 90 == 0 && angulo > 0) { //Isso aqui pega o resto da divisao do primeiro eixo (90). Se a divisao for 0, o angulo está no eixo.
    printf("Este angulo se encontra em um dos eixos\n");
  } else if (angulo % 90 == 0 && angulo < 0) {
    printf("Este angulo se encontra em um dos eixos\n");
  }

  // Definicao do quadrante
  if (angulo >= 0) { // quando o angulo for positivo, vai dividir por 360 e o
                     // resto vai definir o quadrante
    if (angulo % 360 <= 90 && angulo > 0) {
      printf("Primeiro quadrante\n");
    }
    if (angulo % 360 > 90 && angulo <= 180) {
      printf("Segundo quadrante\n");
    }
    if (angulo % 360 > 180 && angulo <= 270) {
      printf("Terceiro quadrante\n");
    }
    if (angulo % 360 > 270 && angulo <= 360) {
      printf("Quarto quadrante\n");
    }
  }

  if (angulo <
      0) { // quando o angulo for negativo, vai transformar o angulo em positivo
           // e inverte as condicoes de verificacao do quadrante
    angulo = angulo * (-1);
    if (angulo % 360 <= 90 && angulo > 0) {
      printf("Quarto quadrante\n");
    }
    if (angulo % 360 > 90 && angulo <= 180) {
      printf("Terceiro quadrante\n");
    }
    if (angulo % 360 > 180 && angulo <= 270) {

      printf("Segundo quadrante\n");
    }
    if (angulo % 360 > 270 && angulo <= 360) {
      printf("Primeiro quadrante\n");
    }
    angulo = angulo * (-1);
  }

  // Numero de voltas e sentido horario e anti-horario
  if (angulo < 0) {//O numero de voltas esta como inteiro, entao se eu pegar um angulo e dividir por 360, o resultado sera o valor mais proximo abaixo do resultado da divisao.
    printf("%d volta(s) sentido horario\n", (angulo * (-1) / 360));
  } else if (angulo >= 0) {
    printf("%d volta(s) sentido antihorario\n", (angulo / 360));
  }
  
  // Quantos graus faltam para proxima volta
  if (angulo < 0) {//isso aqui vai olhar o resto da divisao do angulo por 360 e pegar esse resto e subtrair de 360, dando portanto, quanto falta para completar mais uma volta
    angulo = angulo * (-1);
    printf("Falta(m) %d graus (sentido horario) para completar %d voltas\n",
           360 - (angulo % 360), (angulo / 360) + 1);
  } else if (angulo >= 0) {
    printf(
        "Falta(m) %d graus (sentido antihorario) para completar %d volta(s)\n",
        360 - (angulo % 360), (angulo / 360) + 1);
  }

  return 0;
}