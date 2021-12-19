/*
 * https://open.kattis.com/problems/gold
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool visited[2503];
char grid[53][53];
int w, h, res=0;
int dirr[4] = {1,0,-1,0};
int dirc[4] = {0,1,0,-1};              


bool inrange(int r, int c){
    return r>=0 && r<h && c<w && c>=0;
}

bool danger(int u){
    int r=u/w, c=u%w;
    for (int i = 0; i < 4; ++i) {
        int newr = r+dirr[i], newc=c+dirc[i];
        if(inrange(newr, newc) && grid[newr][newc]=='T')
            return true;
    }
    return false;
}

void dfs(int u){
    int r = u/w, c = u%w;
    visited[u] = true;
    if(grid[r][c]=='G')
        res++;
    if(danger(u))
        return;
    for (int i = 0; i < 4; ++i) {
        int newr = r+dirr[i], newc=c+dirc[i], newv = newr*w+newc;
        if(inrange(newr, newc) && !visited[newv] && grid[newr][newc]!='T' && grid[newr][newc]!='#'){
            dfs(newv);
        }
    }
}

int main()
{
    int p;
    cin>>w>>h;
    fill_n(visited, 2503, false);
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j){
            cin>>grid[i][j];
            if(grid[i][j]=='P')
                p = i*w+j;
        }
    dfs(p);
    cout<<res<<endl;
    return 0;
}

