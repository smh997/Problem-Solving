/*
 * https://open.kattis.com/problems/hidingplaces
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;


int dist[9][9];
vector<pair<int, int>> res;int mx = 0;
int n, a, b;string aa;
queue<pair<int, int>> q;

int dirx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int diry[8] = {1, -1, -2, -2, -1, 1, 2, 2};

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
}

bool inrange(int i, int j){
    return i> 0 && j>0 && i<9 && j<9;
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>aa;
        for (int j = 1; j <= 8; ++j)
            for (int k = 1; k <= 8; ++k)
                dist[j][k]=INT_MAX;
        res.clear();mx=0;
        b = aa[0]-'a'; a = aa[1]-'0';
        q.push({a, 8-b}); dist[a][8-b]=0;
        pair<int, int> p;
        while(!q.empty()){
            p = q.front(); q.pop();
            a = p.first; b = p.second;
//            cout<<a<<" "<<b<<endl;
            for (int j = 0; j < 8; ++j) {
                if(inrange(a+diry[j], b+dirx[j]) && dist[a][b] + 1 < dist[a+diry[j]][b+dirx[j]]){
                    dist[a+diry[j]][b+dirx[j]] = dist[a][b] + 1;
                    q.push({a+diry[j], b+dirx[j]});
                    if(mx<dist[a+diry[j]][b+dirx[j]]){
                        mx = dist[a+diry[j]][b+dirx[j]];
                        res.clear();
                        res.push_back({a+diry[j], b+dirx[j]});
                    }
                    else if(mx==dist[a+diry[j]][b+dirx[j]]){
                        res.push_back({a+diry[j], b+dirx[j]});
                    }
                }
            }
        }
        cout<<mx<<" ";
        sort(res.begin(), res.end(), greater<pair<int, int>>());
        for (auto v : res) {
            cout<<(char)('a'+8-v.second)<<v.first<<" ";
        }
        cout<<endl;
    }
    return 0;
}

