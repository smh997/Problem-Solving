/*
 * https://quera.org/problemset/17246/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;


public class MaliatchiJael {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if(n == 1){
            System.out.println(2);
        }
        else if(n == 2){
            System.out.print(4);
        }
        else{
            long[] arr = new long[3];
            long mod = 1000000007;
            long a = 1, b = 1, c = 1;
            for (int i = 3; i <= n; i++) {
                arr[0] = (a + b) % mod;
                arr[1] = c;
                arr[2] = a;
                a = arr[0];
                b = arr[1];
                c = arr[2];
            }
            System.out.println((arr[0] + arr[1] + arr[2]) % mod);
        }  
    }
}
