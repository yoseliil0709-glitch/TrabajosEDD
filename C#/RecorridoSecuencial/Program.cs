using System;
class Program
{
    static string RecorridoSe(int[] lista, int obje)
    {
        for (int i = 0; i < lista.Length; i++)
        {
            Console.WriteLine($"Revisa posicion {i}: {lista[i]}");
            if (lista[i] == obje) return $"Se encontro el {obje} en la posicion {i}";
        }
        return $"No se encontro el {obje}";
    }
    static void Main()
    {
        int[] MiLista = { 10, 23, 5, 89, 3, 42, 15 };
        Console.Write("Que numero quieres buscar? ");
        int buscar = int.Parse(Console.ReadLine());
        Console.WriteLine(RecorridoSe(MiLista, buscar));
    }
}
