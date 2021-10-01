/*
 * https://open.kattis.com/problems/dartscores
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){
        x = y = 0;
    }
};

int t, n;
point p;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        long long int res = 0;
        for (int i = 0; i < n; ++i) {
            cin>>p.x>>p.y;
            for (int j = 10; j > 0; --j) 
                if(hypot(p.x, p.y)<=(20*(11-j))){
                    res += j;
                    break;
                }
        }
        cout<<res<<endl;
    }
    return 0;
}

