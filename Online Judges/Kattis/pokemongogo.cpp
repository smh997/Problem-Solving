/*
 * https://open.kattis.com/problems/pokemongogo
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, r, c, uniqc = 0;
string name;
vector<pair<string, pair<int, int>>> pstops;
set<string> uniqp;
map<string , int> id;
int dp[25][1 << 21];

int cdp (int i, int mask) {
    if (dp[i][mask] != -1)
        return dp[i][mask];

    if (i == 0 && mask & 1)
        return dp[i][mask] = (mask == (1 << uniqc) - 1) ? 0 : 1e9;

    int cur_r = pstops[i].second.first;
    int cur_c = pstops[i].second.second;
    int ans = INT_MAX;

    for (int j = 0; j <= n; j++){
        if (j == i)
            continue;

        if (!(mask & (1 << id[pstops[j].first]))){
            int cost = abs(pstops[j].second.first - cur_r) + abs(pstops[j].second.second - cur_c);
            ans = min(ans, cost + cdp(j, (mask | (1 << id[pstops[j].first]))));
        }
    }

    return dp[i][mask] = ans;
}

int main(){
    
    uniqp.insert("p1");
    pstops.push_back({"p1", {0, 0}});
    id["p1"] = uniqc++;
    
    cin >> n;

    for (int i = 0; i < n; i++){
        
        cin >> r >> c >> name;
        
        if (uniqp.find(name) == uniqp.end()) {
            id[name] = uniqc++;
            uniqp.insert(name);
        }
        pstops.push_back({name, {r, c}});
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < (1 << uniqc); j++)
            dp[i][j] = -1;
    
    cout << cdp(0, 0) << endl;
    
    return 0;
}