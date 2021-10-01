/*
 * https://open.kattis.com/problems/elementarymath
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 2503;
int n, k = 0;
pair<num, num> a[maxn];
map<num, int> b;
num id[3 * maxn];
vector<pair<char, int>> adjs[maxn];
bool vis[maxn];
int match[3 * maxn];

int aug(int u){
    if(vis[u])
        return 0;
    vis[u] = 1;
    for(auto x : adjs[u]){
        int v = x.second;
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        num ans = a[i].first * a[i].second;
        if(b.find(ans) == b.end())
            b[ans] = k, id[k++] = ans;
        adjs[i].push_back({'*', b[ans]});
        ans = a[i].first + a[i].second;
        if(b.find(ans) == b.end())
            b[ans] = k, id[k++] = ans;
        adjs[i].push_back({'+', b[ans]});
        ans = a[i].first - a[i].second;
        if(b.find(ans) == b.end())
            b[ans] = k, id[k++] = ans;
        adjs[i].push_back({'-', b[ans]});
    }
    fill_n(match, k, -1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        fill_n(vis, n, 0);
        ans += aug(i);
    }
    if(ans != n){
        cout << "impossible" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(auto x : adjs[i])
            if(match[x.second] == i){
                cout << a[i].first << " " << x.first << " " << a[i].second << " = " << id[x.second] << endl;
                break;
            }
}