/*
 * https://open.kattis.com/problems/musicaltrees
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

set<int> res;
int tree[103], person[103];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> person[i];
    for (int i = 0; i < m; ++i)
        cin >> tree[i];
    sort(person, person+n);
    sort(tree, tree+m);
    for (int i = 0; i < n; ++i) {
        int mindist = INT_MAX, mi = -1;
        for (int j = 0; j < m; ++j) {
            if(mindist > abs(tree[j]-person[i])){
                mindist = abs(tree[j]-person[i]);
                mi = j;
            }
        }
        res.insert(mi);
    }
    cout << n - res.size() << endl;
    return 0;
}

