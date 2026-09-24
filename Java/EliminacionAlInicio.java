public class Main {
    public static void main(String[] args) {

        int[] inputArr = {11, 21, 31, 41, 51, 61};

        System.out.println("Antes de la eliminacion, el array es: ");

        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }

        // Eliminando el primer elemento inputArr[0]
        int[] newArr = new int[inputArr.length - 1];

        for(int j = 1; j < inputArr.length; j++) {
            newArr[j - 1] = inputArr[j];
        }
        inputArr = newArr;

        System.out.println("\nDespues de la eliminacion, el array es: ");
        
        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }
    }
}