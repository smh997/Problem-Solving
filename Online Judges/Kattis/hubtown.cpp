/*
 * https://open.kattis.com/problems/hubtown
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define double long double
const double eps = 1e-13;

const int maxn = 4e5 + 6;
const int inf = INT_MAX;

int N, M = 0;
int cx[maxn], cy[maxn];
int tx[maxn], ty[maxn];
int tc[maxn];
pair<double, int> trains[maxn];
int train_cnt;
vector<pair<int, int>> singles;
map<pair<int, int>, int> mp;
vector<int> id[maxn];
int id_cnt = 0;

bool cmp(const pair<double, int>& p1, const pair<double, int>& p2){
    return p1.first < p2.first;
}

inline double adis(double t1, double t2){
    double dis = t2 - t1;
    if(dis < 0)
        dis += 2 * acos(-1);
    return dis;
}

struct edge{
    int u, v, cap, flow = 0;
    edge(int u, int v, int cap){
        this->u = u, this->v = v, this->cap = cap;
    }
};

int n, m = 0, s, t, ptr[maxn], level[maxn];
vector<edge> edges;
vector<int> adjs[maxn];
queue<int> q;

void add_edge(int u, int v, int cap){
    edges.push_back(edge(u, v, cap));
    edges.push_back(edge(v, u, 0));
    adjs[u].push_back(m);
    adjs[v].push_back(m + 1);
    m += 2;
}

bool bfs(){
    q.push(s);
    fill_n(level, n, -1);
    level[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int eid : adjs[u]){
            int v = edges[eid].v;
            if(edges[eid].cap - edges[eid].flow == 0)
                continue;
            if(level[v] == -1)
                q.push(v), level[v] = level[u] + 1;
        }
    }
    return level[t] != -1;
}

int dfs(int u, int pushed){
    if(u == t)
        return pushed;
    for(; ptr[u] < adjs[u].size(); ptr[u]++){
        int cid = ptr[u];
        auto& e = edges[adjs[u][cid]];
        int v = e.v;
        if(e.cap - e.flow == 0 || level[v] != level[u] + 1)
            continue;
        int tr = dfs(v, min(pushed, e.cap - e.flow));
        if(tr == 0)
            continue;
        e.flow += tr;
        edges[adjs[u][cid] ^ 1].flow -= tr;
        return tr;
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(bfs()){
        fill_n(ptr, n, 0);
        while(1){
            int p = dfs(s, inf);
            if(!p)
                break;
            ans += p;
        }
    }
    return ans;
}

int main(){
    cin >> N >> train_cnt;
    for(int i = 0; i < N; i++)
        cin >> cx[i] >> cy[i];
    for(int i = 0; i < train_cnt; i++){
        int x, y, c;
        cin >> x >> y >> c;
        if(c == 0)
            continue;
        tx[M] = x, ty[M] = y, tc[M++] = c;
    }
    if(!M){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < M; i++){
        double angle = atan2(ty[i], tx[i]);
        if(angle < 0)
            angle += 2 * acos(-1);
        trains[i] = {angle, i};
    }
    sort(trains, trains + M);
    for(int i = 0; i < N; i++){
        double angle = atan2(cy[i], cx[i]);
        if(angle < 0)
            angle += 2 * acos(-1);
        int nexty = (upper_bound(trains, trains + M, make_pair(angle, 0), cmp) - trains) % M;
        int prevy = (nexty - 1 + M) % M;
        double adisp = adis(trains[prevy].first, angle), adisn = adis(angle, trains[nexty].first);
        if(fabs(adisp - adisn) < eps){
            if(prevy > nexty)
                swap(prevy, nexty);
            if(mp.find({trains[prevy].second, trains[nexty].second}) == mp.end())
                id[id_cnt].push_back(i), mp[{trains[prevy].second, trains[nexty].second}] = id_cnt++;
            else
                id[mp[{trains[prevy].second, trains[nexty].second}]].push_back(i);
        }
        else if(adisp < adisn){
            if(tc[trains[prevy].second] > 0)
                tc[trains[prevy].second]--, singles.push_back({i, trains[prevy].second});
        }
        else{
            if(tc[trains[nexty].second] > 0)
                tc[trains[nexty].second]--, singles.push_back({i, trains[nexty].second});
        }
    }
    N = id_cnt;
    for(auto x : mp){
        add_edge(x.second + 1, x.first.first + N + 1, id[x.second].size());
        add_edge(x.second + 1, x.first.second + N + 1, id[x.second].size());
    }
    for(int i = 0; i < N; i++)
        add_edge(0, i + 1, id[i].size());
    for(int i = 0; i < M; i++)
        if(tc[i] > 0)
            add_edge(N + i + 1, N + M + 1, tc[i]);
    n = N + M + 2, s = 0, t = N + M + 1;
    cout << max_flow() + singles.size() << endl;
    for(int i = 0; i < m; i += 2)
        if(edges[i].u >= 1 && edges[i].u <= N && edges[i].flow >= 1){
            int k = edges[i].flow;
            while(k--)
                cout << id[edges[i].u - 1].back() << " " << edges[i].v - N - 1 << endl, id[edges[i].u - 1].pop_back();
        }
    for(auto p : singles)
        cout << p.first << " " << p.second << endl;
}