/*
 * https://open.kattis.com/problems/convexpolygonarea
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){
        x = y = 0;
    }
    point(int _x, int _y){
        x = _x;
        y = -y;
    }
};

int n, m;
point p[103];

double area(){
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        x1 = p[i].x; x2 = p[(i+1)%m].x;
        y1 = p[i].y; y2 = p[(i+1)%m].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

int main()
{
    cin>>n;
    while(n--){
        cin>>m;
        for (int i = 0; i < m; ++i) {
            cin>>p[i].x>>p[i].y;
        }
        cout<<area()<<endl;
    }
    return 0;
}

