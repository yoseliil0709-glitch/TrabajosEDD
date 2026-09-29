public class Main {
    public static void main(String[] args) {
        int[] arr = {12, 34, 10, 6, 40, 89, 98};
        int target = 40;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                System.out.println("Elemento encontrado en posicion: " + (i + 1));
                return;
            }
        }
        System.out.println("Elemento no encontrado");
    }
}