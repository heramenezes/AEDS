import java.util.Scanner;

public class is {

    // verifica iterativamente se a string é composta somente por vogais
    public static boolean ehVogal(String frase) {
        for (int i = 0; i < frase.length(); i++) {
            char caractere = frase.charAt(i);
            if (!(caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U' ||
                  caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u')) {
                return false;
            }
        }
        return true;
    }

    // verifica iterativamente se a string é composta somente por consoantes
    public static boolean ehConsoante(String frase) {
        for (int i = 0; i < frase.length(); i++) {
            char caractere = frase.charAt(i);
            if (Character.isLetter(caractere) && (caractere == 'A' || caractere == 'E' || caractere == 'I' ||
                                                  caractere == 'O' || caractere == 'U' || caractere == 'a' ||
                                                  caractere == 'e' || caractere == 'i' || caractere == 'o' ||
                                                  caractere == 'u')) {
                return false;
            }
        }
        return true;
    }

    // verifica iterativamente se a string corresponde a um número inteiro
    public static boolean ehInteiro(String frase) {
        for (int i = 0; i < frase.length(); i++) {
            char caractere = frase.charAt(i);
            if (!Character.isDigit(caractere)) {
                return false;
            }
        }
        return true;
    }

    // verifica iterativamente se a string corresponde a um número real
    public static boolean ehReal(String frase) {
        int pontos = 0;
        for (int i = 0; i < frase.length(); i++) {
            char caractere = frase.charAt(i);
            if (Character.isDigit(caractere)) {
                continue;
            } else if ((caractere == '.' || caractere == ',') && pontos < 1) {
                pontos++;
            } else {
                return false;
            }
        }
        return pontos == 1;
    }

    public static void main(String[] args) {
        MyIO.setCharset("ISO-8859-1"); // setando o charset
        String frase;

        while (true) { // enquanto não chegar no fim
            frase = MyIO.readLine(); // lendo...

            if (frase.equals("FIM")) { // quebra o while
                break;
            }

            boolean somenteVogais = ehVogal(frase);
            boolean somenteConsoantes = ehConsoante(frase);
            boolean numeroInteiro = ehInteiro(frase);
            boolean numeroReal = ehReal(frase);

            String resposta = (somenteVogais ? "SIM" : "NAO") + " " +
                              (somenteConsoantes ? "SIM" : "NAO") + " " +
                              (numeroInteiro ? "SIM" : "NAO") + " " +
                              (numeroReal ? "SIM" : "NAO");

            MyIO.println(resposta); // imprime a resposta na forma "X1 X2 X3 X4"
        }
    }
}

