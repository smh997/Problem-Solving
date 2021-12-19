/*
 * https://open.kattis.com/problems/inverteddeck
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 3;
int n;
pair<int, int> a[maxn], b[maxn];
vector<int> ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
        b[i] = a[i];
    }
    bool sorted = 1;
    for(int i = 0; i < n - 1; i++)
        if(b[i].first > b[i + 1].first){
            sorted = 0;
            break;
        }
    if(sorted){
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    sort(a, a + n);
    int start = 0;
    for(int i = 0; i < n; i++)
        if(i + 1 != a[i].second){
            start = i;
            break;
        }
    int end = n - 1;
    for(int j = n - 1; j >= 0; j--)
        if(j + 1 != a[j].second){
            end = j;
            break;
        }
    for(int i = 0; i < start; i++)
        ans.push_back(b[i].first);
    for(int j = end; j >= start; j--)
        ans.push_back(b[j].first);
    for(int i = end + 1; i < n; i++)
        ans.push_back(b[i].first);
    for(int i = 0; i < n - 1; i++)
        if(ans[i] > ans[i + 1]){
            cout << "impossible" << endl;
            return 0;
        }
    cout << start + 1 << " " << end + 1 << endl;
}