/*
 * https://open.kattis.com/problems/mazemakers
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int R, C;
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {-1, 0, 1, 0};
vector<vector<int>> adj;
int exts[2], ex;
bool multi, unrech;
map<char, int> mp = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
                     {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
                     {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11},
                     {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
bool inrange(int i, int j){
    return i >= 0 && i < R && j >= 0 && j < C;
}

bool visited[2503];
int parent[2503];

void dfs(int u){
    visited[u] = true;
    for (auto v : adj[u]) {
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
        else if(v != parent[u])
            multi = true;
    }
}

int main()
{
    char ch;
    while(cin>>R>>C && R){
        ex = 0;
        unrech = multi = false;
        adj.clear();
        adj.resize(R*C+3);
        fill_n(visited, R*C+3, false);
        fill_n(parent, R*C+3, -1);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin>>ch;
                for(int k = 0; k < 4; k++){
                    if(!(mp[ch] & (1<<k))){
                        if(inrange(i+dirr[k], j+dirc[k])){
                            adj[i*C+j].push_back((i+dirr[k])*C+(j+dirc[k]));
                        }
                        else{
                            exts[ex] = i*C+j;
                            ex++;
                        }
                    }
                }
            }
        }
        dfs(exts[0]);
        if(!visited[exts[1]]){
            cout << "NO SOLUTION" <<endl;
            continue;
        }
        else{
            for (int i = 0; i < R*C; ++i) {
                if(!visited[i]){
                    unrech = true;
                }
            }
        }
        if(unrech){
            cout << "UNREACHABLE CELL" << endl;
        }
        else if(multi){
            cout << "MULTIPLE PATHS" << endl;
        }
        else{
            cout << "MAZE OK" << endl;
        }
    }
    return 0;
}

