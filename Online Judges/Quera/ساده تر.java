/*
 * https://quera.org/problemset/3403/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class Sadetar {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = new int[4];
        int sum = 0;
        int product = 1;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < 4; i++) {
            arr[i] = in.nextInt();
            if(arr[i] > max)
                max = arr[i];
            if(arr[i] < min)
                min = arr[i];
            sum += arr[i];
            product *= arr[i];
        }
        System.out.format("Sum : %.06f\n", (float)sum);
        System.out.format("Average : %.06f\n", (float)sum / 4);
        System.out.format("Product : %.06f\n", (float)product);
        System.out.format("MAX : %.06f\n", (float)max);
        System.out.format("MIN : %.06f\n", (float)min);
    }
    
}
