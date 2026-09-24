public class Main {
    
    public static void main(String[] args) {
        int[] inputArr = {11, 21, 31, 41, 51, 61};
        int ele = 52;

        System.out.println("Antes de la insercion, el array es: ");
        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }

        // Insercion al final
        int[] newArr = new int[inputArr.length + 1];
        for(int j = 0; j < inputArr.length; j++) {
            newArr[j] = inputArr[j];
        }
        newArr[inputArr.length] = ele;
        inputArr = newArr;

        System.out.println("\nDespues de la insercion, el array es: ");
        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }
    }
}