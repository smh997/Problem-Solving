/*
 * https://open.kattis.com/problems/cuchitunnels
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
int deg[1003];
bool vis[1003];
bool flag;

void dfs(int u){
    vis[u] = true;
    for (int i = u+1; i < n; ++i) {
        if(deg[u] == 0){
            break;
        }
        if(!vis[i]){
            deg[u]--;
            deg[i]--;
            dfs(i);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> deg[i];
    }
    dfs(0);
    flag = true;
    for (int i = 0; i < n; ++i) {
        if(deg[i])
            flag = false;
    }
    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

