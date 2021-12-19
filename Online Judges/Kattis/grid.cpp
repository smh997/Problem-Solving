/*
 * https://open.kattis.com/problems/grid
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int grid[503][503];
char gridc[503][503];
int dist[503][503];
int n, m, d, nexr, nexc;
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {1, 0, -1, 0};
bool inrange(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int main()
{
    cin>>n>>m;
    pair<int, int> a;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin>>gridc[i][j],grid[i][j]=gridc[i][j]-'0', dist[i][j] = INT_MAX;
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        a = q.front(); q.pop();
        d = grid[a.first][a.second];
        for (int i = 0; i < 4; ++i) {
            nexr = a.first+dirr[i]*d;nexc = a.second+dirc[i]*d;
            if(inrange(nexr, nexc) && dist[nexr][nexc]>dist[a.first][a.second]+1){
                dist[nexr][nexc]=dist[a.first][a.second]+1;
                q.push({nexr, nexc});
            }
        }
    }
    cout<<((dist[n-1][m-1]==INT_MAX)?-1:dist[n-1][m-1])<<endl;
        
    return 0;
}

