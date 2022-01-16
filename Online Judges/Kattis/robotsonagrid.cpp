/*
 * https://open.kattis.com/problems/robotsonagrid
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
long long int dp[1003][1003];
char grid[1003][1003];
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {1, 0, -1, 0};

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<n && j<n;
}

int main()
{
    cin>>n;
    bool vis[n][n];dp[0][0]=1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>grid[i][j];
            vis[i][j]=false;
            if(i==0 && j==0)continue;
            if(grid[i][j]=='#')
                continue;
            dp[i][j] = (((i>=1 && grid[i-1][j]=='.')?dp[i-1][j]:0LL)%INT_MAX + ((j>=1 && grid[i][j-1]=='.')?dp[i][j-1]:0LL)%INT_MAX)%INT_MAX;
        }
    }
    if(dp[n-1][n-1]!=0)
        cout<<dp[n-1][n-1]<<endl;
    else{
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0]= true;
        pair<int, int> to;
        while(!q.empty()){
            to = q.front(); q.pop();
            int r,c;r=to.first;c=to.second;
            if(r==n-1 && c==n-1)
                break;
            for (int i = 0; i < 4; ++i) {
                if(inrange(r+dirr[i], c+dirc[i]) && grid[r+dirr[i]][c+dirc[i]] != '#' && !vis[r+dirr[i]][c+dirc[i]])
                    q.push({r+dirr[i], c+dirc[i]}), vis[r+dirr[i]][c+dirc[i]]=true;
            }
        }
        if(vis[n-1][n-1])
            cout<<"THE GAME IS A LIE"<<endl;
        else
            cout<<"INCONCEIVABLE"<<endl;
    }
    return 0;
}

