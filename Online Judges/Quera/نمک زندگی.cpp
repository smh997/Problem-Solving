/*
 * https://quera.org/problemset/20258/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
int t[100003];

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v;
    vector<pair<int, int> > v2;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b - a, a));
        v2.push_back(make_pair(a, b));
    }
    for(int i = 1; i <= 100000; i++)
        t[i] = 0;
    sort(v.begin(), v.end());
    bool set = false;
    for(vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++){
        int l = it->second;
        int r = it->first + it->second;
        set = false;
        for(int i = l; i <= r; i++){
            if(t[i] < k){
                t[i]++;
                set = true;
                break;
            }
        }
        if(!set) break;
   }

    bool set2 = false;
    for(vector<pair<int, int> >::iterator it = v2.begin(); it != v2.end(); it++){
        int l = it->first;
        int r = it->second;
        set2 = false;
        for(int i = l; i <= r; i++){
            if(t[i] < k){
                t[i]++;
                set2 = true;
                break;
            }
        }
        if(!set2) 
            break;
    }
    if(set || set2)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}