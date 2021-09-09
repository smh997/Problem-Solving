#include <bits/stdc++.h>
#include "point.cpp"
using namespace std;

struct circle{
    point center;
    double radius;

    circle() = default;

    circle(point center, double radius){
        this->center = center;
        this->radius = radius;      
    }

    circle& operator=(const circle& o) = default; 

    int status(point& p){
        double dx = p.x - center.x, dy = p.y - center.y;
        double euc = dx * dx + dy * dy;
        if(fabs(euc - radius * radius) < EPS)
            return 0; // on circle
        if(euc < radius * radius)
            return -1; // inside circle
        return 1; // outside circle
    }

    double perimeter(){
        return 2 * M_PI * this->radius;
    }

    double area(){
        return M_PI * this->radius * this->radius;
    }

    double arc(double rad){
        return rad * this->radius;
    } 

    double chord(double rad){
        return 2 * this->radius * sin(rad / 2);
    }

    double sector(double rad){
        return (rad / (2 * M_PI)) * this->area();
    }
};

// before using make sure that p1.dist(p2) <= 2 * r
pair<circle, circle> circles_with_2_points(point& p1, point& p2, double r){
    double l = p1.dist(p2);
    double a = sqrt(r * r - l * l / 4);
    return {circle(point((p1.x + p2.x) / 2 + (p1.y - p2.y) * a / l, (p1.y + p2.y) / 2 + (p2.x - p1.x) * a / l), r),
            circle(point((p1.x + p2.x) / 2 + (p2.y - p1.y) * a / l, (p1.y + p2.y) / 2 + (p1.x - p2.x) * a / l), r)};
}
