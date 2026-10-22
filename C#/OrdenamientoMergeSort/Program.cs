using System;
class Program
{
    static void merge(int[] a, int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; i++)
        {
            L[i] = a[l + i];
        }

        for (int j = 0; j < n2; j++)
        {
            R[j] = a[m + 1 + j];
        }

        int i1 = 0;
        int j1 = 0;
        int k = l;

        while (i1 < n1 && j1 < n2)
        {
            if (L[i1] <= R[j1])
            {
                a[k] = L[i1];
                i1 += 1;
            }
            else
            {
                a[k] = R[j1];
                j1 += 1;
            }
            k += 1;
        }

        while (i1 < n1)
        {
            a[k] = L[i1];
            i1 += 1;
            k += 1;
        }

        while (j1 < n2)
        {
            a[k] = R[j1];
            j1 += 1;
            k += 1;
        }
    }
    static void mergeSort(int[] a, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m + 1, r);
            merge(a, l, m, r);
        }
    }
    static void Main()
    {
        // Programa principal
        int[] a = { 12, 11, 13, 5, 6, 7 };
        int s = a.Length;

        Console.Write("Antes de ordenar el arreglo: \n");
        for (int j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }

        mergeSort(a, 0, s - 1);

        Console.Write("\nDespues de ordenar el arreglo: \n");
        for (int j = 0; j < s; j++)
        {
            Console.Write(a[j] + " ");
        }
    }
}