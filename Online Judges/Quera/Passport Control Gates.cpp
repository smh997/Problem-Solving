/*
 * https://quera.org/problemset/82385/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100003
priority_queue<pair<int, int>> pq;
vector<int> Q[MAX_N];
int Qit[MAX_N];
int n, q, k, a;
vector<int> ans;
int main()
{
    cin >> q >> n;
    for (int i = 0; i < q; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j){
            cin >> a;
            Q[i].push_back(a);
        }
    }
    bool flag = false;
    for (int i = 0; i < q; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j){
            cin >> a;
            if(flag)
                continue;
            if(Q[i][j] == a){
                Qit[i]++;
            }
            else{
                cout << "Impossible" << endl;
                flag = true;
            }
        }
    }
    if(flag)
        return 0;
    for (int i = 0; i < q; ++i) {
        if(Q[i].size() > Qit[i]){
            pq.push({*Q[i].rbegin(), i});
        }
    }
    pair<int, int> ii;
    int myq;
    while(!pq.empty()){
        ii = pq.top();
        pq.pop();
        myq = ii.second;
        if(myq == 0){
            ans.push_back(myq);
            Q[myq].pop_back();
            if(Q[myq].size() > Qit[myq]){
                pq.push({*Q[myq].rbegin(), myq});
            }
        }
        else if(myq == q){
            ans.push_back(myq+1);
            Q[myq].pop_back();
            if(Q[myq].size() > Qit[myq]){
                pq.push({*Q[myq].rbegin(), myq});
            }
        }
        else{
            if(Q[myq-1].size() == 0 || *Q[myq].rbegin() > *Q[myq-1].rbegin()){
                ans.push_back(myq);
                Q[myq].pop_back();
                if(Q[myq].size() > Qit[myq]){
                    pq.push({*Q[myq].rbegin(), myq});
                }
            }
            else if(Q[myq+1].size() == 0 || *Q[myq].rbegin() > *Q[myq+1].rbegin()){
                ans.push_back(myq+1);
                Q[myq].pop_back();
                if(Q[myq].size() > Qit[myq]){
                    pq.push({*Q[myq].rbegin(), myq});
                }
            }
            else{
                cout << "Impossible" << endl;
                flag = true;
                break;
            }
        }
    }
    if(flag)
        return 0;
    cout << ans.size() << endl;
    for (auto v: ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
