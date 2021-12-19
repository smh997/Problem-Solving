/*
 * https://open.kattis.com/problems/fibtour
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
long long int n, m, u, v;
int ans, c;
vector<long long int> fibs;
vector<int> vert[100003];
int dp[100003][100];
void fib_make(){
    fibs.push_back(1);
    fibs.push_back(1);
    long long int a=1, b=1, c;
    while(a+b<=1e18){
        c = a+b;
        fibs.push_back(c);
        a = b;
        b = c;
    }
}

int dfs(int a, int h){
    if(dp[a][h]!=-1)
        return dp[a][h];
    dp[a][h]=0;
    for (auto v: adj[a])
        for (auto hh: vert[v])
            if(hh-1==h)
                dp[a][h] = max(dp[a][h], 1+dfs(v, hh));
    return dp[a][h];
}

int main()
{
    fib_make();
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>u;
        auto tmp = find(fibs.begin(), fibs.end(), u);
        if(tmp!=fibs.end()){
            if(tmp==fibs.begin())
                vert[i].push_back(0),vert[i].push_back(1);
            else
                vert[i].push_back(tmp-fibs.begin());
        }
    }
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < fibs.size(); ++j)
            dp[i][j]=-1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for(auto h : vert[i])
            ans = max(ans, 1+dfs(i, h));
    cout<<ans<<endl;
    
    return 0;
}

