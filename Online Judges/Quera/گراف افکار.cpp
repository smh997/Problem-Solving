/*
 * https://quera.org/problemset/80648/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, m, mat[maxn][maxn];
vector<int> adjs[maxn];
int color[maxn];
bool bicolorable = true;

void dfs(int u, int c){
    color[u] = c;
    for(int x : adjs[u]){
        if(color[x] == 2)
            dfs(x, 1 - c); // swap the color!
        else if(color[x] == color[u])
            bicolorable = false;
    }
}

int k;

#define num long long int

const num mod = 1e9 + 7;

int main(){
    cin >> n >> m >> k;
    int x, y;
    for(int i = 0; i < m; i++)
        cin >> x >> y, x--, y--, mat[x][y] = mat[y][x] = 1, adjs[x].push_back(y), adjs[y].push_back(x);
    fill_n(color, n, 2);
    for(int i = 0; i < n; i++)
        if(color[i] == 2)
            dfs(i, 1);
    num ans = 1;
    num z = ((num)n * (n - 1)) / 2 - m;
    for(num i = z - k + 1; i <= z; i++)
        ans = (ans * i) % mod;
    if(!bicolorable){
        cout << ans << endl;
        return 0;
    }
    num a = 0, b = ((num)n * (n - 1)) / 2 - m;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(!mat[i][j] && color[i] == color[j])
                a++, b--;
    if(b < k){
        cout << ans << endl;
        return 0;
    }
    num d = 1;
    for(num i = b - k + 1; i <= b; i++)
        d = (d * i) % mod;
    cout << ans - d << endl;   
}