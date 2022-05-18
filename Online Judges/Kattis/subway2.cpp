/*
 * https://open.kattis.com/problems/subway2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define dnum long double

dnum calc_dist(num si, num sj, num ti, num tj){
    return (dnum)sqrt((si - ti) * (si - ti) + (sj - tj) * (sj - tj));
}

dnum dist[203];
vector<pair<num, num>> nodes;
map<pair<num, num>, num> id;
pair<num, num> home, school, stop, prestop;
num prestop_i = -1, cur, stop_i = 0;
dnum dis;
vector<pair<num, dnum>> adj[203];
priority_queue<pair<dnum, num>, vector<pair<dnum, num>>, greater<pair<dnum, num>>> pq;


int main(){
    cin >> home.first >> home.second >> school.first >> school.second;
    nodes.push_back(home); nodes.push_back(school);
    id[home] = 0; id[school] = 1;
    dist[1] = LLONG_MAX;

    while(cin >> stop.first){
        cin >> stop.second;
        
        if (stop.first == -1){
            prestop_i = -1;
            continue;
        }
        
        if (prestop_i == -1){
            if (id.find(stop) == id.end()){
                prestop_i = nodes.size();
                id[stop] = prestop_i;
                nodes.push_back(stop);
                dist[prestop_i] = LLONG_MAX;
            }
            else
                prestop_i = id[stop];
            prestop = stop;
            continue;
        }
        
        if (id.find(stop) == id.end()){
            stop_i = nodes.size();
            id[stop] = stop_i;
            nodes.push_back(stop);
            dist[stop_i] = LLONG_MAX;
        }
        else
            stop_i = id[stop];
        
        dis = calc_dist(stop.first, stop.second, prestop.first, prestop.second);
        adj[prestop_i].push_back({stop_i, dis / 4});
        adj[stop_i].push_back({prestop_i, dis / 4});
        
        prestop_i = stop_i;
        prestop = stop;
    }
    for (int i = 0; i < nodes.size(); i++){
        for (int j = 0; j < nodes.size(); j++){
            if (i == j)
                continue;
                
            dis = calc_dist(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second);
            adj[i].push_back({j, dis});
            adj[j].push_back({i, dis});
        }
    }

    pq.push({(dnum)0, 0ll});
    pair<dnum, num> tp;
    while (!pq.empty()){
        tp = pq.top(); pq.pop();
        cur = tp.second;
        if (cur == 1)
            break;
        if (tp.first > dist[cur])
            continue;
        for (auto nxt: adj[cur]){
            if (dist[nxt.first] > dist[cur] + nxt.second){
                dist[nxt.first] = dist[cur] + nxt.second;
                pq.push({dist[nxt.first], nxt.first});
            }
        }
    }
    
    cout << round(dist[1] * 6 / 1000) << endl;
    
    return 0;
}