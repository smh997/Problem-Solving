/*
 * https://open.kattis.com/problems/cursethedarkness
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1003
struct point{
    double x, y;
    point(){x=y=0;}
};

point p[MAX_N];
point you;
int m, n;

bool inrange(int i){
    return hypot(you.x-p[i].x, you.y-p[i].y) <= 8.0;
}

int main()
{
    cin>>m;
    while(m--){
        cin>>you.x>>you.y;
        cin>>n;
        bool res = false;
        for (int i = 0; i < n; ++i){
            cin>>p[i].x>>p[i].y;
            if(!res && inrange(i))
                res = true;
        }
        cout<<((res)?"light a candle":"curse the darkness")<<endl;
        
    }
    return 0;
}

