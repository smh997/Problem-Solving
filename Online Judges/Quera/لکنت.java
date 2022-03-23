/*
 * https://quera.org/problemset/2530/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Loknat {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        int res = 1;
        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == 'T' || str.charAt(i) == 'D' || str.charAt(i) == 'L' || str.charAt(i) == 'F')
                res *= 2;
        }
        System.out.println(res);
    }
}
