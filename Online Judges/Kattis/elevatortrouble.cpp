/*
 * https://open.kattis.com/problems/elevatortrouble
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f,s,g,u,d, a;
    cin>>f>>s>>g>>u>>d;
    int dist[f+1];
    fill_n(dist, f+1, INT_MAX);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        a = q.front();q.pop();
        if(a+u<=f && dist[a]+1<dist[a+u]){
            dist[a+u]=dist[a]+1;
            q.push(a+u);
        }
        if(a-d >= 1 && dist[a]+1<dist[a-d]){
            dist[a-d]=dist[a]+1;
            q.push(a-d);
        }
    }
    if(dist[g]==INT_MAX)
        cout<<"use the stairs"<<endl;
    else
        cout<<dist[g]<<endl;
    return 0;
}
