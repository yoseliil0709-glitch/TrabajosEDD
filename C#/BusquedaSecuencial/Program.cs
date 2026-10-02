using System;

class Program
{
    static int findEle(int[] inpuptArr, int s, int targetEle)
    {
        for (int j = 0; j < s; j++)
        {
            if (inpuptArr[j] == targetEle) // aplicando búsqueda lineal
            {
                return j; // elemento encontrado en el índice j
            }
        }
        // no se encuentra el elemento objetivo
        return -1;
    }

    static void Main()
    {
        int[] inputArr = { 12, 34, 10, 6, 40, 89, 98, 57, 19, 69 };
        int targetElement = 40;
        int s = inputArr.Length;
        // operación de búsqueda
        int idx = findEle(inputArr, s, targetElement);
        if (idx!= -1)
        {
            Console.WriteLine("El elemento se encuentra en la posición: " + (idx + 1));
        }
        else
        {
            Console.WriteLine("No se encuentra el elemento.");
        }
    }
}