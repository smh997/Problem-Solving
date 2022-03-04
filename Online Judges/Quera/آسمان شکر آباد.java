/*
 * https://quera.org/problemset/6082/
 * Author: https://github.com/smh997/
 */

import java.util.Scanner;

public class AsemanShekarestan {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int sum = 0;
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.next();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i].charAt(j) == '*')
                    sum++;
            }
        }
        System.out.println(sum);
    }

}
