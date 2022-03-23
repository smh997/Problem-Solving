/*
 * https://quera.org/problemset/4067/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Sarab {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int x, y;
        for (int i = 0; i < t; i++) {
            x = in.nextInt();
            y = in.nextInt();
            if (x == y) {
                if (x % 2 == 0) {
                    System.out.println(x + y);
                } else {
                    System.out.println(2 * x - 1);
                }
            } else if (y == (x - 2)) {
                if (x % 2 != 0) {
                    System.out.println(2 * y + 1);
                } else {
                    System.out.println(x + y);
                }
            } else {
                System.out.println(-1);
            }

        }
    }

}
