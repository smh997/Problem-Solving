/*
 * https://open.kattis.com/problems/geppetto
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

int n, m, a, b;
int used[23];
int is_ok[23][23];

void init(){
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
            is_ok[i][j] = 1;
}

int calc(int i){
    if(i > n)
        return 1;
    int ans = calc(i+1);
    for (int j = 1; j <= i-1; j++)
    {
        if(used[j] && !is_ok[i][j]){
            return ans;
        }
    }
    used[i] = 1;
    ans += calc(i+1);
    used[i] = 0;
    return ans;
}

int main(){
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        is_ok[a][b] = is_ok[b][a] = 0;
    }
    
    cout << calc(1) << endl;
    
    return 0;
}