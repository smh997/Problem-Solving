/*
 * https://open.kattis.com/problems/spiral
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int grid[203][203];
pair<int, int> itog[40003];
int x, y;
bool prime[40003];
int dist[40003];
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};

void gen(){
    int currx = 100, curry = 99, a = 1, lay = 1;
    grid[currx][curry] = a;itog[a] = {currx, curry};
    while(a<40000){
        if(lay%2){
            for (int i = 0; i < lay; ++i) {
                grid[currx][++curry] = ++a;
                itog[a] = {currx, curry};
            }
            for (int i = 0; i < lay; ++i) {
                grid[--currx][curry] = ++a;
                itog[a] = {currx, curry};
            }
        }
        else{
            for (int i = 0; i < lay; ++i) {
                grid[currx][--curry] = ++a;
                itog[a] = {currx, curry};
            }
            for (int i = 0; i < lay; ++i) {
                grid[++currx][curry] = ++a;
                itog[a] = {currx, curry};
            }
        }
        lay++;
    }
}

void genprime(){
    fill_n(prime, 40003, true);
    prime[1] = false;
    for (int i = 2; i < 201; ++i) {
        if(prime[i]){
            for (int j = i*i; j < 40001; j+=i) {
                prime[j] = false;
            }
        }
    }
}

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<200 && j<200;
}

int main()
{
    gen();
    genprime();
    pair<int, int> p;
    int t = 1;
    while(cin>>x>>y){
        cout<<"Case "<<t<<": ";t++;
        if(prime[x]||prime[y]){
            cout<<"impossible"<<endl;
            continue;
        }
        queue<pair<int, int>> q;
        fill_n(dist, 40003, INT_MAX);
        dist[x] = 0;
        q.push(itog[x]);
        while(!q.empty()){
            p = q.front();q.pop();
            if(grid[p.first][p.second] == y)
                break;
            for (int i = 0; i < 4; ++i) {
                if(inrange(p.first+dirx[i], p.second+diry[i]) && !prime[grid[p.first+dirx[i]][p.second+diry[i]]] && dist[grid[p.first+dirx[i]][p.second+diry[i]]] > dist[grid[p.first][p.second]]+1){
                    dist[grid[p.first+dirx[i]][p.second+diry[i]]] = dist[grid[p.first][p.second]]+1;
                    q.push({p.first+dirx[i], p.second+diry[i]});
                }
            }
        }
        cout<<((dist[y]==INT_MAX)?"impossible":to_string(dist[y]))<<endl;
    }
    return 0;
}

