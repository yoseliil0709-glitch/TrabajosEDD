using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        List<int> arr = new List<int>{11, 20, 31, 40, 51, 61};
        int ele = 52;
        arr.Insert(0, ele);
        Console.WriteLine(string.Join(" ", arr));
    }
}
