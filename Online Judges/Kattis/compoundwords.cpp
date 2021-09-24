/*
 * https://open.kattis.com/problems/compoundwords
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

set<string> ss;
set<string> ans;
string s;
int main()
{
    while(cin>>s)
        ss.insert(s);
    for (auto it = ss.begin(); it!=ss.end(); it++) {
        for (auto it2 = ss.begin(); it2!=ss.end(); it2++) {
            if(it==it2)continue;
            ans.insert(*it+*it2);
        }
    }
    auto it = ans.begin();
    while(it != ans.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}

