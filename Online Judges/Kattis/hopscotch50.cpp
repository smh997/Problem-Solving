/*
 * https://open.kattis.com/problems/hopscotch50
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, k, x, r, c;
num dist[53][53];
vector<pair<int, int>> numbers[53 * 53];
int mat[53][53];
queue<pair<int, int>> q;

num dis(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            numbers[mat[i][j]].push_back({i, j});
            dist[i][j] = INT_MAX;
        }
    }
    for (auto p : numbers[1]){
        dist[p.first][p.second] = 0;
        q.push(p);
    }
    pair<int, int> fr;
    num ans = -1;
    while (!q.empty()){
        fr = q.front(); q.pop();
        for (auto adj : numbers[mat[fr.first][fr.second]+1]){
            num d = dis(fr, adj);
            if (dist[adj.first][adj.second] > dist[fr.first][fr.second] + d){
                dist[adj.first][adj.second] = dist[fr.first][fr.second] + d;
                q.push(adj);
            }
        }
    }
    num res = INT_MAX;
    for(auto p: numbers[k])
        res = min(dist[p.first][p.second], res);
    if (res != INT_MAX)
        ans = res;
    cout << ans << endl;
}