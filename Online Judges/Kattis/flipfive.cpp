/*
 * https://open.kattis.com/problems/flipfive
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int p;
string target = ".........";
map<string, long long int> dist;
vector<int> adj[10] = {{1, 3}, {0, 2, 4}, {1, 5}
                       ,{0, 4, 6}, {1, 3, 5, 7},{2, 4, 8}
                       ,{3, 7}, {4 , 6, 8}, {5, 7}};


long long int bfs(string s){
    dist.clear();
    dist[s] = 0;
    queue<string> q;
    q.push(s);
    string tp, news;
    while(!q.empty()){
        tp = q.front();
        q.pop();
        for (int i = 0; i < 9; ++i) {
            news = tp;
            news[i] = ((news[i] == '*')?'.':'*');
            for (auto v: adj[i]) {
                news[v] = ((news[v] == '*')?'.':'*');
            }
//            cerr << i << " " << news << endl;
            if(news != s && dist[news] == 0){
                dist[news] = dist[tp] + 1;
                if(news == target){
                    return dist[target];
                }
                q.push(news);
            }
        }
    }
    return dist[target];
}

int main()
{
    cin >> p;
    string s, st;
    while(p--){
        cin >> s;
        st = s;
        for (int i = 1; i < 3; ++i) {
            cin >> s;
            st += s;
        }
        cout << bfs(st) << endl;
    }
    return 0;
}

