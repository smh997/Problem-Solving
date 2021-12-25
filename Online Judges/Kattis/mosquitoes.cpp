/*
 * https://open.kattis.com/problems/mosquitoes
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-8

struct point{
    double x, y;
    point(){
        x = 0, y = 0;
    }

    point(double _x, double _y){
        x = _x, y = _y;
    }
};

point mosq[35];

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
} // to get the other center, reverse p1 and p2

int insideCircle(point p, point c, double r) { // all integer version
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r; // all integer
    return Euc < rSq ? 0 : fabs(Euc-rSq) < EPS ? 1 : 2; 
} //inside/border/outside

int main()
{
    int n, m;
    double di, r;
    cin >> n;
    while(n--){
        cin >> m >> di; r = di/2;
        for (int i = 0; i < m; ++i) {
            cin >> mosq[i].x >> mosq[i].y;
        }
        int res = 1;
        point center;
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                if(circle2PtsRad(mosq[i], mosq[j], r, center)){
                    int su = 0;
                    for (int k = 0; k < m; ++k) {
                        if(insideCircle(mosq[k], center, r) < 2){
                            su++;
                        }
                    }
                    res = max(su, res);
                    su = 0;
                    circle2PtsRad(mosq[j], mosq[i], r, center);
                    for (int k = 0; k < m; ++k) {
                        if(insideCircle(mosq[k], center, r) < 2){
                            su++;
                        }
                    }
                    res = max(res, su);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

