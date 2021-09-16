/*
 * https://open.kattis.com/problems/vegetables
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

double t;
int n, res = INT_MAX;
double veg[1003];
int main()
{
    cin >> t >> n;
    for (int i = 0; i < n; ++i)
        cin >> veg[i];
    double maxveg, minveg;
    int cuts;
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 500; ++c) {
            minveg = maxveg = veg[i]/(c+1);
            cuts = c;
            if(cuts >= res)
                continue;
            for(int j = 0; j < n; j++){
                if(i==j)
                    continue;
                int k = ceil(veg[j] / maxveg) - 1;
                cuts += k;
                if(cuts >= res)
                    break;
                minveg = min(minveg, veg[j] / (k + 1));
            }
            if(minveg / maxveg > t)
                res = min(res, cuts);
        }
    }
    cout << res << endl;
    return 0;
}

