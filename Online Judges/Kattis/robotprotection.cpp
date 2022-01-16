/*
 * https://open.kattis.com/problems/robotprotection
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
struct point{
    int x, y;
    point(int _x, int _y){
        x = _x;
        y = _y;
    }
    point(){
        x = y = 0;
    }
    bool operator ==(point other){
        return x == other.x && y == other.y;
    }
};
double dist (point p, point q){
    return hypot((p.x-q.x), p.y-q.y);
}

vector<point> P;
set<pair<int, int>> tmp;
point pivot;

struct vec {
    int x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) { 
    return a.x * b.y - a.y * b.x; 
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; 
}

bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}
vector<point> CH() {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
        return P; 
    }
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n) {
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back(); 
    }
    return S; 
}
double area(const vector<point> &res) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)res.size()-1; i++) {
        x1 = res[i].x; x2 = res[i+1].x;
        y1 = res[i].y; y2 = res[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}
int main()
{
    int n, x, y;
    while(cin>>n && n){
        P.clear();tmp.clear();
        for (int i = 0; i < n; ++i) {
            cin>>x>>y;
            tmp.insert({x, y});
        }
        for(auto v : tmp){
            P.push_back(point(v.first, v.second));
        }
        P.push_back(P[0]);
        vector<point> res = CH();
        cout<<fixed<<setprecision(1)<<area(res)<<endl;
    }
    return 0;
}

