/*
 * https://open.kattis.com/problems/fire3
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

char grid[1003][1003];
int w, h;
int dist[1003][1003];
int dist2[1003][1003];
int dirw[4] = {-1, 0, 1, 0};
int dirh[4] = {0, -1, 0, 1};
vector<pair<int, int>> fires;
bool inrange(int i, int j){
    return i>=0 && j>=0 && i<h && j<w;
}

int main()
{
    pair<int, int> start;
    pair<char, pair<int, int>> top;
    cin>>h>>w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j){
            cin>>grid[i][j];
            if(grid[i][j] == 'J')
                start = {i, j}, grid[i][j]='.';
            else if(grid[i][j] == 'F')
                fires.push_back({i, j});
            dist[i][j] = INT_MAX;
            dist2[i][j] = INT_MAX;
        }
    
    queue<pair<char, pair<int, int>>> q;
   
    for (int i = 0; i < fires.size(); ++i) {
        dist2[fires[i].first][fires[i].second] = 0;
        q.push({'F', fires[i]});
    }
    q.push({'.', start});
    dist[start.first][start.second] = 0;
    bool flag = false;
    int res;
    while(!q.empty()){
        top = q.front(); q.pop();
        start = top.second;
        for (int i = 0; i < 4; ++i) {
            if(top.first == '.'){
                if(inrange(start.first+dirh[i], start.second+dirw[i])){
                    if(grid[start.first+dirh[i]][start.second+dirw[i]] == '.' && dist[start.first][start.second]+1< dist[start.first+dirh[i]][start.second+dirw[i]]){
                        dist[start.first+dirh[i]][start.second+dirw[i]] = dist[start.first][start.second] + 1;
                        q.push({'.', {start.first+dirh[i], start.second+dirw[i]}});
                    }
                }
                else{
                    flag = true;
                    res = dist[start.first][start.second];
                    break;
                }
            }
            else{
                if(inrange(start.first+dirh[i], start.second+dirw[i]) && grid[start.first+dirh[i]][start.second+dirw[i]] != '#' && dist2[start.first][start.second]+1< dist2[start.first+dirh[i]][start.second+dirw[i]]){
                    dist2[start.first+dirh[i]][start.second+dirw[i]] = dist2[start.first][start.second] + 1;
                    q.push({'F', {start.first+dirh[i], start.second+dirw[i]}});
                    grid[start.first+dirh[i]][start.second+dirw[i]] = 'F';
                }
            }
            
        }
        if(flag)
            break;
    }
    if(flag){
        cout<<res+1<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
