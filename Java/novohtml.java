import java.util.Scanner;
import java.io.*;
import java.net.*;

public class novohtml {

    public static String stringfy_conteudo(String endereco) {
        URL url;
        InputStream is = null;
        BufferedReader br;
        StringBuilder resp = new StringBuilder();
        String line;

        try {
            url = new URL(endereco);
            is = url.openStream();  // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            while ((line = br.readLine()) != null) {
                resp.append(line).append("\n");
            }
        } catch (MalformedURLException mue) {
            mue.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        } finally {
            try {
                if (is != null) {
                    is.close();
                }
            } catch (IOException ioe) {
                // nada
            }
        }

        return resp.toString();
    }

    public static int[] contando(String conteudo) {
        int[] contagens = new int[25];
        int tamanho = conteudo.length();
        int indice = 0;

        while (indice < tamanho) {
            char ch = conteudo.charAt(indice);

            switch (ch) {
                case ' ':
                case '\n':
                    // Ignore spaces and newlines
                    break;
                case 'a':
                    contagens[0]++;
                    break;
                case 'e':
                    contagens[1]++;
                    break;
                case 'i':
                    contagens[2]++;
                    break;
                case 'o':
                    contagens[3]++;
                    break;
                case 'u':
                    contagens[4]++;
                    break;
                case '\u00E1': // á
                    contagens[5]++;
                    break;
                case '\u00E9': // é
                    contagens[6]++;
                    break;
                case '\u00ED': // í
                    contagens[7]++;
                    break;
                case '\u00F3': // ó
                    contagens[8]++;
                    break;
                case '\u00FA': // ú
                    contagens[9]++;
                    break;
                case '\u00E0': // à
                    contagens[10]++;
                    break;
                case '\u00E8': // è
                    contagens[11]++;
                    break;
                case '\u00EC': // ì
                    contagens[12]++;
                    break;
                case '\u00F2': // ò
                    contagens[13]++;
                    break;
                case '\u00F9': // ù
                    contagens[14]++;
                    break;
                case '\u00E3': // ã
                    contagens[15]++;
                    break;
                case '\u00F5': // õ
                    contagens[16]++;
                    break;
                case '\u00E2': // â
                    contagens[17]++;
                    break;
                case '\u00EA': // ê
                    contagens[18]++;
                    break;
                case '\u00EE': // î
                    contagens[19]++;
                    break;
                case '\u00F4': // ô
                    contagens[20]++;
                    break;
                case '\u00FB': // û
                    contagens[21]++;
                    break;
                default:
                    if (indice + 4 < tamanho && conteudo.startsWith("<br/>", indice)) {
                        contagens[22]++;
                        indice += 4;
                    } else if (indice + 6 < tamanho && conteudo.startsWith("<table>", indice)) {
                        contagens[23]++;
                        indice += 6;
                    } else {
                        contagens[24]++;
                    }
                    break;
            }

            indice++;
        }
        return contagens;
    }

    public static void main(String[] args) {
        MyIO.setCharset("ISO-8859-1"); // setando o charset

	
        while (true) {
            String nome_pagina = MyIO.readLine();

            if (nome_pagina.equals("FIM")) {
                break;
            }

            String url = MyIO.readLine();

            String conteudo_site = stringfy_conteudo(url); // Pega todo o conteúdo do site

            int[] contagens = contando(conteudo_site); // Conta os caracteres e tags

            System.out.print("a(" + contagens[0] + ") ");
            System.out.print("e(" + contagens[1] + ") ");
            System.out.print("i(" + contagens[2] + ") ");
            System.out.print("o(" + contagens[3] + ") ");
            System.out.print("u(" + contagens[4] + ") ");
            MyIO.print("á(" + contagens[5] + ") ");
            MyIO.print("é(" + contagens[6] + ") ");
            MyIO.print("í(" + contagens[7] + ") ");
            MyIO.print("ó(" + contagens[8] + ") ");
            MyIO.print("ú(" + contagens[9] + ") ");
            MyIO.print("à(" + contagens[10] + ") ");
            MyIO.print("è(" + contagens[11] + ") ");
            MyIO.print("ì(" + contagens[12] + ") ");
            MyIO.print("ò(" + contagens[13] + ") ");
            MyIO.print("ù(" + contagens[14] + ") ");
            MyIO.print("ã(" + contagens[15] + ") ");
            MyIO.print("õ(" + contagens[16] + ") ");
            MyIO.print("â(" + contagens[17] + ") ");
            MyIO.print("ê(" + contagens[18] + ") ");
            MyIO.print("î(" + contagens[19] + ") ");
            MyIO.print("ô(" + contagens[20] + ") ");
            MyIO.print("û(" + contagens[21] + ") ");
	    MyIO.print("consoantes(" + contagens[24] + ") ");
            MyIO.print("<br>(" + contagens[22] + ") ");
            MyIO.print("<table>(" + contagens[23] + ") ");
            System.out.println(nome_pagina);
        }
    }
}

