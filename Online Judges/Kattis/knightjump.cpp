/*
 * https://open.kattis.com/problems/knightjump
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;


int dist[103][103];char grid[103][103];
int n, a, b;
queue<pair<int, int>> q;

int dirx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int diry[8] = {1, -1, -2, -2, -1, 1, 2, 2};

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<n && j<n;
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='K')
                a=i, b=j;
        }
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
            dist[j][k]=INT_MAX;
    q.push({a, b}); dist[a][b]=0;
    pair<int, int> p;
    while(!q.empty()){
        p = q.front(); q.pop();
        a = p.first; b = p.second;
        for (int j = 0; j < 8; ++j) {
            if(inrange(a+diry[j], b+dirx[j]) && grid[a+diry[j]][b+dirx[j]] == '.' && dist[a][b] + 1 < dist[a+diry[j]][b+dirx[j]]){
                dist[a+diry[j]][b+dirx[j]] = dist[a][b] + 1;
                q.push({a+diry[j], b+dirx[j]});
            }
        }
    }
    cout<<((dist[0][0]==INT_MAX)?-1:dist[0][0])<<endl;
    
    return 0;
}

