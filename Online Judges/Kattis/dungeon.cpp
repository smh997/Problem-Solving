/*
 * https://open.kattis.com/problems/dungeon
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 33

char grid[MAX_N][MAX_N][MAX_N];
int dist[MAX_N][MAX_N][MAX_N];
int L, R, C;
pair<int, pair<int, int>> S, E;
int dirl[6] = {0, 0, 0, 0, 1, -1};
int dirr[6] = {0, 1, 0, -1, 0, 0};
int dirc[6] = {1, 0, -1, 0, 0, 0};
bool inrange(int i, int j, int k){
    return i>=0 && j>=0 && k>=0 && i<L && j<R && k<C;
}

int main()
{
    while(cin>>L>>R>>C){
        if(!L && !R && !C)
            break;
        for (int i = 0; i < L; ++i)
            for (int j = 0; j < R; ++j)
                for (int k = 0; k < C; ++k) {
                    dist[i][j][k] = INT_MAX;
                    cin>>grid[i][j][k];
                    if(grid[i][j][k]=='S')
                        S.first = i, S.second.first = j, S.second.second=k;
                    else if(grid[i][j][k]=='E')
                        E.first = i, E.second.first = j, E.second.second=k;
                }
        dist[S.first][S.second.first][S.second.second] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({S.first,{S.second.first, S.second.second}});
        while(!q.empty()){
            S = q.front();q.pop();
            if(S.first==E.first && S.second.first==E.second.first && S.second.second==E.second.second)
                break;
            for (int i = 0; i < 6; ++i) {
                if(inrange(S.first+dirl[i], S.second.first+dirr[i], S.second.second+dirc[i]) && grid[S.first+dirl[i]][S.second.first+dirr[i]][S.second.second+dirc[i]] != '#' && dist[S.first+dirl[i]][S.second.first+dirr[i]][S.second.second+dirc[i]]>dist[S.first][S.second.first][S.second.second]+1){
                    dist[S.first+dirl[i]][S.second.first+dirr[i]][S.second.second+dirc[i]] = dist[S.first][S.second.first][S.second.second]+1;
                    q.push({S.first+dirl[i], {S.second.first+dirr[i], S.second.second+dirc[i]}});
                }
            }
        }
        if(dist[E.first][E.second.first][E.second.second]!=INT_MAX)
            printf("Escaped in %d minute(s).\n", dist[E.first][E.second.first][E.second.second]);
        else
            cout<<"Trapped!"<<endl;
    }
    return 0;
}

