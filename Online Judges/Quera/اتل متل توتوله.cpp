/*
 * https://quera.org/problemset/69899/
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int lose[31];
int main()
{
    cin>>n>>k;
    m = n;
    vector<int> v(2 * n);
    for (int i = 0; i < n; ++i)
        v[2 * i] = v[2 * i + 1] = i + 1;
    int tmp = 0;
    while(m > 1){
        for (int i = 0; i < k; ++i) {
            cout << v[tmp];
            if(i == k - 1){
                cout << endl;
                lose[v[tmp]]++;
                if(lose[v[tmp]] == 2)
                    m--;
                v.erase(v.begin() + tmp);
                tmp = tmp % v.size();
            }
            else{
                cout << " ";
                tmp = (tmp + 1) % v.size();
            }
        }
    }
    cout << "winner:" << v[0] << endl;
    return 0;
}
