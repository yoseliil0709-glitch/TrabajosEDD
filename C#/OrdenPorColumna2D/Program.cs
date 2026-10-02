using System;
class Program
{
    static void Main()
    {
        int r = 3;
        int c = 3;
        int[] arr = new int[r * c];

        int[,] TwoDArr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        int k = 0;
        for (int y = 0; y < c; y++) // primero columnas
        {
            for (int x = 0; x < r; x++) // luego filas
            {
                arr[k] = TwoDArr[x, y];
                k = k + 1;
            }
        }
        Console.WriteLine("Los elementos del array bidimensional son: ");
        for (int x = 0; x < r; x++)
        {
            for (int y = 0; y < c; y++)
            {
                Console.Write(TwoDArr[x, y] + " ");
            }
            Console.WriteLine();
        }
        Console.WriteLine("\nLos elementos del array unidimensional por columnas son: ");
        for (int i = 0; i < r * c; i++)
        {
            Console.Write(arr[i] + " ");
        }
    }
}
