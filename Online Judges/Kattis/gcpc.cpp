/*
 * https://open.kattis.com/problems/gcpc
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, q;
set<pair<int, pair<int, int>>> s;
pair<int, int> m[maxn];

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        s.insert({0, {0, i}}), m[i] = {0, 0};
    int t, p;
    int ans = 1;
    while(q--){
        scanf("%d %d", &t, &p);
        pair<int, int> data = m[t];
        pair<int, pair<int, int>> info = {data.first, {data.second, t}};
        s.erase(info);
        bool down = data >= m[1];
        data.first--, data.second += p;
        m[t] = data;
        info = {data.first, {data.second, t}};
        s.insert(info);
        if(t != 1){
            if(down && data < m[1])
                ans++;
        }
        else
            ans = distance(s.begin(), s.find(info)) + 1;
        printf("%d\n", ans);
    }
}