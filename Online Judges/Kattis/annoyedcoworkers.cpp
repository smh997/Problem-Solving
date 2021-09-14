/*
 * https://open.kattis.com/problems/annoyedcoworkers
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
int h, c;
long long int a[100003], d[100003];
long long int res;

int main()
{
    cin >> h >> c;
    res = 0;
    for (int i = 0; i < c; ++i) {
        cin >> a[i] >> d[i];
        res = max(a[i], res);
        pq.push({a[i]+d[i], i});
    }
    pair<long long int, int> help;
    while(h){
        help = pq.top();
        pq.pop();
        res = max(help.first, res);
        pq.push({help.first+d[help.second], help.second});
        h--;
    }
    cout << res << endl;
    return 0;
}

