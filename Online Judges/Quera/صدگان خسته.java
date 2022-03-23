/*
 * https://quera.org/problemset/3406/
 * Author: https://github.com/smh997/
 */
import java.util.Arrays;
import java.util.Scanner;

public class SadeganKhaste {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        char[] sa = (String.valueOf(a)).toCharArray();
        char[] sb = (String.valueOf(b)).toCharArray();
        char tmp = sa[2];
        sa[2] = sa[0];
        sa[0] = tmp;
        tmp = sb[2];
        sb[2] = sb[0];
        sb[0] = tmp;
        if(Arrays.toString(sa).compareTo(Arrays.toString(sb)) > 0){
            System.out.println(b + " < " + a);
        }
        else if(Arrays.toString(sa).compareTo(Arrays.toString(sb)) == 0){
            System.out.println(b + " = " + a);   
        }
        else{
            System.out.println(a + " < " + b);               
        }
        
    }
}
