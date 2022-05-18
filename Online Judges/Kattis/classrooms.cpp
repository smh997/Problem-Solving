/*
 * https://open.kattis.com/problems/classrooms
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, k, res = 0;
multiset<int> s;
pair<int, int> activity[200003];

int main(){
    cin >> n >> k;
    
    for (int i = 0; i < n; i++){
        cin >> activity[i].second >> activity[i].first;
        if (i < k)
            s.insert(0);
    }
    
    sort(activity, activity + n);
    
    for (int i = 0; i < n; i++){
        auto it = s.lower_bound(activity[i].second);
        if (it == s.begin())
            continue;
        s.erase(prev(it)); 
        s.insert(activity[i].first);
        res++;
    }
    
    cout << res << endl;

    return 0;
}