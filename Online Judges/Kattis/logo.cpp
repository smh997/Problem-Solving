/*
 * https://open.kattis.com/problems/logo
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int m, n;
struct point{
    double x, y; int deg;
    point(){x=y=0;deg=0;}
};
point cur;
double val;
string cmd;
double PI = 2*acos(0.0);
void fd(){
//    cout<<cur.x<<" "<<cur.y<<endl;
    cur.x = cur.x + val*cos(cur.deg * PI/180.0);
    cur.y = cur.y + val*sin(cur.deg * PI/180.0);
//    cout<<cur.x<<" "<<cur.y<<endl;
}
void bk(){
//    cout<<cur.x<<" "<<cur.y<<endl;
    cur.x = cur.x - val*cos((cur.deg) * PI/180.0);
    cur.y = cur.y - val*sin((cur.deg) * PI/180.0);
//    cout<<cur.x<<" "<<cur.y<<endl;
}

int main()
{
    cin>>m;
    while(m--){
        cin>>n;
        cur.x = cur.y = 0;cur.deg=0;
        for (int i = 0; i < n; ++i) {
            cin>>cmd>>val;
            if(cmd=="lt")
                cur.deg = (cur.deg + (int)val)%360;
            else if(cmd == "rt")
                cur.deg = (cur.deg - (int)val + 360)%360;
            else if(cmd == "fd")
                fd();
            else
                bk();
        }
        cout<<fixed<<setprecision(0)<<hypot(cur.x, cur.y)<<endl;
    }
    return 0;
}

