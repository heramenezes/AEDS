#include <stdio.h>
int main(){
    int numero1=0, numero2=0, opcao=0, novo_numero=0, potencia=1, resto=0;
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    scanf("%d", &opcao);

    switch (opcao){
//
        case 1:
        //REMOCAO DO Y-ESIMO NUMERO DE X
        for (int i=0; i<(numero1*potencia); i++){ // loop que percorre todo o meu primeiro numero (vai acabar quando meu numero chegar a 0, ou seja, sem mais nenhum algarismo pra olhar)
            if (i!=numero2){ // vai acontecer ate que o numero chegar no numero que se quer tirar (numero2)
                resto = numero1%10; // guardando o valor de resto
                novo_numero = novo_numero+ (resto*potencia); // vai guardando a formacao do novo numero
                potencia = potencia*10; // vai fazer a potencia dos lugares (ex: 100 eh 10², 1000 eh 10³, 10 eh 10¹...)
            }
            numero1 = numero1/10; // vai passando a casinha do primeiro numero pra ir pro proximo algarismo
        }
        printf("%d", novo_numero);
        potencia = 1;
        break;
//
        case 2:
        // NUMEROS ALTERNADOS
        for (int i=0; i<(numero1*potencia) || i<(numero2*potencia); i++){ // como a gente quer intercalar, a condicao tem que acontecer ate que ambos numeros chegem em seus ultimos algarismos (quando chega em 0)
            if (numero2>0){ // vai acontecer ate que o numero2 chegue em seu ultimo algarismo
                resto = numero2%10; 
                novo_numero = novo_numero+ (resto*potencia); 
                potencia = potencia*10;
                numero2 = numero2/10; 
            }
            if (numero1>0){ // vai acontecer ate que o numero1 chege em seu ultimo algarimo
                resto = numero1%10; 
                novo_numero = novo_numero+ (resto*potencia); 
                potencia = potencia*10;
                numero1 = numero1/10;
            }
        }
        printf("%d", novo_numero);
        potencia =1;
        break;
//
        case 3:
        // NUMERO EM ORDEM, PRIMEIRO X DEPOIS Y
        for (int i=0; i<(numero2*potencia); i++){ // um loop que vai montar e desmontar o numero2. Ele eh primeiro pq ele eh o das unidades
            if (numero2>0){ // vai acontecer ate que o numero chege em seu ultimo algarimo
                resto = numero2%10; 
                novo_numero = novo_numero+ (resto*potencia); 
                potencia = potencia*10;
                numero2 = numero2/10;
            }
        }
        for (int i=0; i<(numero1*potencia); i++){ // mesma coisa do outro so que com o numero1. Ele eh depois pq ele aparece depois do 2
            if (numero1>0){ 
                resto = numero1%10; 
                novo_numero = novo_numero+ (resto*potencia); 
                potencia = potencia*10;
                numero1 = numero1/10;
            }
        }
        // se eu quisesse tbm era so fazer um printf conjuntado tipo: printf("%d%d", numero1,numero2);, mas como eu nao entendi seu enunciado fiquei com medo de ser alem disso ai, dai fiz esse trambolho
        printf("%d", novo_numero);
        potencia =1;
        break;
    }
    return 0;
}
