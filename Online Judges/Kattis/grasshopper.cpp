/*
 * https://open.kattis.com/problems/grasshopper
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int INF = INT_MAX;

bool inrange(int w, int h, int x, int y) {
    return (x >= 0 && y >= 0 && x < w && y < h);
}

int main() {
    int x, y, startx, starty, endx, endy;
    vector<vector<int>> v;
    vector<pair<int, int>> modifiers;
    modifiers.push_back({-2, -1});
    modifiers.push_back({-1, -2});
    modifiers.push_back({+2, -1});
    modifiers.push_back({+1, -2});
    modifiers.push_back({-2, +1});
    modifiers.push_back({-1, +2});
    modifiers.push_back({+2, +1});
    modifiers.push_back({+1, +2});
    
    while(cin >> x && cin >> y && cin >> startx && cin >> starty && cin >> endx && cin >> endy) {
        v.clear();
        v.resize(x, vector<int>(y, INF));
        v[startx-1][starty-1] = 0;
        queue<pair<int, int>> q;
        q.push({startx-1, starty-1});

        while(!q.empty()) {
            int currx = q.front().first;
            int curry = q.front().second;
            int currval = v[currx][curry];
            q.pop();
            for(auto m : modifiers) {
                if(inrange(x, y, currx+m.first, curry+m.second) && v[currx+m.first][curry+m.second] == INF) {
                    v[currx+m.first][curry+m.second] = currval+1;
                    q.push({currx+m.first, curry+m.second});
                }
            }
        }

        if(v[endx-1][endy-1] == INF) {
            cout << "impossible" << endl;
        }
        else {
            cout << v[endx-1][endy-1] << endl;
        }
    }
}
