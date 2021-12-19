/*
 * https://open.kattis.com/problems/increasingsubsequence
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> sequence;
vector<int> lis;
vector<int> lis_index;
vector<int> trace;
vector<int> path;

void clis(){
    trace.resize(sequence.size(), -1);
    for(int i = 0; i < sequence.size(); i++){
        int num = sequence[i];
        int ptr = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
        if(ptr == lis.size()){
            lis.push_back(num);
            lis_index.push_back(i);
        }
        else {
            lis[ptr] = num;
            lis_index[ptr] = i;
        }
        if(ptr > 0)
            trace[i] = lis_index[ptr-1];
    }
    cout << lis.size() << " ";
    int it = lis_index[lis.size()-1];
    while(it != -1){
        path.push_back(sequence[it]);
        it = trace[it];
    }
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ((i == 0)? "\n" : " ");
}

int main()
{
    int n ,a;
    while (cin >> n && n) {
        sequence.clear();
        lis.clear();
        lis_index.clear();
        trace.clear();
        path.clear();
        for (int i = 0; i < n; ++i)
            cin >> a, sequence.push_back(a);
        clis();
    }
    return 0;
}

