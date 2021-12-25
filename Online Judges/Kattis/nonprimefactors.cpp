/*
 * https://open.kattis.com/problems/nonprimefactors
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int saved[2000001];
    fill_n(saved, 2000001, 0);
    bool prime[2000001];
    fill_n(prime, 2000001, true);
    prime[1] = false;
    for (int i = 2; i <= (int)sqrt(2000001); i++)
        if (prime[i])
            for (int j = 2*i; j < 2000001; j += i)
                prime[j] = false;
    int n, inp, main_inp, p, f, c;
    scanf("%d\n", &n);
    while (n--) {
        scanf("%d\n", &inp);
        if (saved[inp]) {
            printf("%d\n", saved[inp]);
            continue;
        }
        if (prime[inp]) {
            printf("1\n");
            continue;
        }
        main_inp = inp;
        p = 0, f = 1;
        if (inp%2==0) {
            p++;
            c = 0;
            while (inp%2==0) {
                c++;
                inp /= 2;
            }
            f *= c + 1;
        }
        if (prime[inp])
            p++, f *= 2;
        else {
            for (int pr = 3; pr <= sqrt(inp); pr += 2)
                if (inp % pr == 0) {
                    p++;
                    c = 0;
                    while (inp % pr == 0) {
                        c++;
                        inp /= pr;
                    }
                    f *= c + 1;
                }
            if (prime[inp])
                p++, f *= 2;
            
        }
        saved[main_inp] = f - p;
        printf("%d\n", f-p);
    }
    return 0;
}