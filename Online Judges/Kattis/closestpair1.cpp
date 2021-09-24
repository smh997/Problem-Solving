/*
 * https://open.kattis.com/problems/closestpair1
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

struct point{
    double x;
    double y;
};

map<double, pair<point, point>> mp;

bool comparex(point p1, point p2){
    return p1.x<p2.x;
}
bool comparey(point p1, point p2){
    return p1.y<p2.y;
}

double dist(point p1, point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double solve(point* p2, int m, double d){
    
    double mindist = d;
    
    for (int i = 0; i < m; ++i)  
            for (int j = i+1; j < m && (p2[j].y - p2[i].y) < mindist; ++j)  
                if (dist(p2[i], p2[j]) < mindist){
                    mindist = dist(p2[i], p2[j]);
                    mp[mindist] = make_pair(p2[i], p2[j]);
                }
    return mindist;
}

double closest(point* p, int m){
    if(m<=3){
        double mindist = DBL_MAX;
        for (int i = 0; i < m-1; ++i)
            for (int j = i+1; j < m; ++j)
                if(mindist>dist(p[i], p[j])){
                    mindist = dist(p[i], p[j]);
                    mp[mindist] = make_pair(p[i], p[j]);
                }
        return mindist;
    }
    double d, dl, dr;
    dl = closest(p,m/2);
    dr = closest(p+m/2,m-m/2);
    
    d = min(dl, dr);
    int j = 0;point p2[m];
    for (int i = 0; i < m; ++i)
        if(abs(p[i].x-p[m/2].x)<d)
            p2[j++] = p[i];
    sort(p2, p2+j, comparey);
    
    return(min(d, solve(p2, j, d)));
}

int main()
{
    int m;
    while(cin>>m){
        if(m==0)
            break;
        point p[m];
        for (int i = 0; i < m; ++i) {
            cin>>p[i].x>>p[i].y;
        }
        sort(p, p+m, comparex);
        double mindist = closest(p, m);
//        cout<<mindist<<endl;
        printf("%.5f %.5f %.5f %.5f\n",mp[mindist].first.x,mp[mindist].first.y,mp[mindist].second.x,mp[mindist].second.y);
        
    }
    return 0;
}

