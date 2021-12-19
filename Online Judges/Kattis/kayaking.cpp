/*
 * https://open.kattis.com/problems/kayaking
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int b, n, e, sb, sn, se, c[maxn];

struct s{
    int b, n, e;
    int sum;

    s(int b, int n, int e){
        this->b = b;
        this->n = n;
        this->e = e;
        sum = b * sb + n * sn + e * se;
    }

    bool operator<(const s& o) const{
        return this->sum < o.sum;
    }
};

vector<s> ss;

bool judge(int v, int b, int n, int e){
    int m = (b + n + e) / 2;
    for(int i = m-1; i >= 0; i--){
        bool found = false;
        for(s it : ss){
            if(b >= it.b && n >= it.n && e >= it.e && c[i] * it.sum >= v){
                b -= it.b, n -= it.n, e -= it.e;
                found = true;
            }
            if(found)
                break;
        }
        if(!found)
            return false;
    } 
    return true;
}

int main(){
    cin >> b >> n >> e >> sb >> sn >> se;
    for(int i = 0; i < (b + n + e) / 2; i++)
        cin >> c[i];
    sort(c, c + (b + n + e) / 2);
    ss.push_back(s(0, 1, 1));
    ss.push_back(s(1, 0, 1));
    ss.push_back(s(1, 1, 0));
    ss.push_back(s(2, 0, 0));
    ss.push_back(s(0, 2, 0));
    ss.push_back(s(0, 0, 2));
    sort(ss.begin(), ss.end());
    int lo = 0, hi = 1e9;
    while(lo < hi){
        int v = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(v, b, n, e))
            lo = v;
        else
            hi = v-1;
    }
    cout << lo << endl;
}