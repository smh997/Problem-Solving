/*
 * https://open.kattis.com/problems/knapsackcollection
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, s, t;
int a[2003];
multiset<int> ms;
set<int> b;
num ans[10000003], sum = 0;

inline num gcd(num a, num b){
    num mi = min(a, b);
    num mx = max(a, b);
    if(mi == 0)
        return mx;
    return gcd(mx % mi, mi);
}

int main(){
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i], b.insert(a[i]);
    for(int i : b){
        for(int z = 0; z < n; z++)
            ms.insert(a[z]);
        num T = 0;
        int k = i;
        while(!ms.empty()){
            auto it = ms.lower_bound(k);
            if(it == ms.end())
                T += s - k, k = 0;
            else if(*it == k)
                T += t, k = (k + t) % s, ms.erase(it);
            else
                T += *it - k + t, k = (*it + t) % s, ms.erase(it);
        }
        ans[i] = T;
        sum += T;
    }
    for(int i = 0; i < s; i++)
        if(!ans[i]){
            auto it = b.upper_bound(i);
            if(it == b.end())
                ans[i] = s - i + *b.begin() + ans[*b.begin()];
            else
                ans[i] = *it - i + ans[*it];
            sum += ans[i];
        }
    sort(ans, ans + s);
    num g = gcd(sum, s);
    cout << ans[0] << endl;
    cout << ans[s - 1] << endl;
    cout << sum / g << "/" << s / g << endl;
}