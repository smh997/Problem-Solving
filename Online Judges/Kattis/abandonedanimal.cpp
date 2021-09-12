
/*
 * https://open.kattis.com/problems/abandonedanimal
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;
int n, k, m, lis[maxn], sh, c = 0, mnit, mxit;
string item;
unordered_map<string, int> mp;
vector<int> asc, dsc, shops[maxn];

int main()
{
    cin >> n >> k;
    mnit = 0, mxit = n;
    for (int i = 0; i < k; ++i) {
        cin >> sh >> item;
        if(mp.find(item) == mp.end()){
            mp[item] = c++;
        }
        shops[mp[item]].push_back(sh);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> item;
        lis[i] = mp[item];
    }
    for (int i = 0; i < c; ++i) {
        sort(shops[i].begin(), shops[i].end());
    }
    for (int i = 0; i < m; ++i) {
        auto it = lower_bound(shops[lis[i]].begin(), shops[lis[i]].end(), mnit);
        if(it == shops[lis[i]].end()){
            cout << "impossible" << endl;
            return 0;
        }
        asc.push_back(*it);
        mnit = *it;
    }
    for (int i = m-1; i >= 0; --i) {
        auto it = prev(upper_bound(shops[lis[i]].begin(), shops[lis[i]].end(), mxit));
        mxit = *it;
        dsc.push_back(*it);
    }
    for (int i = 0; i < m; ++i) {
        if(asc[i] != dsc[m-1-i]){
            cout << "ambiguous" << endl;
            return 0;
        }
    }
    cout << "unique" << endl;
    return 0;
}

