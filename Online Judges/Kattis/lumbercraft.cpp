/*
 * https://open.kattis.com/problems/lumbercraft
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, h, w;
char grid[53][53];
vector<pair<int, int>> trees;
vector<pair<pair<pair<char, double>, pair<int, int>>, int>> players;
map<int, vector<pair<int, int>>> pt;
int curp;
bool cmp(pair<int, int> t1, pair<int, int> t2){
    double dist1 = hypot(players[curp].first.second.first - t1.first, players[curp].first.second.second - t1.second);
    double dist2 = hypot(players[curp].first.second.first - t2.first, players[curp].first.second.second - t2.second);
//    double dist1 = abs(players[curp].first.second.first - t1.first) + abs(players[curp].first.second.second - t1.second);
//    double dist2 = abs(players[curp].first.second.first - t2.first) + abs(players[curp].first.second.second - t2.second);
    if(dist1 < dist2){
        return true;
    }
    if(dist1 > dist2){
        return false;
    }
    if(t1.second == t2.second){
        return t1.first > t2.first;
    }
    return t1.second > t2.second;
}

int main()
{
    while(cin >> n >> h >> w && n){
        trees.clear();
        players.clear();
        pt.clear();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
                if(grid[i][j] == '!'){
                    trees.push_back({i, j});
                }
                else if(grid[i][j] != '.'){
                    players.push_back({{{grid[i][j], 0}, {i, j}}, 0});
                }
            }
        }
        for (int pl = 0; pl < players.size(); ++pl) {
            for (int tr = 0; tr < trees.size(); ++tr) {
                pt[pl].push_back(trees[tr]);
            }
            curp = pl;
            sort(pt[pl].begin(), pt[pl].end(), cmp);
        }
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, vector<int>> targetTrees;
            for (int pl = 0; pl < players.size(); ++pl) {
                int curt = players[pl].second;
                for (int j = curt; j < trees.size(); ++j) {
                    pair<int, int> candid = pt[pl][j];
                    if(grid[candid.first][candid.second] == '!'){
                        if(targetTrees.find(candid) == targetTrees.end()){
                            vector<int> v;
                            targetTrees[candid] = v;
                        }
                        targetTrees[candid].push_back(pl);
                        curt = j+1;
                        break;
                    }
                }
            }
            for(auto tree : targetTrees){
                double score = 1.0 / tree.second.size();
                grid[tree.first.first][tree.first.second] = '.';
                for(auto pp : tree.second){
                    players[pp].first.first.second += score;
//                    cerr << i << " " << players[pp].first.first.first << " " << tree.first.first << " " << tree.first.second << " " << score << endl;
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        sort(players.begin(), players.end());
        for(auto pp: players){
            auto ans = pp.first.first;
            cout << ans.first << " " << fixed << setprecision(3) << ans.second << endl;
        }
    }
    return 0;
}

