/*
 * https://open.kattis.com/problems/ballotboxes
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int population[500003];
int n, b, mx;

bool judge (int ballot_size){
    int need = 0;
    for (int i = 0; i < n; ++i)
        need += ceil(1.0 * population[i] / ballot_size);
    return b >= need;
}

int main()
{
    while (true) {
        cin >> n >> b;
        if (n == -1 && b == -1)
            break;
        mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> population[i];
            mx = max(mx, population[i]);
        }
        int lo = 1, hi = mx + 3, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (judge(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo << endl;
    }
    
    return 0;
}

