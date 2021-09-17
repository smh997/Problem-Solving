/*
 * https://open.kattis.com/problems/canvasline
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, p, x, ca[maxn], cb[maxn];
set<int> pegs;
vector<int> ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ca[i] >> cb[i];
    cin >> p;
    while(p--)
        cin >> x, pegs.insert(x);
    for(int i = 0; i < n; i++){
        auto lo = pegs.lower_bound(ca[i]), hi = pegs.upper_bound(cb[i]);
        int d = distance(lo, hi);
        if(d > 2){
            cout << "impossible" << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        auto lo = pegs.lower_bound(ca[i]), hi = pegs.upper_bound(cb[i]);
        int d = distance(lo, hi);
        if(d <= 1){
            int cand = cb[i] - 1;
            if(pegs.find(cand) != pegs.end())
                cand--; 
            if(pegs.find(cb[i]) == pegs.end()){
                bool ok = 1;
                if(i + 1 < n && ca[i + 1] == cb[i]){
                    auto lo2 = pegs.lower_bound(ca[i + 1]), hi2 = pegs.upper_bound(cb[i + 1]);
                    if(distance(lo2, hi2) >= 2)
                        ok = 0;
                }
                if(ok){
                    pegs.insert(cb[i]);
                    ans.push_back(cb[i]);
                }
                else{
                    pegs.insert(cand);
                    ans.push_back(cand);
                }
            }
            else{
                pegs.insert(cand);
                ans.push_back(cand);
            }
            if(!d){
                pegs.insert(cb[i] - 2);
                ans.push_back(cb[i] - 2);
            }
        }
    }
    cout << ans.size() << endl;
    for(int i : ans)
        cout << i << " ";
    cout << endl;
}