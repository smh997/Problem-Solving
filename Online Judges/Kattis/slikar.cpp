/*
 * https://open.kattis.com/problems/slikar
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 53
int R, C;
char grid[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
pair<int, int> S, D;
int dirr[4] = {0, -1, 0, 1};
int dirc[4] = {-1, 0, 1, 0};

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<R && j<C;
}

int main()
{
    cin>>R>>C;
    queue<pair<char, pair<int, int>>> q;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j){
            cin>>grid[i][j];dist[i][j]=INT_MAX;
            if(grid[i][j]=='*')
                q.push({'*',{i, j}});
            else if(grid[i][j]=='S')
                S.first = i, S.second=j;
            else if(grid[i][j]=='D')
                D.first = i, D.second=j;
        }
    q.push({'S', {S.first, S.second}});
    dist[S.first][S.second]=0;
    pair<char, pair<int, int>> pp;
    pair<int, int> p;
    while(!q.empty()){
        pp = q.front(); q.pop();
        p = pp.second;
        if(pp.first=='S' && grid[p.first][p.second]=='D')
            break;
        for (int i = 0; i < 4; ++i) {
            if(pp.first=='*'){
                if(inrange(p.first+dirr[i], p.second+dirc[i]) && grid[p.first+dirr[i]][p.second+dirc[i]]!='X' && grid[p.first+dirr[i]][p.second+dirc[i]]!='D' && grid[p.first+dirr[i]][p.second+dirc[i]]!='*'){
                    grid[p.first+dirr[i]][p.second+dirc[i]] = '*';
                    q.push({'*', {p.first+dirr[i], p.second+dirc[i]}});
                }
            }
            else{
                if(inrange(p.first+dirr[i], p.second+dirc[i]) && (grid[p.first+dirr[i]][p.second+dirc[i]]=='.' || grid[p.first+dirr[i]][p.second+dirc[i]]=='D') && dist[p.first+dirr[i]][p.second+dirc[i]]>dist[p.first][p.second]+1){
                    dist[p.first+dirr[i]][p.second+dirc[i]] = dist[p.first][p.second]+1;
                    q.push({'S', {p.first+dirr[i], p.second+dirc[i]}});
                }
            }
        }
    }
    if(dist[D.first][D.second]!=INT_MAX)
        cout<<dist[D.first][D.second]<<endl;
    else
        cout<<"KAKTUS"<<endl;
    
    return 0;
}

