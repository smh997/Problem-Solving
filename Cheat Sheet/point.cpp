#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

struct point{
    double x, y;
    
    point() = default;
    
    point(double x, double y){
        this->x = x, this->y = y;
    }
	
	point& operator=(const point& o) = default; 
    
    bool operator==(const point& o) const{
        return fabs(this->x - o.x) < EPS && fabs(this->y - o.y) < EPS;
    }
    
    bool operator<(const point& o) const{
        if(fabs(this->x - o.x) < EPS)
            return this->y < o.y;
        return this->x < o.x;
    }

    double dist(const point& o){
        return hypot(this->x - o.x, this->y - o.y);
    }
    
    point rotate(double rad){
        return point(this->x * cos(rad) - this->y * sin(rad), this->x * sin(rad) + this->y * cos(rad));
    }
};

inline double deg_to_rad(double deg){
    return (deg * M_PI) / 180; 
}

inline double rad_to_dag(double rad){
    return (rad * 180) / M_PI; 
}