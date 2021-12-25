/*
 * https://open.kattis.com/problems/pebblesolitaire
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int cdp(string s){
    if(mp.find(s)!=mp.end())
        return mp[s];
    int res = 0;
    for (int i = 0; i < 12; ++i)
        if(s[i]=='o')
            res++;
    if(res==1){
        mp[s] = 1;
        return res;
    }
    for (int i = 0; i < 10; ++i) {
        if(s[i]==s[i+1] && s[i]=='o' && s[i+2]=='-')
            res = min(res, cdp(s.substr(0,i)+"--o"+((i+3<12)?s.substr(i+3,12-(i+3)):"")));
        if(s[i+2]==s[i+1] && s[i]=='-' && s[i+2]=='o')
            res = min(res, cdp(s.substr(0,i)+"o--"+((i+3<12)?s.substr(i+3,12-(i+3)):"")));
    }
    mp[s] = res;
    return res;
}
int main()
{
    int n;
    string ss;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>ss;
        cout<<cdp(ss)<<endl;
    }
    return 0;
}