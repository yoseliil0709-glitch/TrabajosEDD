using System;

class ShellShort
{
    public static void displayArr(int[] imputArr)
    {
        foreach (int k in imputArr)
        {
            Console.Write(k + " ");
        }
        Console.WriteLine();
    }

    public int sort(int[] imputArr)
    {
        int size = imputArr.Length;
        int gapSize = size / 2;

        while (gapSize > 0)
        {
            for (int j = gapSize; j < size; j++)
            {
                int val = imputArr[j];
                int k = j;

                while (k >= gapSize && imputArr[k - gapSize] > val)
                {
                    imputArr[k] = imputArr[k - gapSize];
                    k = k - gapSize;
                }
                imputArr[k] = val;
            }
            gapSize = gapSize / 2;
        }
        return 0;
    }

    static void Main()
    {
        int[] imputArr = { 36, 34, 43, 11, 15, 20, 28, 45 };

        Console.WriteLine("Arreglo antes de ser ordenado: ");
        ShellShort.displayArr(imputArr);

        ShellShort obj = new ShellShort();
        obj.sort(imputArr);

        Console.WriteLine("Arreglo despues de ser ordenado: ");
        ShellShort.displayArr(imputArr);
    }
}
