using System;

class Program
{
    static void Main()
    {
        int numero_atual_sequencia = 0;
        int proximo_numero_sequencia = 1;
        int guardador_de_numeros = 0;
        int quantos_numeros_da_sequencia = 0;

        
        quantos_numeros_da_sequencia = int.Parse(Console.ReadLine());

        for (int i = 0; i < quantos_numeros_da_sequencia; i++)
        {
            Console.WriteLine(numero_atual_sequencia);

            guardador_de_numeros = numero_atual_sequencia;
            numero_atual_sequencia = proximo_numero_sequencia;
            proximo_numero_sequencia = guardador_de_numeros + numero_atual_sequencia;
        }
    }
}
