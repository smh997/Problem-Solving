/*
 * https://quera.org/problemset/2636/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class ShatranjHerfei {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] input = new int[6];
        int arr[]={1, 1, 2, 2, 2, 8};
        for (int i = 0; i < 6; i++) {
            input[i] = in.nextInt();
            System.out.print(arr[i] - input[i] + " ");
        }
    }
    
}
