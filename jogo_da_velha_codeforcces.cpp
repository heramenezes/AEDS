#include <iostream>
using namespace std;
bool win(char matriz[3][3], char caractere);



bool limite_caractere(char mat[3][3]) {
  int acumulador = 0, acumulador2 = 0;
  bool resultado = false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (mat[i][j] == 'X') {
        acumulador++;
      }
      if (mat[i][j] == '0') {
        acumulador2++;
      }
    }
  }
  if ((acumulador > 5 && acumulador2 > 4) || (acumulador - acumulador2 > 1) || acumulador2 > acumulador ||
      (win(mat, '0')&& acumulador2 != acumulador)||win(mat, 'X')&& acumulador2 == acumulador) {
    resultado = true;
  }
  return resultado;
}
bool verificando_linhas(char caractere, char matriz[3][3]) {
  if ((matriz[0][0] == caractere && matriz[0][1] == caractere && matriz[0][2] == caractere) ||
      (matriz[1][0] == caractere && matriz[1][1] == caractere && matriz[1][2] == caractere) ||
      (matriz[2][0] == caractere && matriz[2][1] == caractere && matriz[2][2] == caractere)) {
    return true;
  } else {
    return false;
  }
}
bool verificando_colunas(char caractere, char matriz[3][3]) {
  if ((matriz[0][0] == caractere && matriz[1][0] == caractere && matriz[2][0] == caractere) ||
      (matriz[0][1] == caractere && matriz[1][1] == caractere && matriz[2][1] == caractere) ||
      (matriz[0][2] == caractere && matriz[1][2] == caractere && matriz[2][2] == caractere)) {
    return true;
  } else {
    return false;
  }
}
bool win(char matriz[3][3], char caractere);

void lendo_matriz(char matriz[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matriz[i][j];
    }
  }
}

bool verificar_diagonais(char caractere, char matriz[3][3]) {
  if ((matriz[0][0] == caractere && matriz[1][1] == caractere && matriz[2][2] == caractere) ||
      (matriz[2][0] == caractere && matriz[1][1] == caractere && matriz[0][2] == caractere)) {
    return true;
  } else {
    return false;
  }
}

bool win(char matriz[3][3], char caractere) {
  if (verificando_linhas(caractere, matriz) || verificando_colunas(caractere, matriz) ||
      verificar_diagonais(caractere, matriz)) {
    return true;
  } else {
    return false;
  }
}
bool doiswins(char matriz[3][3]) {
  if (win(matriz, 'X') && win(matriz, '0')) {
    return true;
  } else {
    return false;
  }
}

bool legal(char matriz[3][3]) {
  bool resultado = true;
  if (limite_caractere(matriz) || doiswins(matriz)) {
    resultado = false;
  }
  return resultado;
}
string proximo_jogador(char mat[3][3]) {
  int acumulador = 0, acumulador2 = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (mat[i][j] == 'X') {
        acumulador++;
      }
      if (mat[i][j] == '0') {
        acumulador2++;
      }
    }
  }
  if (acumulador == acumulador2 || acumulador == 0 && acumulador2 == 0) {
    return "first";
  } else {
    return "second";
  }
}
bool acabou(char matriz[3][3]) {
  int acumulador = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (matriz[i][j] == '.') {
        acumulador++;
      }
    }
  }
  if (acumulador > 0) {
    return false;
  } else {
    return true;
  }
}

int main() {
  char matriz[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matriz[i][j];
    }
  }
  if (!legal(matriz)) {
    cout << "illegal" << endl;
  } else {
    if (win(matriz, 'X')) {
      cout << "the first player won" << endl;
    } else if (win(matriz, '0')) {
      cout << "the second player won" << endl;
    } else if (!acabou(matriz)) {
      string prox = proximo_jogador(matriz);
      cout << prox << endl;
    } else {
      cout << "draw" << endl;
    }
  }
}