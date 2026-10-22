using System;
class Program {
    static void Main() {
        int[] arr = {12, 34, 10, 6, 40, 89, 98, 57, 19, 69};
        int target = 40;
        Array.Sort(arr);
        int l = 0, h = arr.Length - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == target) {
                Console.Write("Elemento encontrado en posicion: " + (mid+1));
                return;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        Console.Write("Elemento no encontrado");
    }
}
