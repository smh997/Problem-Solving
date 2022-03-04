/*
 * https://quera.org/problemset/132248/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define watch(x) cout << #x << " : " << x << endl
#define pb push_back
#define pll pair<ll, ll>

const ll maxn = 1e5 + 1;
const ll mod = 1e9 + 7;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> sortedArr = arr;
    unordered_map<ll, ll> indexOf;
    ll currentIndex = 0;

    sort(sortedArr.begin(), sortedArr.end());
    for(ll i = 0; i < n; i++)
    {
        if(i % k == k - 1)
        {
            for(ll j = i; j > i - k; j--)
            {
                indexOf[sortedArr[j]] = currentIndex;
            }
            currentIndex++;
        }
    }

    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        a[i] = indexOf[arr[i]];
    }

    vector<ll> lis;
    for(ll i = 0; i < n; i++)
    {
        auto it = upper_bound(lis.begin(), lis.end(), a[i]);
        if(it == lis.end())
        {
            lis.push_back(a[i]);
        }
        else
        {
            *it = a[i];
        }
    }
    cout << n - lis.size();
    return 0;
}
