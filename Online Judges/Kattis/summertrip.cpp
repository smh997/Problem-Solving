/*
 * https://open.kattis.com/problems/summertrip
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

vector<int> v[29];

int main(){
    string s;
    cin >> s;
    int size = s.size();
    for(int i = 0; i < size; i++)
        v[s[i] - 'a'].push_back(i);
    
    num ans = 0;
    for(int i = 0; i < size; i++){
        auto it = upper_bound(v[s[i] - 'a'].begin(), v[s[i] - 'a'].end(), i);
        int e;
        if(it == v[s[i] - 'a'].end())
            e = -1;
        else 
            e = *it;
        for(int j = 0; j < 26; j++){
            if(j == s[i] - 'a' || v[j].empty())
                continue;
            auto it2 = upper_bound(v[j].begin(), v[j].end(), i);
            if(it2 != v[j].end() && e == -1)
                ans++;
            else if(it2 != v[j].end()){
                auto it3 = lower_bound(v[j].begin(), v[j].end(), e);
                if(it2 != it3)
                    ans++;
            }
        }
    }

    cout << ans << endl;
}