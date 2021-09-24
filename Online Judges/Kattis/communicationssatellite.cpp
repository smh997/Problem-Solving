/*
 * https://open.kattis.com/problems/communicationssatellite
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2003
int parent[MAX_N];
int raank[MAX_N];
int n;
double x, y, r;
pair<double,pair<double, double>> points[MAX_N];
vector<pair<double, pair<int, int>>> edgeList;

void initSets(int n){
    for (int i = 0; i < n; ++i) {
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

double calc_weight(int i, int j){
    return max(0.0, sqrt((points[i].second.first - points[j].second.first)*(points[i].second.first - points[j].second.first) + (points[i].second.second - points[j].second.second) * (points[i].second.second - points[j].second.second))-(points[i].first+points[j].first));
}

int main()
{
    cin>>n;
    edgeList.clear();
    for (int i = 0; i < n; ++i) {
        cin>>points[i].second.first>>points[i].second.second>>points[i].first;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j)continue;
            edgeList.push_back(make_pair(calc_weight(i, j), make_pair(i, j)));
        }
    }
    sort(edgeList.begin(), edgeList.end());
    double mstcost = 0;
    initSets(n);
    for (int i = 0; i < edgeList.size(); ++i) {
        pair<double, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mstcost += front.first;
            mergeSets(front.second.first, front.second.second);
        }
    }
    printf("%.7f\n", mstcost);
    
    return 0;
}
