/*
 * https://open.kattis.com/problems/millionairemadness
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000100
int r, c;
int x, y;
int weight[MAX_N];
int dirr[4] = {0, -1, 0, 1};
int dirc[4] = {-1, 0, 1, 0};
int dist[MAX_N];

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<r && j<c;
}


int main()
{
    cin>>r>>c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>weight[i*c+j];
        }
    }
    
    fill_n(dist, r*c, INT_MAX);
    set<pair<int, int>> q;
    q.insert({0, 0});
    dist[0] = 0;
    pair<int, int> currp;
    int curr, currx, curry, ad, adx, ady, dis;
    while(!q.empty()){
        currp = *q.begin();
        curr = currp.second;
        currx = curr/c;
        curry = curr%c;
        q.erase(q.begin());
        for (int i = 0; i < 4; ++i) {
            adx = currx+dirr[i];ady = curry + dirc[i]; ad = adx*c+ady;
            if(inrange(adx, ady)){
                dis = max(dist[curr], weight[ad]-weight[curr]);
                if(dis<dist[ad]){
                    dist[ad] = dis;
                    q.insert({dis, ad});
                }
            }
        }
    }
    cout<<dist[r*c-1]<<endl;
    
    return 0;
}
