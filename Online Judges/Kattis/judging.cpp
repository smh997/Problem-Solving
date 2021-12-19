/*
 * https://open.kattis.com/problems/judging
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
int n;
map<string, int> d;
int dom[maxn], kattis[maxn];
int cnt = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(d.find(s) == d.end())
            d[s] = cnt++;
        dom[d[s]]++;
    }
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(d.find(s) != d.end())
            kattis[d[s]]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(dom[i] != 0)
            ans += min(dom[i], kattis[i]);
    cout << ans << endl;
}