/*
 * https://quera.org/problemset/3558/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class ErsalSangin {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        int m = in.nextInt();
        int[][] arr1 = new int[n][2];
        int[][] arr2 = new int[m][2];
        for (int i = 0; i < n; i++) {
            arr1[i][0] = in.nextInt();
            arr1[i][1] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            arr2[i][0] = in.nextInt();
            arr2[i][1] = in.nextInt();
        }
        int sum = 0;
        for(int i = 0; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(arr1[i][0] <= arr2[j][0] && arr1[i][1] >= arr2[j][0]){
                   sum += Math.min(arr1[i][1], arr2[j][1]) - arr2[j][0] + 1; 
                }
                else if(arr2[j][0] <= arr1[i][0] && arr2[j][1] >= arr1[i][0]){
                   sum += Math.min(arr1[i][1], arr2[j][1]) - arr1[i][0] + 1; 
                }
            }
        }
        System.out.println(sum);
    }
    
}
