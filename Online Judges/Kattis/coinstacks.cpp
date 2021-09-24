/*
 * https://open.kattis.com/problems/coinstacks
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int, int>> coins;
vector<pair<int, int>> ans;

int main(){
    cin >> n;
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x)
            coins.push({x, i});
    }
    while(coins.size() >= 2){
        auto p = coins.top();
        coins.pop();
        auto q = coins.top();
        coins.pop();
        ans.push_back({p.second, q.second});
        if(p.first > 1)
            coins.push({p.first - 1, p.second});
        if(q.first > 1)
            coins.push({q.first - 1, q.second});
    }
    if(coins.empty()){
        cout << "yes" << endl;
        for(auto p : ans)
            cout << p.first << " " << p.second << endl;
    }
    else
        cout << "no" << endl;
}