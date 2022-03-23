/*
 * https://quera.org/problemset/2794/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Doorbin {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[][] arr = new int[3][2];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                arr[i][j] = in.nextInt();
            }
        }
        int[] res = new int[2];
        res[0] = arr[0][0];
        res[1] = arr[0][1];

        if (res[0] == arr[1][0]) {
            res[0] = arr[2][0];
            if(res[1] == arr[2][1])
                res[1] = arr[1][1];
        } 
        else if(res[0] == arr[2][0]) {
            res[0] = arr[1][0];
            if(res[1] == arr[1][1])
                res[1] = arr[2][1];
        }
        else{
            if(res[1] == arr[1][1])
                res[1] = arr[2][1];
            else
                res[1] = arr[1][1];
        }
        System.out.println(res[0] + " " + res[1]);

    }

}
