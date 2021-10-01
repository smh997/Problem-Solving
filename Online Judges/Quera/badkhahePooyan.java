
import java.util.Scanner;

public class BadkhahePooyan {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        int p=in.nextInt();
        int d=in.nextInt();
        int pro=d;
        int rem=pro%p;
        while(rem>p/2){
            pro+=d;
            rem=pro%p;
        }
        System.out.println(pro);
    }
    
}
