/*
 * https://open.kattis.com/problems/watersheds
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int T, H, W, al[103][103];
char basin, dp[103][103];
pair<int, int> directions[4] = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0}
};

bool inrange (int h, int w){
    return h < H && h >= 0 && w < W && w >= 0;
}

char cdp(int h, int w){
    if (dp[h][w] != 'A')
        return dp[h][w];

    vector<pair<int, int>> candids;
    int lowest_al = INT_MAX;

    for (auto dir: directions){
        
        int nh = h + dir.first, nw = w + dir.second;

        if (inrange(nh, nw) && al[nh][nw] < al[h][w]){
            if (lowest_al > al[nh][nw]){
                lowest_al = al[nh][nw];
                candids.clear();
                candids.push_back({nh, nw});
            }
            else if (lowest_al == al[nh][nw]){
                candids.push_back({nh, nw});
            }
        }
    }

    if (candids.size()){
        return dp[h][w] = cdp(candids[0].first, candids[0].second);
    }

    return dp[h][w] = basin++;
}

int main(){
    
    cin >> T;
    
    for (int i = 1; i <= T; i++){
        
        cin >> H >> W;
        
        for (int h = 0; h < H; h++)
            for (int w = 0; w < W; w++)
                cin >> al[h][w], dp[h][w] = 'A';

        basin = 'a';
        
        cout << "Case #" << i << ":" << endl;
        
        for (int h = 0; h < H; h++)
            for (int w = 0; w < W; w++)
                cout << cdp(h, w) << ((w == W - 1) ? '\n' : ' ');
    }
    
    return 0;
}