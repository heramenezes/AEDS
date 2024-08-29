import java.util.Scanner;

public class is_recursivo {

    // verifica recursivamente se a string é composta somente por vogais
    public static boolean ehVogal(String frase, int indice) {
        if (indice == frase.length()) {
            return true;
        }

        char caractere = frase.charAt(indice);
        if (caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U' ||
            caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
            return ehVogal(frase, indice + 1);
        } else {
            return false;
        }
    }

    // verifica recursivamente se a string é composta somente por consoantes
    public static boolean ehConsoante(String frase, int indice) {
        if (indice == frase.length()) {
            return true;
        }

        char caractere = frase.charAt(indice);
        if (Character.isLetter(caractere) && !(caractere == 'A' || caractere == 'E' || caractere == 'I' ||
            caractere == 'O' || caractere == 'U' || caractere == 'a' || caractere == 'e' ||
            caractere == 'i' || caractere == 'o' || caractere == 'u')) {
            return ehConsoante(frase, indice + 1);
        } else {
            return false;
        }
    }

    // verifica recursivamente se a string corresponde a um número inteiro
    public static boolean ehInteiro(String frase, int indice) {
        if (indice == frase.length()) {
            return true;
        }

        char caractere = frase.charAt(indice);
        if (Character.isDigit(caractere)) {
            return ehInteiro(frase, indice + 1);
        } else {
            return false;
        }
    }

    // verifica recursivamente se a string corresponde a um número real
    public static boolean ehReal(String frase, int indice, int pontos) {
        if (indice == frase.length()) {
            return pontos == 1;
        }

        char caractere = frase.charAt(indice);
        if (Character.isDigit(caractere)) {
            return ehReal(frase, indice + 1, pontos);
        } else if ((caractere == '.' || caractere == ',') && pontos < 1) {
            return ehReal(frase, indice + 1, pontos + 1);
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        MyIO.setCharset("ISO-8859-1"); // setando o charset
        String frase;

        while (true) { // enquanto não chegar no fim
            frase = MyIO.readLine(); // lendo...

            if (frase.equals("FIM")) { // quebra o while
                break;
            }

            boolean somenteVogais = ehVogal(frase, 0);
            boolean somenteConsoantes = ehConsoante(frase, 0);
            boolean numeroInteiro = ehInteiro(frase, 0);
            boolean numeroReal = ehReal(frase, 0, 0);

            String resposta = (somenteVogais ? "SIM" : "NAO") + " " +
                              (somenteConsoantes ? "SIM" : "NAO") + " " +
                              (numeroInteiro ? "SIM" : "NAO") + " " +
                              (numeroReal ? "SIM" : "NAO");

            MyIO.println(resposta); // imprime a resposta na forma "X1 X2 X3 X4"
        }
    }
}

