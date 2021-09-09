#include <bits/stdc++.h>
#include "point.cpp"
using namespace std;

#define INF LLONG_MAX

struct line{
    double m, b;
	
	line() = default;
    
    line(point& p1, point& p2){
        if(fabs(p1.x - p2.x) < EPS)
            this->m = INF, this->b = p1.x;
        else if(fabs(p1.y - p2.y) < EPS)
            this->m = 0, this->b = p1.y;
        else{
            this->m = (p1.y - p2.y) / (p1.x - p2.x);
            this->b = p1.y - this->m * p1.x;
        }
    }

    line& operator=(const line& o) = default; 

    bool parallel(const line& o) const{
        return fabs(this->m - o.m) < EPS;
    }

    bool operator==(const line& o) const{
        return parallel(o) && (fabs(this->b - o.b) < EPS);
    }

    point intersect(const line& o) const{
        if(this->m == INF)
            return point(this->b, o.m * this->b + o.b);
        if(o.m == INF)
            return point(o.b, this->m * o.b + this->b);
        double x = (o.b - this->b) / (this->m - o.m);
        return point(x, this->m * x + this->b);
    }
};

bool on_line_segment(point& a, point& b, point& c){
    return fabs(a.dist(b) - c.dist(a) - c.dist(b)) < EPS;
}