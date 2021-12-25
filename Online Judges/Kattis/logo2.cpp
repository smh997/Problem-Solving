/*
 * https://open.kattis.com/problems/logo2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-4

double PI = acos(-1);
struct point{
    double x, y;
    point(){
        x = y = 0;
    }
    point(double _x, double _y){
        x = _x;
        y = _y;
    }

};
struct vec{
    double x, y;
    vec(){
        x = y = 0;
    }
    vec(double _x, double _y){
        x = _x;
        y = _y;
    }
    vec(point p1, point p2){
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
};

vector<pair<string, int>> inss;
int n, m;
string s, sval;
pair<string, int> question;

point trans(point p, vec v){
    return point(p.x+v.x, p.y+v.y);
}


point goo(){
    point cur(0, 0);
    double deg = 0;
    for(auto ins : inss){
        if(ins.first=="fd"){
            cur = trans(cur, vec(ins.second*cos(deg*PI/180.0), ins.second*sin(deg*PI/180.0)));
        }
        else if(ins.first=="bk"){
            cur = trans(cur, vec(-ins.second*cos(deg*PI/180.0), -ins.second*sin(deg*PI/180.0)));
        }
        else if(ins.first=="lt"){
            deg += ins.second;
            if(deg>=360)
                deg -= 360;
        }
        else{
            deg -= ins.second;
            if(deg<0)
                deg += 360;
        }
    }
    return cur;
}

int main()
{
    cin>>n;
    while(n--){
        inss.clear();
        cin>>m;
        for (int i = 0; i < m; ++i) {
            cin>>s>>sval;
            if(sval == "?"){
                question.first = s;
                question.second = i;
                inss.push_back({s, 0});
            }
            else{
                inss.push_back({s, stoi(sval)});
            }
        }
        int d; double dd;
        point p;
        if(question.first == "fd" || question.first == "bk"){
            p = goo();
            d = round(hypot(p.x, p.y));
            inss[question.second].second = d;
            p = goo();
            dd = hypot(p.x, p.y);
            if(fabs(dd)<EPS){
                cout<<d<<endl;
                continue;
            }
            cout<<-d<<endl;
        }
        else{
            for (int i = 0; i < 360; ++i) {
                inss[question.second].second = i;
                p = goo();
                dd = hypot(p.x, p.y);
                if(fabs(dd)<EPS){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        
    }
    return 0;
}

