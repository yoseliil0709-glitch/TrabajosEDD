using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        List<int> arr = new List<int>{11, 21, 31, 41, 51, 61};
        int ele = 52;
        arr.Add(ele);
        Console.WriteLine(string.Join(" ", arr));
    }
}
