/*
 * https://open.kattis.com/problems/distinctivecharacter
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, k, dis[1<<21];
queue<int> q;

int main()
{
    fill_n(dis, 1<<21, INT_MAX);
    cin>>n>>k;
    string inp;
    int nu, res=0;
    for (int i = 0; i < n; ++i) {
        cin>>inp;
        nu = 0;
        for (int j = 0; j < k; ++j)
            nu += ((inp[j]=='1')?1:0)*(1<<j); 
        q.push(nu); 
        dis[nu] = 0;
    }
    int curr, neighbor;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for (int i = 0; i < k; ++i) {
            neighbor = curr^(1<<i); 
            if(dis[curr]+1<dis[neighbor])
                dis[neighbor] = dis[curr]+1, q.push(neighbor); 
        }
    }
    res = curr; 
    for (int i = 0; i < k; ++i)
        cout<<(((1<<i)&res)?'1':'0')<<((i==k-1)?"\n":""); 
    return 0;
}
