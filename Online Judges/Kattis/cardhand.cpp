/*
 * https://open.kattis.com/problems/cardhand
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string ord = "23456789TJQKA";
map<char, int> mp; 

int n;
pair<int, char> deck[53];

set<char> tmp;
vector<char> labels;
map<char, vector<int>> cards;

vector<pair<int, char>> seq;

void produce(int mask){
    for(int i = 0; i < labels.size(); i++){
        char l = labels[i];
        vector<int> cl = cards[l];
        sort(cl.begin(), cl.end());
        if(mask & (1 << i))
            reverse(cl.begin(), cl.end());
        for(int t : cl)
            seq.push_back({t, l});
    }
}

map<pair<int, char>, int> ind;
vector<int> liss;

int lis(){
    ind.clear();
    liss.clear();
    for(int i = 0; i < n; i++)
        ind[deck[i]] = i;
    for(int i = 0; i < n; i++){
        int curr = ind[seq[i]];
        auto it = lower_bound(liss.begin(), liss.end(), curr);
        if(it == liss.end())
            liss.push_back(curr);
        else
            *it = curr;
    }
    return liss.size();
}

int main(){
    for(int i = 0; i < ord.size(); i++)
        mp[ord[i]] = i;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c, deck[i].first = mp[c], cin >> deck[i].second;
        tmp.insert(deck[i].second);
        cards[deck[i].second].push_back(deck[i].first);
    }
    for(char t : tmp)
        labels.push_back(t);
    int ans = INT_MAX;
    do{
        for(int mask = 0; mask < (1 << labels.size()); mask++){
            seq.clear();
            produce(mask);
            ans = min(ans, n - lis());
        }
    }while(next_permutation(labels.begin(), labels.end()));
    cout << ans << endl;   
}