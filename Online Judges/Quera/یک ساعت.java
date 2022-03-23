/*
 * https://quera.org/problemset/2886/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class yekSaat {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int h = in.nextInt();
        int m = in.nextInt();
        System.out.format("%02d:%02d", ((h == 0) ? h : 12 - h), ((m == 0) ? m : 60 - m));
    }
}
