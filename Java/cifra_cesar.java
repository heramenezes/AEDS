import java.util.Scanner;

public class cifra_cesar {

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in); // criando meu leitor

        String palavra;

        while (true){ // enquanto nao tiver excessao

            palavra = leitor.nextLine(); // lendo minha string

            if (palavra.equals("FIM")){ // quebra o meu while
                break;
            }

            StringBuilder cifra = new StringBuilder(); // criando minha srting resposta

            for (int i=0; i<palavra.length(); i++){ // percorrendo a string
                char guardador = palavra.charAt(i); // atribuindo o caractere pro meu guardador

                guardador = (char) (guardador+3); // deslocando meu caractere e voltando o numero pra char

                cifra.append(guardador); // guardando na string cifra (resposta)

            }

            System.out.println(cifra);

        }
        leitor.close();
    }
}