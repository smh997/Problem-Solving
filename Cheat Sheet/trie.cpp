#include <bits/stdc++.h>
using namespace std;

// Trie Implementation

class trie{
    public:
    trie* adj[26+3];
    trie* parent = nullptr;
    bool terminal = false;

    trie(){
        fill_n(adj, 26, nullptr);
    }

    trie(trie* parent){
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

trie* root = new trie();

// O(|S|)
inline void trie_insert(string s){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'A'; // use 'a' for lowercase letters
        if(t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
    }
    t->terminal = true;
}

// O(|S|)
inline bool trie_find(string s){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'A'; // use 'a' for lowercase letters
        if(t->adj[ind] == nullptr)
            return false;
        t = t->adj[ind];
    }
    return t->terminal;
}

int main(){
    // Example:
    trie_insert("ABC");
    trie_insert("KARIM");
    trie_insert("KERIM");
    trie_insert("ABCD");
    trie_insert("GHAZAL");
    string s;
    while(cin >> s)
        cout << trie_find(s) << endl;
}