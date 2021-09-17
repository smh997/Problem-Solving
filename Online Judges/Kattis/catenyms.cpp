/*
 * https://open.kattis.com/problems/catenyms
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t, n, u, v;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        bool vis[n];
        fill_n(vis, n, false);
        vector<pair<int, int>> adj[26];
        vector<int> indeg(26, 0), outdeg(26, 0);
        string words[n];
        for (int i = 0; i < n; ++i) {
            cin>>words[i];
        }sort(words, words+n);
        for (int i = 0; i < n; ++i) {
            u = words[i][0]-'a';
            v = words[i][words[i].length()-1]-'a';
            adj[u].push_back({v, i});
            indeg[v]++;outdeg[u]++;
        }
        int curr = 0;
        for (int i = 0; i < 26; ++i) {
            if(outdeg[i]>0){
                curr = i;
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            if(outdeg[i]-indeg[i]==1)
                curr = i;
            if(outdeg[i]!=indeg[i])
                sum++;
        }
//        for (int i = 0; i < 26; ++i) {
//            cout<<i<<" ";
//            /*for (auto v : adj[i]) {
//                cout<<words[v.second]<<" ";
//            }*/cout<<adj[i].size()<<" "<<indeg[i]<<endl;
//        }
        if(!(sum==0 || (sum==2 && outdeg[curr]-indeg[curr]==1))){
            cout<<"***"<<endl;
            continue;
        }
        vector<int> path;
        stack<pair<int, int>>st;
        pair<int, int> pp;
        int lastEdge = -1;
//        cout<<curr<<endl;cout<<outdeg[curr]<<endl;
        while(!st.empty() || outdeg[curr]){
            if (!outdeg[curr]){
                path.push_back(lastEdge);
                pp = st.top(); st.pop();
                curr = pp.first; lastEdge = pp.second;
                continue;
            }
            else{
                for (auto e : adj[curr]){;
                    if (!vis[e.second]){
                        outdeg[curr]--;
                        vis[e.second] = true;
                        st.push({curr, lastEdge});
                        curr = e.first;
                        lastEdge = e.second;
                        break;
                    }
                }
            }
        }
//        cout<<path.size()<<endl;
        if(path.size()!=n){
            cout<<"***"<<endl;
            continue;
        }
        for (int i = n-1; i >= 0; --i) {
            cout<<words[path[i]]<<((i==0)?"\n":".");
        }
    }
    return 0;
}
