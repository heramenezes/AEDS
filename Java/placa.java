import java.util.Scanner;

public class placa {
    public static void main(String[] args){

        Scanner leitor = new Scanner(System.in);

        String placa;

        placa = leitor.nextLine();
        int contador_certas = 0;

        if (placa.length() == 8){ // se o tamanho da placa for do tamanho antigo
            for (int i=0; i<3; i++){ // loop de verificacao de caracteres
                if (placa.charAt(i) >='A' && placa.charAt(i) <= 'Z'){
                    contador_certas++;
                } 
            }
            if(placa.charAt(3) == '-') contador_certas++; // verficando hifen >:0

            for (int i=4; i<8; i++){ // loop de verificacao de digitos
                if (placa.charAt(i) >= '0' && placa.charAt(i) <= '9'){
                    contador_certas++;
                }
            }

            if (contador_certas == 8){ // o contador de certas tem que ser igual ao tamanho da placa
                System.out.println("1");
            } else {
                System.out.println("0");
            }

        } else if (placa.length() == 7){ // se o tamanho da placa for do tamanho mercosul
            
            for (int i=0; i<3; i++){ // loop de verificacao dos caracteres
                if (placa.charAt(i) >='A' && placa.charAt(i) <= 'Z'){
                    contador_certas++;
                } 
            }

            if(placa.charAt(3) >= '0' && placa.charAt(3) <= '9') contador_certas++; // verificando digito

            if(placa.charAt(4) >= 'A' && placa.charAt(4) <= 'Z') contador_certas++; // verificando letra

            for (int i=5; i<7; i++){ // verificando digitos finais
                if (placa.charAt(i) >= '0' && placa.charAt(i) <= '9'){
                    contador_certas++;
                }
            }

            if (contador_certas == 7){ // o contador de certas tem que ser igual ao tamanho da placa
                System.out.println("2");
            } else {
                System.out.println("0");
            }

        } else { // se nao entrou nos dois, essa placa ta errada

            System.out.println("0");
        }

        leitor.close();
    }
}