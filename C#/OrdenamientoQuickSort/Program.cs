using System;
class Program
{
    static int partition(int[] a, int l, int h)
    {
        int pvt = a[h];
        int j = l - 1;
        for (int k = l; k < h; k++)
        {
            if (a[k] < pvt)
            {
                j += 1;
                swap(a, j, k);
            }
        }
        swap(a, j + 1, h);
        return j + 1;
    }
    static void swap(int[] a, int j, int k)
    {
        int temp = a[j];
        a[j] = a[k];
        a[k] = temp;
    }
    static void qckSort(int[] a, int l, int h)
    {
        if (l < h)
        {
            int pi = partition(a, l, h);
            qckSort(a, l, pi - 1);
            qckSort(a, pi + 1, h);
        }
    }
    static void Main()
    {
        int[] a = { 10, 7, 8, 9, 1, 5 };
        int size = a.Length;
        Console.WriteLine("El arreglo antes de ordenarlo: ");
        foreach (int v in a)
        {
            Console.Write(v + " ");
        }
        Console.WriteLine();
        qckSort(a, 0, size - 1);
        Console.WriteLine("El arreglo despues de ordenarlo: ");
        foreach (int v in a)
        {
            Console.Write(v + " ");
        }
    }
}
