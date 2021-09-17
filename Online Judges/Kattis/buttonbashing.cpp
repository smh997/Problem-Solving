/*
 * https://open.kattis.com/problems/buttonbashing
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> m;
queue<int> q;
int dist[3603];
bool visited[3603];

int main()
{
    int t, n, target, a;
    cin>>t;
    while(t--){
        cin>>n>>target;
        p.clear();
        m.clear();
        fill_n(dist, 3603, INT_MAX);
        fill_n(visited, 3603, false);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            cin>>a;
            p.push_back(a);
        }
        dist[0] = 0;
        q.push(0);
        bool res = false;
        int near = INT_MAX, steps = 0, morre=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            if(curr == target){
                cout<<dist[curr]<<" "<<0<<endl;
                res = true;
                break;
            }
            if(curr > target){
                if(curr<near)
                    near = curr, steps = dist[curr], morre = curr - target;
            }
                for (int i = 0; i < p.size(); ++i){
                    int v;
                    if(p[i]<0)
                        v = max(0, curr+p[i]);
                    else
                        v = min(3600, curr + p[i]);
                    if(!visited[v] && dist[curr] + 1 < dist[v])
                        dist[v] = dist[curr] + 1, q.push(v);
                }

        }
        if(!res)
            cout<<steps<<" "<<morre<<endl;
        
    }
    return 0;
}