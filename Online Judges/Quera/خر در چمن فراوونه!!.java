/*
 * https://quera.org/problemset/4065/
 * Author: https://github.com/smh997/
 */
import java.util.*;
public class KharDarChaman {   
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a,b,l;
        a = in.nextInt();
        b = in.nextInt();
        l = in.nextInt();
        int res = (l / 2) * (a + b);
        res += (l % 2 != 0) ? a : 0;
        System.out.println(res);
    }
    
}
