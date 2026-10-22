public class InsercionInicio {
    public static void main(String[] args) {
        int[] inputArr = {11, 21, 31, 41, 51, 61};
        int ele = 52;

        System.out.println("Antes de la insercion, el array es: ");
        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }

        // Insercion del elemento en el indice 0
        int[] newArr = new int[inputArr.length + 1];
        newArr[0] = ele;
        for(int j = 0; j < inputArr.length; j++) {
            newArr[j + 1] = inputArr[j];
        }
        inputArr = newArr;

        System.out.println("\nDespues de la insercion, el array es: ");
        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }
    }
}