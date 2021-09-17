/*
 * https://open.kattis.com/problems/cardtrading
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 2e5 + 3;

int n, t, k;
num deck[maxn], acc[maxn];
pair<num, num> cards[maxn], trans[maxn];

int main(){
    int x;
    cin >> n >> t >> k;
    for(int i = 0; i < n; i++)
        cin >> x, deck[x-1]++;
    for(int i = 0; i < t; i++)
        cin >> cards[i].first >> cards[i].second;
    for(int i = 0; i < t; i++)
        trans[i] = {cards[i].first * (2 - deck[i]), cards[i].second * deck[i]};
    num ans = 0;
    for(int i = 0; i < t; i++)
        ans -= trans[i].first, acc[i] = trans[i].first + trans[i].second;
    sort(acc, acc + t);
    for(int i = k; i < t; i++)
        ans += acc[i];
    cout << ans << endl;
}
