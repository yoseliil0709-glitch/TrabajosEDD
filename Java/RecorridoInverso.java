public class Main {

    public static void main(String[] args) {

        int[] arr = {40, 50, 60, 70, 80, 90};
        System.out.print("Recorrido inverso: ");
        
        for(int i = arr.length - 1; i >= 0; i--) {

            System.out.print(arr[i] + " ");
        }
    }
}