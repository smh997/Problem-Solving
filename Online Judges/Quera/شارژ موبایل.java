/*
 * https://quera.org/problemset/17244/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Maliatchi {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int sum = 0;
        for(int i = n ; i > 0; i--){
            sum += i;
        }
        System.out.println(sum);
    }
    
}
