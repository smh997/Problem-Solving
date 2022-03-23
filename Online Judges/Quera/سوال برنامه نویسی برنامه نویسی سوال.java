/*
 * https://quera.org/problemset/3408/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class SoalBarnamenevisiBarnamenevisiSoal {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.next();
        }
        for (int i = n - 1; i >= 0; i--) {
            System.out.print(arr[i] + " ");
        }
    }
    
}
