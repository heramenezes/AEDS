import java.util.Scanner;

public class palindromo {

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in); // criando meu leitor

        String sequencia;

        while (true) { // enquanto nao acontecer a excessao

            sequencia = leitor.nextLine(); // lendo sequencia >:)

            if (sequencia.equals("FIM")) { // se a sequencia for FIM, o programa para
                break;
            }

            StringBuilder normal = new StringBuilder(); // dando tipo um malloc pra o que vai ser minha string sem espacos

            int tamanho = sequencia.length(); // Corrigido: length() ao invés de lenght()

            for (int i = 0; i < tamanho; i++) { // loop que vai desconsiderar os espaços da minha string 
                if (sequencia.charAt(i) != ' ') { 
                    normal.append(sequencia.charAt(i)); // se nao tiver string, coloca o caractere na minha string normal
                }
            }

            StringBuilder invertida = new StringBuilder(normal).reverse(); // dando tipo um malloc pra minha string invertida

            if (normal.toString().equals(invertida.toString())) { // comparando minhas duas strings
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }

        leitor.close(); // fechei o meu leitor
    }
}
