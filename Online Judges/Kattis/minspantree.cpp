/*
 * https://open.kattis.com/problems/minspantree
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20003
int parent[MAX_N];
int raank[MAX_N];
int n, m, a, b, c;
bool visited[MAX_N];
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

int main()
{
    while(true){
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        fill_n(visited, n, false);
        edgeList.clear();
        for (int i = 0; i < m; ++i) {
            cin>>a>>b>>c;
            edgeList.push_back(make_pair(c, make_pair(a, b)));
            edgeList.push_back(make_pair(c, make_pair(b, a)));
        }
        sort(edgeList.begin(), edgeList.end());
        int mstcost = 0;
        vector<pair<int, int>> res;
        initSets(n);
        for (int i = 0; i < edgeList.size(); ++i) {
            pair<int, pair<int, int>> front = edgeList[i];
            if(!inSameSets(front.second.first, front.second.second)){
                res.push_back(make_pair(min(front.second.first, front.second.second), max(front.second.first, front.second.second)));
                mstcost += front.first;
                mergeSets(front.second.first, front.second.second);
                visited[front.second.first] = true; visited[front.second.second] = true;
            }
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if(!visited[i]){
                cout<<"Impossible"<<endl;
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        sort(res.begin(), res.end());
        cout<<mstcost<<endl;
        for (int i = 0; i < res.size(); ++i) {
            cout<<res[i].first<<" "<<res[i].second<<endl;
        }
        
    }
    
    return 0;
}
