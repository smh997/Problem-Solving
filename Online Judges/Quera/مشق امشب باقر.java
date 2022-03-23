/*
 * https://quera.org/problemset/10230/
 * Author: https://github.com/smh997/
 */
import java.util.*;
public class Moghadamati1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = new int[3];
        int sum = 0;
        boolean flag = false;
        for(int i = 0 ; i < arr.length ; i++){
            arr[i] = in.nextInt();
            if(arr[i] == 0){
                System.out.println("No");
                flag = true;
                break;
            }
            sum += arr[i];            
        }
        if(!flag){
            if(sum == 180)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}
