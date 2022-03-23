/*
 * https://quera.org/problemset/17679/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, q, com, x, i, j;
int qus[300003];
long long int sv[300003];
vector<long long int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    int c = 1;
    for (int k = 0; k < q; ++k) {
        cin >> com;
        if(com == 1){
            cin >> x;
            sv[c] = x + sv[c - 1];
            c++;
        }
        else{
            cin >> i >> j;
            if(j == 0){
                ans.push_back(0);
                continue;
            }
            ans.push_back(sv[qus[i - 1] + j] - sv[qus[i - 1]]);
            qus[i - 1] += j;
        }
    }
    for(auto a: ans){
        cout << a << endl;
    }
    return 0;
}
