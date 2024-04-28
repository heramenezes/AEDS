#include <stdio.h>
#include <stdlib.h>

//int main(void){
   // int nota,res;
    //scanf("%d",&nota);
    //res ='N'+5*(1-(nota%2));
    //printf("%c\n",res);
    //return 0;
//}
int main(void){
    int nota,res;
    scanf("%d",&nota);
    res ='N'+5*(nota/60); //isso aqui divide a nota por 60 pra saber se a pessoa pelo menos pegou a media. Caso positivo, a divisao pode dar um e quase dois, mas nunca dois. Como a variavel nota eh definida como inteiro, tudo com os quebradinhos arredonda pra baixo pro primeiro numero inteiro mais proximo do valor da divisao. A mesma coisa acontece quando eh com valores menores que 60, so que com 0. Dai, vai multiplicar esse valor por 5, e isso vai fazer (ou nao) o N passar 5 casinhas pra frente
    printf("%c\n",res);

    res ='N'+5*((nota/45)*(1-(nota/60)));//isso aqui divide a nota por 45 pra saber se a pessoa pelo menos pegou a recuperacao. Caso positivo, a divisao pode dar um e quase dois, mas nunca dois. Como a variavel nota eh definida como inteiro, tudo com os quebradinhos arredonda pra baixo pro primeiro numero inteiro mais proximo do valor da divisao. A mesma coisa acontece quando eh com valores menores que 45, so que com 0. Aquela parte do 1- ali vai fazer a condicao nunca passar de 60, porque nem todo mundo que ficou com mais de 45 precisa de recuperacao. Dai, vai multiplicar o resultado disso tudo por 5, e isso vai fazer (ou nao) o N passar 5 casinhas pra frente
    printf("%c\n",res);

    res ='N'+5*(1-(nota/60));// isso aqui faz o contrario da primeira, porque se tiver passado (60+) vai dai 1 e bolinha e vai anular com aquele 1- ali. Se nao tiver passado, o resultado disso ai da 0, e 1-0 eh 1, fazendo N passar 5 casinhas
    printf("%c\n",res);

    return 0;
}
