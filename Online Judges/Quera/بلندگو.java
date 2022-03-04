/*
 * https://quera.org/problemset/3430/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(s.charAt(i));
            }
            for (int k = i + 1; k < n; k++) {
                System.out.print(s.charAt(k));
            }
            System.out.println("");
        }
    }
    
}
