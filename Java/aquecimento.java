import java.util.Scanner;

public class aquecimento {

    public static void main(String[] args) {
        
        Scanner leitor = new Scanner(System.in);
        
        String sentenca;
        int quantos_char = 0;
        int quantas_maiusculas = 0;

        while (true) { 
            sentenca = leitor.nextLine(); // lendo ate o \n

            if (sentenca.equals("FIM")) {
                break; // encerra o loop se a string for a mesma que FIM
            }

            quantos_char = sentenca.length(); // achando o tamanho da string

            quantas_maiusculas = 0; // reinicia a contagem de maiúsculas
            for (int i = 0; i < quantos_char; i++) { // loop de verificação de caracteres da string
                if (sentenca.charAt(i) >= 'A' && sentenca.charAt(i) <= 'Z') { // se o caractere for maiúsculo adiciona no contador
                    quantas_maiusculas++;
                }
            }

            System.out.println(quantas_maiusculas);
        }

        leitor.close(); // acabano com a acao do meu leitor (scanner)
    }
}
