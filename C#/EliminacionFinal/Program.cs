using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        List<int> arr = new List<int>{11, 21, 31, 41, 51, 61};
        arr.RemoveAt(arr.Count - 1);
        Console.WriteLine(string.Join(" ", arr));
    }
}
