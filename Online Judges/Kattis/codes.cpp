/*
 * https://open.kattis.com/problems/codes
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

int mt[33][18];
vector<int> v;

int main()
{
    int t, n, k, res, s, ss;
    cin>>t;
    while(t--){
        res = 1e9;s=0;ss=0;
        cin>>n>>k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                cin>>mt[i][j];
            }
        }
        
        for (int i = 0; i < k; ++i) {
            v.clear();
            for (int j = 0; j < i; ++j) {
                v.push_back(0);
            }
            for (int j = i; j < k; ++j) {
                v.push_back(1);
            }
            do {
                ss=0;
//                for (int f = 0; f < k; ++f) {
//                    cout<<v[f]<<" ";
//                }cout<<endl;
                for (int o = 0; o < n; ++o) {
                    s = 0;
                    for (int l = 0; l < k; ++l) {
                        s += v[l]*mt[o][l];
                    }
//                    cout<<"s "<<s%2<<endl;
                    ss += s%2;
                }
                
                res = min(ss, res);
            } while (next_permutation(v.begin(), v.end()));
        }
        cout<<res<<endl;
    }
    return 0;
}

