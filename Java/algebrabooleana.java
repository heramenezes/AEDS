import java.util.Scanner;

public class algebrabooleana{

	public static String pedacinhoString(String normal, int comeco, int fina ){

		String resultado = new String("");

		for (int i= comeco; i<fina; i++ ){
			resultado = resultado + normal.charAt(i);
		}

		return resultado;
	}

	public static String simplificando(String expressao, boolean[] bools){

		int rem = ((bools.length + 1)*2)-1;

		expressao = pedacinhoString(expressao, rem, expressao.length());

		String resultado = new String(" ");

		for (int i=0; i<expressao.length(); i++){

			char variavel = expressao.charAt(i);

			if (variavel=='A') { resultado += ((bools[0])?1:0); }
			else if(variavel == 'B') { resultado += ((bools[1])?1:0); }
			else if(variavel == 'C') { resultado += ((bools[2])?1:0); }
			else if(variavel == 'a'){
				resultado += 'a';
				i+=2;
			}
			else if(variavel == 'o'){
				resultado += 'o';
				i++;
			}
			else if(variavel == 'n'){
				resultado += '!';
				i+=2;
			}
			else if(variavel != ' ' && variavel != ',') { resultado += variavel; }

		}
		return resultado;
	}

	public static boolean[] getBools(String expressao){
		int numeroBools = (int)expressao.charAt(0)-'0';
		boolean[] bools = new boolean[numeroBools];
		boolean resultado = true;
		int indice = 0;
		for(int i=1; i<expressao.length(); i++){
			if(expressao.charAt(i)=='1'){
				bools[indice] = true;
				indice++;
			}
			else if(expressao.charAt(i)=='0'){
				bools[indice] = false;
				indice++;
			}
		}
		return bools;
	}


	public static char percorrendoString (String compactada){

		Pilha pil = new Pilha();

		for (int i=0; i<compactada.length(); i++){

			char atual = compactada.charAt(i);

			if (atual != ')'){
				pil.adicionando(compactada.charAt(i));
			}

			else {

				String recorte = new String("");

				do{
					recorte += pil.removendo();
				} while(recorte.charAt(recorte.length()-1) != '(');

				char operacao = pil.removendo();

				pil.adicionando(algebrismo(operacao, recorte));

			}
		}

		return pil.topo.data;

	}

	public static char algebrismo(char operacao, String recorte){

		if (operacao == 'a'){
			char resultado = '1';

			for ( int i = 0; i< recorte.length(); i++){
				if (recorte.charAt(i) == '0'){
					i = 100;
					resultado = '0';
				}
			}

			return resultado;

		} else if (operacao == 'o'){

			char resultado = '0';

			for ( int i = 0; i< recorte.length(); i++){
				if (recorte.charAt(i) == '1'){
					i = 100;
					resultado = '1';
				}
			}
			return resultado;
		} else{

			char resultado = '0';

			for ( int i = 0; i< recorte.length(); i++){

				if (recorte.charAt(i) == '1'){
					i = 100;
					resultado = '0';
				}

				else if (recorte.charAt(i) == '0'){
					i = 100;
					resultado = '1';
				}

			}

			return resultado;
		}
	}	

	public static void main (String[] agrs){

		Scanner leitor = new Scanner(System.in); // declarando meu leitor >;)

		String expressao = null; 

		while (true){

			expressao = leitor.nextLine(); // lendo minha expressao 

			if (expressao.equals("0")){ // quebra o meu while
				break;
			} else {

				String compactada = simplificando(expressao, getBools(expressao));

				System.out.println(percorrendoString(compactada));
			}
		}
	}



}

class Cell{

	public Cell apontador;
	public char data;

	Cell(){
		apontador = null;
		data = ' ';
	}	

	Cell(char caractereDaVez){
		apontador = null;
		data = caractereDaVez;
	}	
}

class Pilha{

	public Cell topo;

	Pilha(){
		topo =  null;
	}

	Pilha(char caractereDaVez){
		topo = new Cell(caractereDaVez);
	}

	public void adicionando(char caractereDaVez){
		Cell tmp = new Cell(caractereDaVez);
		tmp.apontador = topo;
		topo = tmp;
	}

	public char removendo(){
		if (topo == null){ return '2'; }

		else {

			char backup = topo.data;
			Cell tmp = topo;
			topo = topo.apontador;
			tmp.apontador = null;
			return backup;
		}
	}
}
