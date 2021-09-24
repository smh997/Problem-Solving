/*
 * https://open.kattis.com/problems/beepers
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int dp[11][1<<11];
int t, m, w, h, b, x, y;
pair<int, int> points[11];
int dist[11][11];
int calc(int i, int j){
    return abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second);
}

int tsp(int pos, int mask){
    if(dp[pos][mask]!=INT_MAX)
        return dp[pos][mask];
    if(mask==(1<<(m+1))-1)
        return dp[pos][mask]=dist[pos][0];
    int res = INT_MAX;
    for (int i = 0; i < m+1; ++i) {
        if(i!=pos && !(mask & (1<<i)))
            res=min(res, dist[pos][i]+tsp(i, mask|(1<<i)));
    }
    return dp[pos][mask] = res;
}

int main()
{
    cin>>t;
    while(t--){
        cin>>w>>h;
        cin>>points[0].first>>points[0].second;
        cin>>m;
        for (int i = 1; i <= m; ++i)
            cin>>points[i].first>>points[i].second;
        for (int i = 0; i < m+1; ++i) {
            for (int j = i+1; j < m+1; ++j) {
                dist[i][j] = dist[j][i] = calc(i, j);
            }
            for (int j = 0; j < 1<<(m+1); ++j) {
                dp[i][j]=INT_MAX;
            }
        }
        cout<<tsp(0, 0)<<endl;
    }
    return 0;
}

