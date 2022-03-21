/*
 * https://quera.org/contest/assignments/40731/problems/137866
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define num long long int

const int maxn = 503;

int n, m, q;
num sp[maxn][maxn];
num a[500003], b[500003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(i == j)
                sp[i][j] = 0;
            else
                sp[i][j] = inf;
        }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        sp[u][v] = (num)1;
        sp[v][u] = sp[u][v];
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(sp[i][k] != inf && sp[k][j] != inf && sp[i][k] + sp[k][j] < sp[i][j])
                    sp[i][j] = sp[i][k] + sp[k][j];
    cin >> q;
    num res = 0;
    bool fff = false;
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < q; ++i) {
        cin >> b[i];
        b[i]--;
        if(!fff){
            if(b[i] != a[i]){
                if(sp[b[i]][a[i]] == inf){
                    res = inf;
                    fff = true;
                }
                else{
                    res += sp[b[i]][a[i]];
                }
            }
        }
    }
    if(fff)
        cout << -1 << endl;
    else
        cout << res << endl;
}
