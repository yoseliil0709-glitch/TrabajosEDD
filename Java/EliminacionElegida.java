public class Main {
    public static void main(String[] args) {

        int[] inputArr = {11, 21, 31, 41, 51, 61};
        int position = 3;

        System.out.println("Antes de la eliminacion, el array es: ");
        // Para mostrar el antes, necesitamos el array original
        // 11 21 31 41 51 61

        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }

        // Eliminacion del elemento en el indice 3
        int[] newArr = new int[inputArr.length - 1];

        for(int j = 0, k = 0; j < inputArr.length; j++) {
            if(j == position) continue;
            newArr[k++] = inputArr[j];
        }

        inputArr = newArr;

        System.out.println("\nDespues de la eliminacion, el array es: ");
        
        for(int j = 0; j < inputArr.length; j++) {
            System.out.print(inputArr[j] + " ");
        }
    }
}