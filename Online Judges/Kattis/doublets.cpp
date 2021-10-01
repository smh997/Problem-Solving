/*
 * https://open.kattis.com/problems/doublets
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

class trie{
    public:
    trie* adj[26+3];
    trie* parent = nullptr;
    bool terminal = false;
    int id = -1;

    trie(){
        fill_n(adj, 26, nullptr);
    }

    trie(trie* parent){
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

trie* root = new trie();

inline void trie_insert(string s, int id){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'a'; // 'a' for lowercase
        if(t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
    }
    t->terminal = true;
    t->id = id;
}

#define inf INT_MAX

vector<string> dict;
string s, s2;
vector<int> adjs[26003];
int par[26003], dis[26003];
map<string, int> gid;

string tmp;

void connect(trie* t, int ind, int id, bool change){
    if(ind == tmp.size()){
        if(t->terminal && change)
            adjs[id].push_back(t->id);
        return;
    }
    if(t->adj[tmp[ind] - 'a'] != nullptr)
        connect(t->adj[tmp[ind] - 'a'], ind + 1, id, change);
    if(!change)
        for(int i = 0; i < 26; i++){
            if(i + 'a' == tmp[ind] || t->adj[i] == nullptr)
                continue;
            connect(t->adj[i], ind + 1, id, true);
        }
}

int main(){
    while(true){
        getline(cin, s);
        if(s.empty())
            break;
        dict.push_back(s);
    }
    for(int i = 0; i < dict.size(); i++)
        trie_insert(dict[i], i), gid[dict[i]] = i;
    for(int i = 0; i < dict.size(); i++){
        tmp = dict[i];
        connect(root, 0, i, false);
    }
    while(cin >> s >> s2){
        fill_n(dis, dict.size(), inf);
        int id1 = gid[s], id2 = gid[s2];
        queue<int> q;
        dis[id1] = 0;
        q.push(id1);
        while(!q.empty()){
            int p = q.front();
            q.pop();
            if(p == id2)
                break;
            for(int v : adjs[p])    
                if(dis[v] == inf)
                    par[v] = p, dis[v] = dis[p] + 1,  q.push(v);
        }
        if(dis[id2] == inf){
            cout << "No solution." << endl << endl;
            continue;
        }
        int i = id2;
        vector<int> ans;
        while(i != id1){
            ans.push_back(i);
            i = par[i];
        }
        ans.push_back(id1);
        reverse(ans.begin(), ans.end());
        for(int x : ans)
            cout << dict[x] << endl;
        cout << endl;
    }
}