/*
 * https://open.kattis.com/problems/mallmania
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int dist[2003][2003];
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};
int p1, p2, x, y;
vector<pair<int, int>> targs;

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<2003 && j<2003;
}

int main()
{
    while(cin>>p1){
        if(!p1)
            break;
        for (int i = 0; i < 2003; ++i) {
            for (int j = 0; j < 2003; ++j) {
                dist[i][j] = INT_MAX;
            }
        }
        queue<pair<int, int>> q; pair<int, int> p;
        for (int i = 0; i < p1; ++i) {
            cin>>x>>y;
            dist[x][y] = 0;
            q.push({x, y});
        }
        targs.clear();
        cin>>p2;
        for (int i = 0; i < p2; ++i) {
            cin>>x>>y;
            targs.push_back({x, y});
        }
        while (!q.empty()) {
            p = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                if(inrange(p.first+dirx[i], p.second+diry[i]) && dist[p.first][p.second]+1<dist[p.first+dirx[i]][p.second+diry[i]]){
                    dist[p.first+dirx[i]][p.second+diry[i]] = dist[p.first][p.second] + 1;
                    q.push({p.first+dirx[i], p.second+diry[i]});
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < p2; ++i)
            res = min(dist[targs[i].first][targs[i].second], res);
        cout<<res<<endl;
        
    }
    return 0;
}

