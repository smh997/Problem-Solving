
import java.util.Scanner;

public class Testbinayee {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        String main=in.next();
        String input = in.next();
        int sum=0;
        for (int i = 0; i < n; i++) {
            if(input.charAt(i)!=main.charAt(i))
                sum++;
        }
        System.out.println(sum);
    }
    
}
