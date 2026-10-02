public class SeleccionSort {
    static void selectionSort(int[] a) {
        int n = a.length;
        for (int i = 0; i < n-1; i++) {
            int min_idx = i;
            for (int j = i+1; j < n; j++) {
                if (a[j] < a[min_idx]) min_idx = j;
            }
            int temp = a[min_idx];
            a[min_idx] = a[i];
            a[i] = temp;
        }
    }
    public static void main(String[] args) {
        int[] a = {64, 25, 12, 22, 11};
        System.out.println("Antes de ordenar: ");
        for (int i = 0; i < a.length; i++) System.out.print(a[i] + " ");
        selectionSort(a);
        System.out.println("\nDespues de ordenar: ");
        for (int i = 0; i < a.length; i++) System.out.print(a[i] + " ");
    }
}