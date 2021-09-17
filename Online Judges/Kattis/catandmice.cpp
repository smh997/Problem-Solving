/*
 * https://open.kattis.com/problems/catandmice
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Cat and Mice

#define inf LLONG_MAX

int n, msize[(1<<15)+3];
double x[15+3], y[15+3], s[15+3];
double m, p[15+3], dp[(1<<15)+3][15+3];

int main(){
    cin >> n;
    for(int mask = 1; mask < (1 << n); mask++){
        int cp = mask;
        while(cp){
            if(cp % 2)
                msize[mask]++;
            cp /= 2;
        }
    }
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> s[i];
    cin >> m;
    p[0] = 1.0;
    for(int i = 1; i < 15; i++)
        p[i] = p[i-1] * m;
    double lo = 0, hi = 1e9;
    while(fabs(hi - lo) > 1e-8){
        double v = (lo + hi) / 2;
        // cerr << v << endl;
        for(int mask = 1; mask < (1 << n); mask++)
            for(int mouse = 0; mouse < n; mouse++){
                dp[mask][mouse] = inf;
                if(mask == 1 << mouse){
                    double dt = sqrt(double(x[mouse] * x[mouse] + y[mouse] * y[mouse])) / v;
                    if(dt <= s[mouse])
                        dp[mask][mouse] = dt;
                    // cerr << mask << " " << mouse << " " << dp[mask][mouse] << endl;
                }
                else if(mask & (1 << mouse)){
                    for(int prevy = 0; prevy < n; prevy++)
                        if((mask & (1 << prevy)) && prevy != mouse && dp[mask-(1<<mouse)][prevy] != inf){
                            double dx = x[prevy] - x[mouse], dy = y[prevy] - y[mouse];
                            double dt = sqrt(dx * dx + dy * dy) / (v * p[msize[mask]-1]);
                            if(dp[mask-(1<<mouse)][prevy] + dt <= s[mouse])
                                dp[mask][mouse] = min(dp[mask][mouse], dp[mask-(1<<mouse)][prevy] + dt);
                        }
                    // cerr << mask << " " << mouse << " " << dp[mask][mouse] << endl;
                }
            }
        bool judge = false;
        for(int mouse = 0; mouse < n; mouse++)
            if(dp[(1 << n) - 1][mouse] != inf){
                judge = true;
                break;
            }
        if(judge)
            hi = v;
        else
            lo = v;
    }
    cout << fixed << setprecision(10) << lo << endl;
}