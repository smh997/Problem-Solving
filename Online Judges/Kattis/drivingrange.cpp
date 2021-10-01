/*
 * https://open.kattis.com/problems/drivingrange
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000003
int parent[MAX_N];
int raank[MAX_N];
int m, n, x, y, z;
bool visited[MAX_N];

vector<pair<long long int, pair<int, int>>> edgeList;

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

int main()
{
    cin>>n>>m;
    if(n==0 || m==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    edgeList.clear();
    fill_n(visited, n, false);
    for (int i = 0; i < m; ++i) {
        cin>>x>>y>>z;
        visited[x] = visited[y] = true;
        edgeList.push_back(make_pair(z, make_pair(x, y)));
    }
    for (int i = 0; i < n; ++i) {
        if(!visited[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    sort(edgeList.begin(), edgeList.end());
    long long int mstcost = 0, last;
    initSets(n);
    for (int i = 0; i < edgeList.size(); ++i) {
        pair<double, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mstcost += front.first;
            last = front.first;
            mergeSets(front.second.first, front.second.second);
        }
    }
    cout<<last<<endl;
    
    return 0;
}
