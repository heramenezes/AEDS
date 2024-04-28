#include <stdio.h>
int main(void) {

  int angulo, resto, volta;

  printf("Digite a medida de um angulo: ");
  scanf("%d", &angulo);

  if (angulo % 90 == 0) {
    printf("Este angulo se enconta em um dos eixos\n");
  }

  resto = angulo % 360;

  if (angulo < 0) {
    resto = 360 + resto;
  }

  if (resto > 0 && resto <= 90) {
    printf("Primeiro quadrante\n");
  }

  if (resto > 90 && resto <= 180) {
    printf("Segundo quadrante\n");
  }

  if (resto > 180 && resto <= 270) {
    printf("Terceiro quadrante\n");
  }

  if (resto > 270 && resto < 360) {
    printf("Quarto quadrante\n");
  }

  if (angulo < 0) {
    volta = angulo / 360;
    printf("%d volta(s) sentido horario\n", volta);
     printf("Falta(m) %d graus (sentido horario) para completar uma volta\n", 360 - ((angulo *-1) % 360));
    } else if (angulo >=0) {
    printf("%d volta(s) sentido anti-horario\n", volta);
     printf("Falta(m) %d graus (sentido anti-horario) para completar uma volta\n", 360 - (angulo % 360));
  }

  return 0;
}
