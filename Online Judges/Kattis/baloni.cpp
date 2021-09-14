/*
 * https://open.kattis.com/problems/baloni
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

set<int> s;
int a, n;
int has[1000003];

int main()
{
    cin >> n;
    cin >> a;
    has[a]++;
    s.insert(a);
    for (int i = 1; i < n; ++i) {
        cin >> a;
        auto it = s.upper_bound(a);
        if (it != s.end()) {
            int val = *it;
            if (val == a + 1) {
                has[val]--;
                if (has[val] == 0)
                    s.erase(it);
            }
        }
        has[a]++;
        if (has[a] == 1)
            s.insert(a);
    }
    cout << accumulate(has, has+1000001, 0) << endl;
    
    return 0;
}

