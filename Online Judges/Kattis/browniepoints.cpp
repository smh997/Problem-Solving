/*
 * https://open.kattis.com/problems/browniepoints
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20003
struct point{
    int x;
    int y;
    point(){x=y=0;}
    point(int _x, int _y){x=_x;y=_y;}
};
int n;
point p[MAX_N];
point center;
bool stan(int i){
    return (p[i].x > center.x && p[i].y>center.y) || (p[i].x < center.x && p[i].y < center.y); 
}
bool ollie(int i){
    return (p[i].x > center.x && p[i].y<center.y) || (p[i].x < center.x && p[i].y > center.y); 
}

int main()
{
    while(cin>>n && n){
        for (int i = 0; i < n; ++i)
            cin>>p[i].x>>p[i].y;
        center.x = p[n/2].x;
        center.y = p[n/2].y;
        int st=0, ol=0;
        for (int i = 0; i < n; ++i) {
            if(stan(i)) st++;
            else if(ollie(i)) ol++;
        }
        cout<<st<<" "<<ol<<endl;
    }
    return 0;
}

