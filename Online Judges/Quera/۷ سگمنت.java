/*
 * https://quera.org/problemset/18212/
 * Author: https://github.com/smh997/
 */
import java.util.Scanner;

public class SevenSegment {

    @SuppressWarnings("empty-statement")
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        long res = 0;
        String s = in.next();
        String b = s.substring(s.indexOf("e") + 1);
        int bb = Integer.parseInt(b);
        int c = arr[Integer.parseInt(s.substring(0, 1))];
        res += c;
        boolean flag = s.contains(".");
        if (flag) {
            String a = s.substring(s.indexOf(".") + 1, s.indexOf("e"));
            bb -= a.length();
            char[] ch = a.toCharArray();
            for (int i = 0; i < a.length(); i++) {
                res+=arr[ch[i] - 48];
            }
        }
        res += bb * arr[0];
        System.out.println(res);
    }

}
