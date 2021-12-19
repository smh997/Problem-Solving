/*
 * https://open.kattis.com/problems/installingapps
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

int n, c, dp[10005][505];

pair<pair<int,int>,int> apps[505];

bool used[10005][505];

int comp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2){
    return p1.first.first-p1.first.second > p2.first.first-p2.first.second; 
}

int cdp(int d, int i) {
	if (i >= n) return 0;
	if (dp[d][i] >= 0) return dp[d][i];
	int best = cdp(d, i + 1);
	if (d >= apps[i].first.first && d >= apps[i].first.second) {
		int gonext = 1 + cdp(d - apps[i].first.second, i + 1);
		if (gonext > best) {
			best = gonext;
			used[d][i] = true;
		}
	}
	return dp[d][i] = best;
}

int main() {
	cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> apps[i].first.first >> apps[i].first.second, apps[i].second = i + 1;
	sort(apps, apps+n, comp);
    for (int d = 0; d < c+1; ++d)
        for (int i = 0; i < n; ++i)
            dp[d][i] = -1;
	cout << cdp(c, 0) << endl;
	int i = 0, f = c;
	while (i<n) {
		if (used[f][i]) {
            cout << apps[i].second;
			f -= apps[i].first.second;
            cout<<((f!=0)?' ': '\n');
		}
		i++;
	}
	return 0;
}
