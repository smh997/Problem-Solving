/*
 * https://quera.org/problemset/3429/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Yakhdarchi {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if(n > 100)
            System.out.println("Steam");
        else if(n < 0)
            System.out.println("Ice");
        else
            System.out.println("Water");
    }
    
}
