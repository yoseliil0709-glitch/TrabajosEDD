using System;
class Program
{
    static void Main()
    {
        int[] arr = { 40, 50, 60, 70, 80, 90 };
        Console.Write("Recorrido inverso: ");
        for (int i = arr.Length - 1; i >= 0; i--)
        {
            Console.Write(arr[i] + " ");
        }
    }
}
