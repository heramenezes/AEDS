import java.util.Scanner;

public class cifra_cesar_recursivo {

    public static void deslocando (int indice, int tamanho, String normal, StringBuilder cifra){
        if (indice == tamanho){ // se tiver chegado no tamanho da string, encerra
            return;
        } else { // faz o deslocamento 
            char guardador = normal.charAt(indice);
            guardador = (char) (guardador+3);

            cifra.append(guardador);

            deslocando(indice + 1, tamanho, normal, cifra); // chamando minha funcao com mais um indice
        }
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in); // criando meu leitor

        String palavra;

        int tamanho = 0;

        while (true){ // enquanto nao tiver excessao

            palavra = leitor.nextLine(); // lendo minha string

            if (palavra.equals("FIM")){ // quebra o meu while
                break;
            }

            StringBuilder cifra = new StringBuilder(); // criando minha srting resposta

            tamanho = palavra.length(); // contando tamanho da string

            deslocando(0, tamanho, palavra, cifra);

            System.out.println(cifra);

        }
        leitor.close();
    }
}