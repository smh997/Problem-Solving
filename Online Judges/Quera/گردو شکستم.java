/*
 * https://quera.org/problemset/3540/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class GerdooShekastam {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, x, y;
        n = in.nextInt();
        x = in.nextInt();
        y = in.nextInt();
        for (int i = 0; i <= n / x; i++) {
            if((n - (i * x)) % y == 0){
                System.out.println(i + " " + ((n - (i * x)) / y));
                return;
            }
        }
        System.out.println(-1);
    }
}
