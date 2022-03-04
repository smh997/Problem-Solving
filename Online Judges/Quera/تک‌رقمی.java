/*
 * https://quera.org/problemset/3539/
 * Author: https://github.com/smh997/
 */
import java.util.*;

public class Takraghami {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String n = in.next();
        int sum = 0;
        
        while (true) {
            sum=0;
            for (int i = 0; i < n.length(); i++) {
                sum += Character.getNumericValue(n.charAt(i));
            }
            
            if(sum < 10)
                break;
            else
                n = String.format("%d", sum) ;
        }
        System.out.println(sum);
    }

}
