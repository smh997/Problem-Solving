/*
 * https://open.kattis.com/problems/cool1
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

char grid[203][203];
int n;
string ins;
pair<int, int> pos;
long long int v [203][203][203];
map<char, pair<int, int>> dirs = {
    {'>', {0, 1}},
    {'v', {1, 0}},
    {'<', {0, -1}},
    {'^', {-1, 0}}
};

bool same(string s, int k) {
    string samp = s.substr(0, k);
    for(int i = 0; i < s.size(); i+=k) {
        if(samp != s.substr(i, k)){
            return false;
        }
    }
    return true;
}

string compress(string s) {
    for(int i = s.size(); i >= 1; i--) {
        if(s.size() % i == 0) {
            if(same(s, s.size()/i)) {
                return s.substr(0, s.size()/i);
            }
        }
    }
    return s;
}

int main()
{
    cin >> n;
    cin >> ins;
    ins = compress(ins);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'R'){
                pos = {i, j};
            }
        }
    }
    pair<int, int> dir;
    int siz = ins.size();
    int cnt = 0;
    for (int i = 0; i < 203; ++i) {
        for (int j = 0; j < 203; ++j) {
            for (int k = 0; k < 203; ++k) {
                v[i][j][k] = INT_MAX;
            }
        }
    }
    int k = 0;
    deque<pair<int, int>> x;
    while(v[pos.first][pos.second][k%siz] == INT_MAX){
        v[pos.first][pos.second][k%siz] = k;
        dir = dirs[ins[k%siz]];
        if(grid[pos.first+dir.first][pos.second+dir.second] != '#'){
            grid[pos.first][pos.second] = '.';
            grid[pos.first+dir.first][pos.second+dir.second] = 'R';
            x.push_back({k, ins[k%siz]});
            pos = {pos.first+dir.first, pos.second+dir.second};
        }
        k++;
    }
    cnt = v[pos.first][pos.second][k%siz];
    while(!x.empty() && x.front().first < cnt){
        x.pop_front();
    }
    string res = "";
    for (auto item : x) {
        res += item.second;
    }
    res = compress(res);
    if(res.size() == 0){
        cout << 1 << endl;
    }
    else{
        cout << res.size() << endl;
    }
    return 0;
}

