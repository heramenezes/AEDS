#include <stdio.h>
int main(){
    int numeros[10], opcao, soma=0, numero_repete=0, frequencia=0, guardador_maior = 0, guardador_menor=0, media, indice_posicao=0, qual_numero_mudar=0, ordem=0, acumulador=0, rotacoes=0, original[10], contabilizador_numeros_aparecem[101];
    for(int i=0; i<10; i++){ // loop que le todos os numeros do vetor numeros
        scanf("%d%*c", &numeros[i]);
    }

    guardador_maior = numeros[0]; // guardando o primeiro indice
    guardador_menor = numeros[9]; // guardando o ultimo indice

    scanf("%d", &opcao);

    while (opcao!=0){
        switch (opcao){
            case 1:
            //MUDAR O NUMERO
            scanf("%d%*c ", &indice_posicao); //le a posicao do numero que o usuario quer mudar
            scanf("%d%*c ", &qual_numero_mudar); //le o novo valor de numero do usuario
            numeros[indice_posicao] = qual_numero_mudar; // muda o valor que o usuario quer de acordo com o indice da posicao que ele quer mudar
            for (int i=0; i<10; i++){
                original[i]=numeros[i];
            }
            break;
//
            case 2 :
            //EXIBIR SEQUENCIA
            for(int i=0; i<10; i++){ // loop que imprime todos os numeros do vetor numeros
                printf("%d ", numeros[i]);
            }
            printf("\n");
            break;
//           
            case 3 :
            //EXIBIR SEQUENCIA NA ORDEM INVERSA
            for(int j=9; 0<=j; j--){ // loop que imprime todos os numeros do vetor numeros na ordem inversa
                printf("%d ", numeros[j]);
            }
            printf("\n");
            break;
//
            case 4:
            //SOMAR OS NUMEROS DA SEQUENCIA
            for (int p=0; p<10; p++){ // loop que vai pegando todos os numeros do vetor numeros e vai acrescentando no acumulador soma
                soma = soma+ numeros[p];
            }
            printf("%d", soma);
            printf("\n");
            break;
//
            case 5:
            //CONTAR QUANTOS NUMEROS REPETIDOS TEM NA SEQUENCIA
            numero_repete=0;
            for ( int a=0; a<10; a++){ // loop do primeiro numero
                if ( numeros[a]!=22222){ //se esse numero aparecer, a acao nao acontece (comparacao) porque o numero ta repetindo
                    for ( int s=a+1; s<11; s++){ // loop dos proximos numeros depois de a (antecessor)
                        if (numeros[a] == numeros[s]){ // se o antecessor for igual ao sucessor vai ter uma repeticao (acumulador)
                            numero_repete++;
                            numeros[s] = 22222; // define o numero como valor diferente
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                numeros[i] = original[i];
            }
            printf("%d", numero_repete);
            printf("\n");
            break;
//
            case 6:
            //MOSTRAR QUAIS NUMEROS NAO TAO REPETINDO (SE TIVER, VAI "ELIMINAR" TODOS OS QUE REPETEM)
            for  (int i=0; i <10; i++){ // deixa tudo em ordem crescente, verificando quem eh maior e, consequentemente, o menor
                for (int j=i+1; j<10;j++){
                    if (numeros[i]>numeros[j]){
                        ordem = numeros[i];
                        numeros[i] = numeros[j];
                        numeros[j] = ordem;
                    }
                }
            }
            for ( int a=0; a<10; a++){ // loop do primeiro numero
                for ( int s=a+1; s<11; s++){ // loop dos proximos numeros depois de a (antecessor)
                    if (numeros[a] != numeros[s]){ // se o antecessor for diferente do sucessor
                        if (s == 10){ // se chegou no final da sequencia e numero ainda for diferente, pode printar o numero
                            printf("%d ", numeros[a]);
                        }
                    }else{ // caso contrario acaba 
                        break;
                    }
                }
            }
            printf("\n");
            for (int i = 0; i < 10; i++) {
                numeros[i] = original[i];
            }
            break;
//
            case 7:
            //FREQUENCIA DOS NUMEROS
            for  (int i=0; i <10; i++){ // esse loop vai deixar a ordem do que vai ser analizado em crescente
                for (int j=i+1; j<10;j++){
                    if (numeros[i]>numeros[j]){ // aqui vai vendo se o antecessor é maior que o sucessor. Se for, vai trocar a ordem dos dois e assim por diante
                        ordem = numeros[i];
                        numeros[i] = numeros[j];
                        numeros[j] = ordem;
                    }
                }
            }
           for (int j = 0; j <= 100; j++) { // zera tudo que ja pode ter sido contabilizado pelo contabilizador de numeros que aparecem
                contabilizador_numeros_aparecem[j] = 0;
            }
            for (int a = 0; a < 10; a++) { // vai vendo quais os valores que tao no vetor numero e vai adicionando 1 no indice do contabilizador (ex: numero - 1 1 2 2 3, contabilizador - 0 2 2 1)
                contabilizador_numeros_aparecem[numeros[a]]++;
            }
            for (int i = 0; i <= 100; i++) { // vai printar os numeros que apareceram e quantas vezes eles apareceram. O i tem que ser maior que 0 porque eh justamente o que conta as aparicoes (se for 0, o numero nao apareceu)
                if (contabilizador_numeros_aparecem[i] != 0) {
                    printf("%d:%d ", i, contabilizador_numeros_aparecem[i]);
                }
            }
            for (int i = 0; i < 10; i++) {
                numeros[i] = original[i];
            }
            printf("\n");
            break;
//
            case 8:
            //MEDIA E MAIOR E MENOR VALOR DA SEQUENCIA
            soma= 0;
            for ( int i=0; i<10; i++){ // loop pra somar todo mundo (denovo)
                soma= soma+ numeros[i];
            }
            for ( int m=1; m<10; m++){ //loop pra achar o maior
                if (numeros[m]> guardador_maior){ // se o guardador for menor ao numero do indice do loop atual, guardador assume novo valor
                    guardador_maior = numeros[m];
                }
            }
            for ( int n=8; n>=0; n--){ //loop pra achar o menor
                if (numeros[n]< guardador_menor){ // se o guardador for maior ao numero do indice do loop atual, guardador assume novo valor
                    guardador_menor = numeros[n];
                }
            }
            printf("%d %d %.2f", guardador_menor, guardador_maior, (soma/10.0)); // immprime tudo bonitinho e divide a soma por 10 pra achar a media
            printf("\n");
            break;
//
            case 9:
            //IMPRIMIR OS PARES E IMPARES
            for  (int i=0; i <10; i++){ // esse loop deixa os numeros em ordem (denovo)
                for (int j=i+1; j<10;j++){
                    if (numeros[i]>numeros[j]){
                        ordem = numeros[i];
                        numeros[i] = numeros[j];
                        numeros[j] = ordem;
                    }
                }
            }
            printf("P: "); // para os pares
            for (int i=0; i<10; i++){
                acumulador=0; //redefine os dois acumuladores como 0
                int acumulador2 = 0;
                for (int j=10; j>i; j--){ // pros sucessores do numero
                    if (numeros[i] == numeros[j]){ // se o numero for igual ao sucessor adiciona 1 no acumulador? (era pra ser contador) de pares
                        acumulador++;
                    }
                }
                if (acumulador == 0 && numeros[i]%2==0){ // se nao tiver repeticao e o numero for par, imprime ele
                    printf("%d ", numeros[i]);
                }
            }
            printf("I: "); // para os impares
            for (int i=0; i<10; i++){
                acumulador=0; // redefine os dois acumuladores como 0
                for (int j=10; j>i; j--){ // pros sucessores do numero
                    if (numeros[i]==numeros[j]){ // se o numero for igual ao sucessor  adiciona 1 no acumulador? (era pra ser contador) de immpares
                        acumulador++;
                    }
                }
                if (acumulador==0 && numeros[i]%2==1){ // se o nao tiver repeticao e o numero for impar imprime ele
                    printf("%d ", numeros[i]);
                }
            }
            for (int i = 0; i < 10; i++) {
                numeros[i] = original[i];
            }
            printf("\n");
            break;
//
        case 10:
        //ROTACIONAR O NUMERO Y VEZES PRA ESQUERDA
        scanf("%d%*c", &rotacoes);
        rotacoes= rotacoes%10; // to cortando o valor das rotacoes (corrige meu fator)
        for (int i=rotacoes; i<10; i++){ // vai printar a sequencia que vai na frente do primeiro numero que quero mudar de posicao (os que vao pra tras da sequencia depois)
            printf("%d ", numeros[i]);
        }
        for (int a=0; a<rotacoes; a++){ // vai printar a sequencia anterior ao meu numero que quero mudar de posicao (os que vao pular as casinhas)
            printf("%d ", numeros[a]);
        }
        printf("\n");
        for (int i = 0; i < 10; i++) {
            numeros[i] = original[i];
        }
        break;
//
        case 11:
        //ROTACIONAR O NUMERO Y VEZES PRA DIREITA
        scanf("%d%*c", &rotacoes);
        rotacoes= rotacoes%10; // to cortando o valor das rotacoes (corrige o meu fator)
        for (int i= 10-rotacoes; i<10; i++){ // vai imprimir tudo que vem depois do meu fator (que vai pular pra tras) so que ao inverso, porque eh pra direita que eu to movimentando
            printf("%d ", numeros[i]);
        }
        for (int a=0; a< (10-rotacoes); a++){ // vai printar a sequencia anterior ao meu numero que quero mudar de posicao (os que vao pular as casinhas) sp que ao inverso, porque eh pra direita que eu to movimentando
            printf("%d ", numeros[a]);
        }
        printf("\n");
        rotacoes=0;
        for (int i = 0; i < 10; i++) {
            numeros[i] = original[i];
        }
        break;
//
        }
        scanf("%d", &opcao);
    }
    return 0;
}