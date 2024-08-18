import java.util.Scanner;

public class aquecimento_recursivo {

    public static int contando(int contador, String sentenca, int tamanho, int indice) {
        if (indice == tamanho) { // se minha string acabo, retorna quantas maiusculas
            return contador;
        } else {
            if (sentenca.charAt(indice) >= 'A' && sentenca.charAt(indice) <= 'Z') { // se o caractere for maiúsculo
                return contando(contador + 1, sentenca, tamanho, indice + 1); // chama denovo subindo um no indice e contador
            } else {
                return contando(contador, sentenca, tamanho, indice + 1); // chama denovo so no indice
            }
        }
    }

    public static void main(String[] args) {
        
        Scanner leitor = new Scanner(System.in);
        String sentenca;
        int quantos_char;

        while (true) {
            sentenca = leitor.nextLine(); // le ate o final da linha

            if (sentenca.equals("FIM")) { // compara se a string é igual a FIM
                break;
            }

            quantos_char = sentenca.length(); // conta quantos caracteres tem a string

            System.out.println(contando(0, sentenca, quantos_char, 0)); // printando o resultado 
        }

        leitor.close(); // fecha meu leitor
    }
}
