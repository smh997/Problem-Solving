/*
 * https://open.kattis.com/problems/baas
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 403
int dist[MAX_N];
vector<int> adj[MAX_N];
int n, m, a;
int weights[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


int cdp(int i){
    if(dist[i]!=INT_MAX)
        return dist[i];
    for(auto v: adj[i]){
        dist[i] = min(dist[i], cdp(v)+weights[v]);
    }
    return dist[i];
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>weights[i];
        weights[i]*=-1;
    }
    for (int i = 0; i < n; ++i) {
        cin>>m;
        for (int j = 0; j < m; ++j) {
            cin>>a;a--;
            adj[i].push_back(a);
        }
    }
    adj[n].push_back(n-1);
    int tmp;
    pair<int, int> p;
    int mi=INT_MAX;
    for (int i = 0; i < n; ++i) {
        tmp = weights[i];
        weights[i] = 0;
        fill_n(dist, n+1, INT_MAX);
        dist[0] = 0;
        mi = min(-cdp(n), mi);
//        cout<<dist[0]<<" "<<dist[1]<<" "<<dist[2]<<endl;
        weights[i] = tmp;
    }
    cout<<mi<<endl;
    return 0;
}

