/*
 * https://open.kattis.com/problems/phonelist
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

struct node{
    char digit;
    bool leaf = 0;
    set<node> children;

    node(char digit){
        this->digit = digit;
    }

    bool operator<(const node & other) const{
        return this->digit < other.digit;
    }

    bool operator==(const node & other) const{
        return this->digit == other.digit;
    }
};

node root('.');

bool add_number(string number){
    node * it = &root;
    bool making_tree = 0;
    for (auto iter = number.begin(); iter != number.end(); ++iter) {
        if(making_tree){
            it->children.insert(node(*iter));
            it = (node *) &(*it->children.find(node(*iter)));
            continue;
        }
        auto it2 = it->children.find(node(*iter));
        if(it2 == it->children.end()){
            if(it->leaf){
                return 0;
            }
            making_tree = 1;
            it->children.insert(node(*iter));
            it = (node *) &(*it->children.find(node(*iter)));
        }
        else{
            it = (node *) &(*it2);
        }
    }
    if(making_tree){
        it->leaf = 1;
    }
    return making_tree;
}

int t, n;

int main(){
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        root.children.clear();
        string number;
        bool res = 1;
        for (int j = 0; j < n; ++j) {
            cin >> number;
            if(!(add_number(number)))
                res = 0;
        }
        cout << (res?"YES":"NO") << endl;
    }
    return 0;
}
