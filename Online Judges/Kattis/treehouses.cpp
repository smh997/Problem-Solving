/*
 * https://open.kattis.com/problems/treehouses
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1003

int a, b;
int a1, b1, e, p, v;
double x, y;
vector<pair<double, pair<int, int>>> edgeList;
vector<pair<double, double>> vertices;
int parent[MAX_N];
int raank[MAX_N];

void initSets(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        raank[i] = 0;
    }
}

int findSet(int i){
    if(parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

inline bool inSameSets(int i, int j){
    return findSet(i) == findSet(j);
}

void mergeSets(int i, int j){
    int a = findSet(i);
    int b = findSet(j);
    if(a == b)
        return;
    if(raank[a] >= raank[b])
        parent[b] = a;
    else
        parent[a] = b;
    if(raank[a] == raank[b])
        raank[a]++;
}

double distance(const pair<double, double> & p1, const pair<double, double> & p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second) * (p1.second-p2.second));
}

int main(){
    scanf("%d %d %d", &v, &e, &p);    
    for(int i=0; i<v; i++){
        scanf("%lf %lf", &x, &y);
        vertices.push_back({x, y});
    }
    for(int i=0; i< v; i++){
        for(int j=i+1; j<v; j++){
            if(i < e && j < e)
                edgeList.push_back({0.0, {i, j}});
            else
                edgeList.push_back({distance(vertices[i], vertices[j]), {i, j}});
        }
    }
    for(int i=0; i<p; i++){
        scanf("%d %d", &a1, &b1);
        edgeList.push_back({0.0, {a1-1, b1-1}});
    }
    sort(edgeList.begin(), edgeList.end());
    double mst = 0;
    int forests = v;
    initSets(v);
    for (int i = 0; i < edgeList.size(); i++){
        if(forests == 1)
            break;
        pair<double, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mst += front.first;
            forests--;
            mergeSets(front.second.first, front.second.second);
        }
    }
    cout << fixed << setprecision(4) << mst << endl;
    return 0;
}

