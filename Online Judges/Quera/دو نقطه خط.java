/*
 * https://quera.org/problemset/3414/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class DoNoghteKhat {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x1, y1, x2, y2;
        x1 = in.nextInt();
        y1 = in.nextInt();
        x2 = in.nextInt();
        y2 = in.nextInt();
        if(x1 == x2){
            System.out.println("Vertical");
        }
        else if(y1 == y2){
            System.out.println("Horizontal");
        }
        else{
            System.out.println("Try again");
        }
    }
    
}
