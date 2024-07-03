#include <stdio.h>
int main(void){
int lado, linha, coluna;
char comando;

scanf("%d%*c",&lado);

scanf("%c%*c",&comando);



switch(comando){
    case 'b': // SÓ O QUADRADO COM AS BORDAS
    for (linha=0; linha<lado; linha++){
        for (coluna=0; coluna<lado; coluna++){
            if (linha==0 || linha==lado-1 || coluna==0 || coluna==lado-1){
                printf("*");
            }
            else{
              printf(" ");
            }
        }
    printf("\n");
    }
    break;
//
    case 'c': //QUADRADO PREENCHIDO
    for (linha=0; linha<lado; linha++){
        for (coluna=0; coluna<lado; coluna++){
            printf("*");
        }
    printf("\n");
    }
    break;
//
    case 'p': // QUADRADO COM DIAGONAL NORMAL
      for (linha=0; linha<lado; linha++){
        for (coluna=0; coluna<lado; coluna++){
            if (linha==0 || linha==lado-1 || linha==coluna || coluna==0 || coluna==lado-1){
                printf("*");
            }
            else{
              printf(" ");
            }
        }
      printf("\n");
      }
    break;
//
    case 's': // QUADRADO COM DIAGONAL CONTRÁRIA
      for (linha=0; linha<lado; linha++){
        for (coluna=0; coluna<lado; coluna++){
            if (linha==0 || linha==lado-1 || coluna==lado-linha-1 || coluna==0 || coluna==lado-1){
                printf("*");
            }
            else{
              printf(" ");
            }
        }
      printf("\n");
      }
    break;
//
    case 'h': // QUADRADO COM LINHA HORIZONTAL
      for (linha=0; linha<lado; linha++){
        for (coluna=0; coluna<lado; coluna++){
            if (linha==0 || linha==lado-1 || linha==lado/2 || coluna==0 || coluna==lado-1){
                printf("*");
            }
            else{
              printf(" ");
            }
        }
      printf("\n");
      }
    break;
//
    case 'v': // QUADRADO COM LINHA VERTICAL
      for (linha=0; linha<lado; linha++){
        for (coluna=0; coluna<lado; coluna++){
            if (linha==0 || linha==lado-1 || coluna==0 || coluna==lado-1 || coluna==lado/2){
                printf("*");
            }
            else{
              printf(" ");
            }
        }
      printf("\n");
      }
    break;
  //
    default:
    printf("\n\n");
}

  return 0;
}  

