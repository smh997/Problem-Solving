/*
 * https://open.kattis.com/problems/kitchen
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

# define volume array<int, 5>

priority_queue<pair<int, volume>, vector<pair<int, volume>>, greater<pair<int, volume>>> pq;
int n, v, c[6], val;
map<volume, int> dist;
volume vols;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    cin >> v;
    vols[0] = c[0];
    dist[vols] = 0;
    pq.push({0, vols});
    pair<int, volume> tp;
    while(!pq.empty()){
        tp = pq.top();
        pq.pop();
        val = tp.first;
        vols = tp.second;
        if (val > dist[vols]){
            continue;
        }
        if (vols[0] == v){
            break;
        }
        for (int i = 0; i < n; ++i) {
            if (vols[i])
                for (int j = 0; j < n; ++j) {
                    if (i == j || vols[j] == c[j])
                        continue;
                    int pour = min(c[j] - vols[j], vols[i]);
                    volume newv = vols;
                    newv[i] -= pour;
                    newv[j] += pour;
                    if (dist.find(newv) == dist.end() || dist[newv] > dist[vols] + pour){
                        dist[newv] = dist[vols] + pour;
                        pq.push({dist[newv], newv});
                    }
                }
        }
    }
    if (vols[0] == v)
        cout << dist[vols] << endl;
    else
        cout << "impossible" << endl;
    return 0;
}

