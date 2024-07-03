
  #include <cmath>
  #include <iostream>
  using namespace std;

  int arvore_de_binarios(int atual, int limite){
    if (atual >limite){
      return 0;
    }
    int contador =1;

    contador = contador+ arvore_de_binarios(10*atual, limite);
    contador = contador+ arvore_de_binarios((10*atual)+1, limite);
    return contador;
  }

  int main() {
    int numero=0;

    cin>>numero;

    cout<<arvore_de_binarios(1, numero)<<"\n";
  }