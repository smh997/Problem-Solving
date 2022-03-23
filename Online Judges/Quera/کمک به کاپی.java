/*
 * https://quera.org/problemset/8838/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class KomakBeCopy {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        for (int i = 0; i < n; i++) {
            System.out.print("copy of ");
        }
        System.out.print(s);
    }
    
}
