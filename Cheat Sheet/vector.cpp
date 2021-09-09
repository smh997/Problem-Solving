#include <bits/stdc++.h>
#include "line.cpp"
using namespace std;

struct vec{
    double x, y;
    
	vec() = default;
	
    vec(double x, double y){
        this->x = x;
        this->y = y;
    }

    vec(point& p1, point& p2){
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
    }

    vec& operator=(const vec& o) = default; 

    vec scale(double s){
        return vec(this->x * s, this->y * s);
    }

    point translate(point& p){
        return point(p.x + this->x, p.y + this->y);
    }

    double dot(vec& o){
        return this->x * o.x + this->y * o.y;
    }

    double norm_squared(){
        return this->x * this->x + this->y * this->y;
    }

    double norm(){
        return hypot(this->x, this->y);
    }

    double cross(vec& o){
        return this->x * o.y - this->y * o.x;
    }
	
	vec operator+(const vec& o) const{
        return vec(this->x + o.x, this->y + o.y);
    }
};

double dist_to_line(point& p, point& a, point& b){ // a, b are 2 different points on the given line.
    vec ap = vec(a, p);
    vec ab = vec(a, b);
    double u = ab.dot(ap) / ab.norm_squared();
    return ab.scale(u).translate(a).dist(p); // c = u * ab + a
}

double dist_to_line_segment(point& p, point& a, point& b){
    vec ap = vec(a, p);
    vec ab = vec(a, b);
    double u = ab.dot(ap) / ab.norm_squared();
    if(u < 0)
        return p.dist(a);
    if(u > 1)
        return p.dist(b);
    return dist_to_line(p, a, b);
}

double dist_of_line_segments(point& p1, point& p2, point& q1, point& q2){
    line l1(p1, p2), l2(q1, q2);
    if(!l1.parallel(l2)){
        point inter = l1.intersect(l2);
        if(on_line_segment(p1, p2, inter) && on_line_segment(q1, q2, inter))
            return 0.0;
    }
    double ans1 = min(dist_to_line_segment(q1, p1, p2), dist_to_line_segment(q2, p1, p2));
    if(p1 == p2)
        ans1 = min(p1.dist(q1), p1.dist(q2));
    double ans2 = min(dist_to_line_segment(p1, q1, q2), dist_to_line_segment(p2, q1, q2));
    if(q1 == q2)
        ans2 = min(q1.dist(p1), q1.dist(p2));
    return min(ans1, ans2);
}

double angle(point& a, point& o, point& b){
    vec oa = vec(o, a);
    vec ob = vec(o, b);
    return acos(oa.dot(ob) / (oa.norm() * ob.norm()));
}

// to determine whether point r is on the left/right side of the line.
bool ccw(point& p, point& q, point& r){
    vec v(p, r);
    return vec(p, q).cross(v) > -EPS;
}

bool collinear(point& p, point& q, point& r){
    vec v(p, r);
    return fabs(vec(p, q).cross(v)) < EPS;
}