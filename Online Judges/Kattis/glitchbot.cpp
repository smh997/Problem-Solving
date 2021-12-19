/*
 * https://open.kattis.com/problems/glitchbot
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int adjX[4]{0, 1, 0, -1};
int adjY[4]{1, 0, -1, 0};

int x, y, n;
string act[53];

pair<int, int> go(){
    int x = 0, y = 0, k = 0;
    for(int i = 0; i < n; i++){
        if(act[i] == "Right")
            k = (k + 1) % 4;
        else if(act[i] == "Left")
            k = (k + 3) % 4;
        else
            x += adjX[k], y += adjY[k];
    }
    return {x, y};
}

int main(){
    cin >> x >> y >> n;
    for(int i = 0; i < n; i++)
        cin >> act[i];
    string rep[3]{"Right", "Left", "Forward"};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++)
            if(act[i] != rep[j]){
                string save = act[i];
                act[i] = rep[j];
                pair<int, int> ans = go();
                if(ans.first == x && ans.second == y){
                    cout << i + 1 << " " << act[i] << endl;
                    return 0;
                }
                act[i] = save; 
            }
    }
}