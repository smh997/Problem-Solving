/*
 * https://open.kattis.com/problems/jurassicjigsaw
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1003
int parent[MAX_N];
int raank[MAX_N];
int m, n;
string dna[MAX_N];
vector<pair<int, pair<int, int>>> edgeList;

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
    int cost = 0;
    for (int k = 0; k < m; ++k) {
        if(dna[i][k]!=dna[j][k])
            cost++;
    }
    return cost;
}

int main()
{
    cin>>n>>m;
    edgeList.clear();
    for (int i = 0; i < n; ++i) {
        cin>>dna[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j)continue;
            edgeList.push_back(make_pair(calc_weight(i, j), make_pair(i, j)));
        }
    }
    sort(edgeList.begin(), edgeList.end());
    int mstcost = 0;
    vector<pair<int, int>> res;
    initSets(n);
    for (int i = 0; i < edgeList.size(); ++i) {
        pair<int, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            res.push_back(make_pair(front.second.first, front.second.second));
            mstcost += front.first;
            mergeSets(front.second.first, front.second.second);
        }
    }
    cout<<mstcost<<endl;
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    
    return 0;
}
