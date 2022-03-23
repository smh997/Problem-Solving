/*
 * https://quera.org/problemset/17902/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Ramz {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int k = in.nextInt();
        String r = in.next();
        String arr[] = new String[k];
        int sum = 0;
        for (int i = 0; i < k; i++) {
            arr[i] = in.next();
            if(r.charAt(i) == arr[i].charAt(0));
            else
                for (int j = 1; j < 5; j++) {
                    if(r.charAt(i) == arr[i].charAt(j) || r.charAt(i) == arr[i].charAt(9 - j)){
                        sum += j;
                    }
            }
        }
        System.out.println(sum);
    }
    
}
