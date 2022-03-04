/*
 * https://quera.org/problemset/3404/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class EzafeVazn {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        float n = in.nextFloat();
        float m = in.nextFloat();
        float bmi = n / (m * m);        
        System.out.println(String.format("%.02f", bmi));
        if(bmi < 18.5){
            System.out.println("Underweight");
        }else if(bmi < 25){
            System.out.println("Normal");
        }else if(bmi < 30){
            System.out.println("Overweight");
        }else{
            System.out.println("Obese");
        }
    }
    
}
