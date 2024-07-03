
  #include <cmath>
  #include <iostream>
  using namespace std;

  int arvore_de_binarios(int atual, int limite, int contador2){
    if (atual >limite){
      return 0;
    }
    int contador =1;

    contador = contador+ arvore_de_binarios(10*atual, limite, contador2);
    contador = contador+ arvore_de_binarios((10*atual)+1, limite, contador2);
    return contador;
  }

  int main() {
    int numero=0, guardador =0, casas_decimais=1, maior_binario=1, contador=0, potencia=1, contador2=0;
    
    cin>>numero;
    guardador = numero;

    if (guardador<10){
      casas_decimais=1;
    }else{
      for (int i=0; i<guardador; i++){
        guardador = guardador/10;
        casas_decimais++;
        maior_binario = (maior_binario*10)+1;
      }
    }
    if (numero>maior_binario){
      contador = pow(2,casas_decimais)-1;
      cout<<contador<<"\n";
    }else if (numero<=maior_binario){
      potencia = pow(10,(casas_decimais-1));
      contador = pow(2,(casas_decimais-1))-1;
      contador2= arvore_de_binarios((potencia/10), numero, contador);
      contador = (contador + contador2)-2;
      cout<<contador<<"\n";
      cout<<potencia;
    }
  }