/*
 * https://quera.org/problemset/3410/
 * Author: https://github.com/smh997/
 */
import java.lang.reflect.Array;
import java.util.Scanner;

public class MosalasKhayam {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        int[] arr2 = new int[n];
        arr[0] = 1;
        arr2[0] = 1;
        for (int j = 1; j < n + 1; j++) {
            System.out.print(arr[0] + " ");
            for (int i = 1; i < j; i++) {
                arr2[i] = arr[i] + arr[i - 1];
                System.out.print(arr2[i] + " ");
            }
            for (int i = 0; i < n; i++) {
                arr[i] = arr2[i];
            }
            System.out.println("");
        }
    }
}
