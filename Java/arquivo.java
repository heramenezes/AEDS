import java.io.*;
import java.util.Scanner;

public class arquivo {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // ler o número de elementos double a serem lidos
        int quantidadeElementos = scanner.nextInt();

        try {
            // abrir o arquivo
            RandomAccessFile arquivo = new RandomAccessFile("arquivoNumeros.txt", "rw");

            // escrever os valores no arquivo
            for (int i = 0; i < quantidadeElementos; i++) {
                double valorAtual = scanner.nextDouble();
                arquivo.writeDouble(valorAtual);
            }

            // ler o arquivo de trás para frente
            for (int i = quantidadeElementos - 1; i >= 0; i--) {
                arquivo.seek(i * 8); // cada double ocupa 8 bytes
                double valorLido = arquivo.readDouble();

                // exibir os valores lidos
                if (valorLido == (int) valorLido) {
                    System.out.println((int) valorLido);
                } else {
                    System.out.println(valorLido);
                }
            }

            arquivo.close(); // fechar o arquivo
        } catch (IOException excecao) {
            System.err.println("Erro ao manipular o arquivo");
            excecao.printStackTrace();
        }

        scanner.close();
    }
}

