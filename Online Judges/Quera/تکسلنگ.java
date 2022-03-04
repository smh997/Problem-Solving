/*
 * https://quera.org/problemset/17245/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Texlang {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] block = new String[3];
        for (int i = 0; i < 3; i++) {
            block[i] = in.next();
        }
        for (int i = 0; i < block[0].length() / 5; i++) {
            if(block[0].charAt(5 * i) == '*'){
                if(block[0].charAt(5 * i + 1) == '*'){
                    if(block[0].charAt(5 * i + 2) == '*')
                        System.out.print("T");
                    else
                        System.out.print("M");
                }
                else if(block[1].charAt(5 * i) == '*')
                    System.out.print("N");
                else System.out.print("X");
            }
            else
                System.out.print("A");
        }
    }
}
