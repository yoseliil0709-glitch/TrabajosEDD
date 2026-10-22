using System;

class Program
{
    static void Main()
    {
        // Implementacion en C# - Recorrido 3D
        int[,,] ThreeDimensionalArray = {
            {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            },
            {
                {10, 11, 12},
                {13, 14, 15},
                {16, 17, 18}
            }
        };

        Console.WriteLine("Los elementos del array son: ");
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    Console.Write(ThreeDimensionalArray[i, j, k] + " ");
                }
                Console.WriteLine(); // Ir a la siguiente linea despues de mostrar una fila
            }
            Console.WriteLine("--- siguiente capa ---");
        }
    }
}
