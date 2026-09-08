using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        List<int> arr = new List<int>{11, 21, 31, 41, 51, 61};
        int pos = 2; //Elimina el 31
        arr.RemoveAt(pos);
        Console.WriteLine(string.Join(" ", arr));
    }
}
