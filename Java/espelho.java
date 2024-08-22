import java.util.Scanner;

public class espelho {

	public static void main(String[] args){
		Scanner leitor = new Scanner(System.in);

		int primeiro_numero = 0;
		int segundo_numero = 0;

		while (leitor.hasNext()){ // enquanto tiver coisa pra ler

			StringBuilder resposta_normal = new StringBuilder(); // criando um "malloc" so que com essa funcao que nao precisa de declarar o tamanho da string

			primeiro_numero = leitor.nextInt(); // lendo entrada 1
			segundo_numero = leitor.nextInt(); // lendo entrada 2

			
			for (int num1 = primeiro_numero; num1 <= segundo_numero; num1++){ // preenchendo com a sequencia normal
                resposta_normal.append(num1);
            }

			StringBuilder resposta_invertida = new StringBuilder(resposta_normal).reverse(); // invertendo a sequencia

			System.out.print(resposta_normal); // dando print na primeira sequencia 
            System.out.print(resposta_invertida); // dando print na segunda sequencia

            // adiciona uma quebra de linha para separar as saídas
            System.out.println("");
		}
		leitor.close();
	}
}
