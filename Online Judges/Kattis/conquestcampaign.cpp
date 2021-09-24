/*
 * https://open.kattis.com/problems/conquestcampaign
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool visited[10003];
int r, c, n;
queue<int> q;

int c2p(int i, int j){
    return i*c+j;
}
pair<int, int> p2c(int p){
    return {p/c,p%c};
}

int adjr[4] = {0, 1, 0, -1};
int adjc[4] = {1, 0, -1, 0};

bool inrange(int i, int j){
    return (0 <= i && i < r) && (0 <= j && j < c);
}

int main()
{
    fill_n(visited, 10003, false);
    cin>>r>>c>>n;
    set<int> s;int stx, sty;
//    bool flag;
    int res = 0;
    for (int i = 0; i < n; ++i)
        cin>>stx>>sty, s.insert(c2p(stx-1, sty-1));
    for(auto a : s)
        q.push(a), visited[a] = true;
    int siz1 = q.size(), siz2 = 0;
    while(!q.empty()){
        pair<int, int> p = p2c(q.front());
        q.pop();
        siz1--;
//        flag = false;
        for (int i = 0; i < 4; ++i)
            if(inrange(p.first+adjr[i], p.second+adjc[i]))
               if(!visited[c2p(p.first+adjr[i], p.second+adjc[i])])
                   q.push(c2p(p.first+adjr[i], p.second+adjc[i])), visited[c2p(p.first+adjr[i], p.second+adjc[i])] = true, siz2++;
//        cout<<p.first<<" "<<p.second<<" "<<siz1<<" "<<res<<endl;
        if(!siz1) res++, siz1 = siz2, siz2 = 0;
//        cout<<p.first<<" "<<p.second<<" "<<siz1<<" "<<res<<endl;
    }
    cout<<res<<endl;
    
    
    return 0;
}

