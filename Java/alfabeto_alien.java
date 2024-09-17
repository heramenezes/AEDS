import java.util.Scanner;

public class alfabeto_alien {
  public static void main(String[] args) {
    Scanner leitor = new Scanner(System.in);

    int qtd_alien = 0, qtd_normal = 0;
    String alien, normal;
    boolean no_alfabeto = false;

    qtd_alien = leitor.nextInt();
    qtd_normal = leitor.nextInt();
    leitor.nextLine();

    alien = leitor.nextLine();
    normal = leitor.nextLine();

    for (int i = 0; i < qtd_normal; i++) {
      no_alfabeto = false;

      for (int k = 0; k < qtd_alien; k++) {
        if (normal.charAt(i) == alien.charAt(k)) {
          no_alfabeto = true;
        }
      }
      if (no_alfabeto == false)
        i = qtd_normal;
    }

    if (no_alfabeto == true)
      System.out.println("S");
    else
      System.out.println("N");

    leitor.close();
  }

}