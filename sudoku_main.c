
#include <stdio.h>
#include <stdlib.h>

int main() {
  int opcoes, x, y, substituicao, linha[9], coluna[9], repete, repete2, repete_quadrante, qual_linha, qual_coluna, qual_quadrante;
  int sudoku[9][9]; // formação da matriz

  for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        scanf("%d%*c", &sudoku[i][j]);
      }
   }

  while (opcoes !=0){
  switch (opcoes){
  case 1:// mudar o valor de algum lugar da matriz
    scanf("%d", &x);

    scanf("%d", &y);

    scanf("%d", &sudoku[x][y]);
    break;

  case 2:
      repete = 0;
      scanf("%d%*c", &qual_linha);

      for (int j = 0; j < 9; j++) {
        for (int n = j + 1; n < 9; n++) {
          if (sudoku[qual_linha][j] == sudoku[qual_linha][n]) {
            repete++;
          }
        }
      }

      if (repete > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

  case 3:

  scanf("%d%*c", &qual_coluna);
      repete = 0;
      for (int i = 0; i < 9; i++) {
        for (int n = i + 1; n < 9; n++) {
          if (sudoku[i][qual_coluna] == sudoku[n][qual_coluna]) {
            repete++;
          }
        }
      }
      if (repete > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

  case 4: 
  scanf("%d%*c", &qual_quadrante);
   repete2 = 0;
   if( qual_quadrante == 0){
      for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            for (int b = 0; b < 3; b++) {
              for (int n = 0; n < 3; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
      }
    if( qual_quadrante == 1){
      for (int i = 0; i < 3; i++) {
          for (int j = 3; j < 6; j++) {
            for (int b = 0; b < 3; b++) {
              for (int n = 3; n < 6; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
    }
    if ( qual_quadrante == 2){
    for (int i = 0; i < 3; i++) {
          for (int j = 6; j < 9; j++) {
            for (int b = 0; b < 3; b++) {
              for (int n = 6; n < 9; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
    }
    if (qual_quadrante == 3){
    for (int i = 3; i < 6; i++) {
          for (int j = 0; j < 3; j++) {
            for (int b = 3; b < 6; b++) {
              for (int n = 0; n < 3; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
      }
    if ( qual_quadrante == 4){
    for (int i = 3; i < 6; i++) {
          for (int j = 3; j < 6; j++) {
            for (int b = 3; b < 6; b++) {
              for (int n = 3; n < 6; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
      }
    if ( qual_quadrante == 5){
      for (int i = 3; i < 6; i++) {
          for (int j = 6; j < 9; j++) {
            for (int b = 3; b < 6; b++) {
              for (int n = 6; n < 9; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
    }
    if ( qual_quadrante == 6){
    for (int i = 6; i < 9; i++) {
          for (int j = 0; j < 3; j++) {
            for (int b = 6; b < 9; b++) {
              for (int n = 0; n < 3; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
    }
    if ( qual_quadrante == 7){
    for (int i = 6; i < 9; i++) {
          for (int j = 3; j < 6; j++) {
            for (int b = 6; b < 9; b++) {
              for (int n = 3; n < 6; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
    }
    if ( qual_quadrante == 8){
    for (int i = 6; i < 9; i++) {
          for (int j = 6; j < 9; j++) {
            for (int b = 6; b < 9; b++) {
              for (int n = 6; n < 9; n++) {
                if (i != b || j != n) {
                  if (sudoku[i][j] == sudoku[b][n]) {
                    repete2 ++;
                  }
                }
              }
            }
          }
        }
    }
    if (repete2 > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;

 case 5:
      repete = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
      }

      for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
          for (int n = i + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[n][j]) {
              repete++;
            }
          }
        }
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
        for (int j = 3; j < 6; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
        for (int j = 6; j < 9; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
      }

      for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
        for (int j = 3; j < 6; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
        for (int j = 6; j < 9; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
      }

      for (int i = 6; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
        for (int j = 3; j < 6; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
        for (int j = 6; j < 9; j++) {
          for (int n = j + 1; n < 9; n++) {
            if (sudoku[i][j] == sudoku[i][n]) {
              repete++;
            }
          }
        }
      }
      if (repete > 0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
      break;
 
  case 6: // vai imprimir a matriz bonitinha do sudoku
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf(" ");
        for (int j = 3; j < 6; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf(" ");
        for (int j = 6; j < 9; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf("\n");
      }
      printf("           \n");

      for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf(" ");
        for (int j = 3; j < 6; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf(" ");
        for (int j = 6; j < 9; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf("\n");
      }
      printf("           \n");

      for (int i = 6; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf(" ");
        for (int j = 3; j < 6; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf(" ");
        for (int j = 6; j < 9; j++) {
          printf("%d ", sudoku[i][j]);
        }
        printf("\n");
      }
      break;
    }
    scanf("%d%*c", &opcoes);
  }

  return 0;
}