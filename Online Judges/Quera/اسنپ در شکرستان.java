/*
 * https://quera.org/problemset/8938/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class ShekarestanSnap {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] cost = new int[n][n];
        int[][] xy = new int[m][2];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = in.nextInt();
            }
        }
        int sum = 0;
        for (int i = 0; i < m; i++) {
            xy[i][0] = in.nextInt();
            xy[i][1] = in.nextInt();
            sum += cost[xy[i][0]-1][xy[i][1]-1];
        }
        System.out.println(sum);
    }
    
}
