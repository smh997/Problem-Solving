/*
 * https://open.kattis.com/problems/maximizingwinnings
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int mindp[53][5003], maxdp[53][5003];
int n, m, graph[53][53];
int cmindp(int cur, int mm){
    if(mindp[cur][mm]!=INT_MAX)
        return mindp[cur][mm];
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        res = min(graph[cur][i] + cmindp(i, mm-1), res);
    }
    return mindp[cur][mm] = res;
}
int cmaxdp(int cur, int mm){
    if(maxdp[cur][mm]!=INT_MIN)
        return maxdp[cur][mm];
    int res = INT_MIN;
    for (int i = 0; i < n; ++i) {
        res = max(graph[cur][i] + cmaxdp(i, mm-1), res);
    }
    return maxdp[cur][mm] = res;
}
int main()
{
    while(cin>>n){
        if(!n)break;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin>>graph[i][j];
        cin>>m;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                mindp[i][j] = INT_MAX;
                maxdp[i][j] = INT_MIN;
            }
            mindp[i][0]=0;
            maxdp[i][0]=0;
        }
        cout<<cmaxdp(0, m)<<" "<<cmindp(0, m)<<endl;
    }
    return 0;
}

