/*
 * https://quera.org/problemset/3538/
 * Author: https://github.com/smh997/
 */

import java.util.*;

public class Taraf {

    public static void main(String[] args) {
        int n;
        Scanner in = new Scanner(System.in);
        boolean[] week = new boolean[7];
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            n = in.nextInt();
            for (int j = 0; j < n; j++) {
                switch (in.next()) {
                    case "shanbe":
                        week[0] = true;
                        break;
                    case "1shanbe":
                        week[1] = true;
                        break;
                    case "2shanbe":
                        week[2] = true;
                        break;
                    case "3shanbe":
                        week[3] = true;
                        break;
                    case "4shanbe":
                        week[4] = true;
                        break;
                    case "5shanbe":
                        week[5] = true;
                        break;
                    case "jome":
                        week[6] = true;
                        break;
                }
            }
        }
        for (int j = 0; j < week.length; j++) {
            if (week[j] == false) {
                sum++;
            }
        }
        System.out.println(sum);
    }

}
