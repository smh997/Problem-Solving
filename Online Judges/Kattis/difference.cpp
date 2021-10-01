/*
 * https://open.kattis.com/problems/difference
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool vis[200001003];
vector<long long> v;
long long c = 1, curr, res = 1;

int main () {
    long long a, m;
    cin >> a >> m;
    vis[a] = true;
    curr = a;
    v.push_back(a);
    while (!vis[m]) {
        while (vis[c])c++;
        curr += c;
        for (long long b : v)
            if (curr - b <= m)
               vis[curr - b] =true;
        v.push_back(curr);
        if(c < m + 1000) vis[c] = true;
        if(curr < m + 1000) vis[curr] = true;
        res++;
    }
    cout << res << endl;
}

