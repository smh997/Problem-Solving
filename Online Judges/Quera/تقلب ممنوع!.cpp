/*
 * https://quera.org/problemset/8940/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, p, q;

int main(){
    cin >> n >> p >> q;
    vector<string> v;
    string a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    bool tagh,bikh;
    for (int i = 0; i < v.size() - 1; ++i) {
        bikh = false;
        for (int j = i + 1; j < v.size(); ++j) {
            tagh = true;
            for (int k = 0; k < p ; ++k) {
                if(v[i][k] != v[j][k]){
                    bikh = true;
                    break;
                }
            }
            if(bikh)
                break;
            for (int m = 0; m < q; ++m) {
                if(v[i][v[i].size() - 1 - m] != v[j][v[j].size() - 1 - m]){
                    tagh = false;
                    break;
                }
            }
            if(tagh){
                v.erase(v.begin() + j);
                j--;
            }
        }
    }
    cout << v.size() << endl;
}
