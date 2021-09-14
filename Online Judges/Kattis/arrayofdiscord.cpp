/*
 * https://open.kattis.com/problems/arrayofdiscord
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
string a[103];
char digits[10]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<pair<num, num>> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        v.clear();
        for(int j = 0; j < i; j++)
            v.insert({stoll(a[j]), j});
        for(int j = i + 1; j < n; j++)
            v.insert({stoll(a[j]), j});
        for(int k = 0; k < a[i].size(); k++)
            for(char d : digits){
                if(d == '0' && k == 0 && a[i].size() > 1)
                    continue;
                if(d != a[i][k]){
                    string t = a[i].substr(0, k) + d + a[i].substr(k + 1);
                    v.insert({stoll(t), i});
                    if((*next(v.begin(), i)).second != i){
                        set<pair<num, num>> ans;
                        for(auto p : v)
                            ans.insert({p.second, p.first});
                        for(auto p : ans)
                            cout << p.second << " ";
                        cout <<endl;
                        return 0;
                    }
                    v.erase({stoll(t), i});
                }
            }
    }
    cout << "impossible" << endl;
}