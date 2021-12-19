/*
 * https://open.kattis.com/problems/importspaghetti
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int n, a, b, m;
int dist[503][503];
map<string, int> mp;
string f[503], s;
vector<string> v;

void prin(int i, int j){
    for (int k = 0; k < n; ++k) {
        if(dist[i][k]==1 && (dist[i][j]==1 || (dist[i][j]-1==dist[k][j]))){
            cout<<f[i]<<" ";
            if(dist[i][j]>1){
                prin(k, j);
            }
            break;
        }
    }
}

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
        mp[f[i]]=i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j]=INT_MAX;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin>>s>>m;
        a = mp[s];
        cin.ignore();
        for (int j = 0; j < m; j++)
        {
            v.clear();
            getline(cin, s);
            string aa;int ii=-1;
            while(s!=""){
                int it = s.find(" ");
                aa = s.substr(0, it);
                if(it==string::npos)
                    s = "";
                else
                    s = s.substr(it+1, s.length());
                ii++;
                if(ii==0)
                    continue;
                v.push_back(aa);
            }
            for (int kk = 0; kk < v.size(); kk++)
            {
                if(kk<v.size()-1)
                v[kk] = v[kk].substr(0, v[kk].length()-1);
                b = mp[v[kk]];
                dist[a][b] = 1;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(dist[i][k] != INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    int mi=INT_MAX, mid=INT_MAX;
    for (int i = 0; i < n; ++i) {
        if(dist[i][i]<mi){
            mi = dist[i][i];
            mid = i;
        }
    }
    if(mid!=INT_MAX){
        prin(mid, mid);
    }
    else{
        cout<<"SHIP IT"<<endl;
    }
    
    return 0;
}

