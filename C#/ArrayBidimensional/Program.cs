using System;
class Program {
    static void Main() {
        int r = 3, c = 3;
        int[,] TwoDArr = {{1,2,3},{4,5,6},{7,8,9}};
        int[] arr = new int[9];
        int k = 0;
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                k = x * c + y;
                arr[k] = TwoDArr[x,y];
            }
        }
        for (int i = 0; i < 9; i++) Console.Write(arr[i] + " ");
    }
}
