/*
 * https://quera.org/problemset/3409/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class JadvalZarbGonde {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print((i + 1) * (j + 1) + " ");
            }
            System.out.println();
        }
    }
    
}
