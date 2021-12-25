/*
 * https://open.kattis.com/problems/reactivity
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> children(1003, vector<int>());
int numparents[1003];
vector<int> res;


int main()
{
    int n, k, a, b;
    cin>>n>>k;
    fill_n(numparents, n, 0);
    for (int i = 0; i < k; ++i) {
        cin>>a>>b;
        numparents[b]++;
        children[a].push_back(b);
    }
    int parent = 0, nex;
    for (int i = 0; i < n; ++i) {
        if(numparents[i]==0){
            parent++;
            nex = i;
        }
        if(parent == 2){
            cout<<"back to the lab"<<endl;
            return 0;
        }
    }
    res.push_back(nex);
    while(res.size()!=n){
        parent = 0;
        for (auto i : children[nex]) {
            numparents[i]--;
            if(numparents[i]==0){
                parent++;
                nex = i;
            }
            if(parent == 2){
                cout<<"back to the lab"<<endl;
                return 0;
            }
        }
        res.push_back(nex);
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<((i==n-1)?"":" ");
    }cout<<endl;
    return 0;
}

