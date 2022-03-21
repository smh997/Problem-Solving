/*
 * https://quera.org/contest/assignments/39254/problems/135666
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

long long int m, n, maxPackages, maxWeight;
long long int deliveryCenter, weight;
pair<long long int, long long int> packages[10003];
long long int dp[10003];


long long int cdp(int i){
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    long long int w = 0, p = 0, ans = 0, res = INT_MAX;
    int prevcenter = -1;
    for (int j = i; j < n; ++j) {
        if (p + 1 <= maxPackages && w + packages[j].second <= maxWeight){
            p++;
            w += packages[j].second;
            if (prevcenter != packages[j].first){
                ans++;
                prevcenter = packages[j].first;
            }
        }
        else{
            ans++;
            res = min(cdp(j) + ans, res);
            break;
        }
        res = min(cdp(j+1) + ans + 1, res);
    }
//    cerr << i << " " << w << " " << p << " " << res << endl;
    return dp[i] = res;
}


int main()
{
    cin >> m >> n >> maxPackages >> maxWeight;
    for (int i = 0; i < n; ++i) {
        cin >> deliveryCenter >> weight;
        packages[i] = {deliveryCenter, weight};
    }
    fill_n(dp, n+1, -1);
    cout << cdp(0) << endl;
    return 0;
}

