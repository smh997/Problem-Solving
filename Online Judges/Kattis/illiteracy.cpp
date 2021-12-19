/*
 * https://open.kattis.com/problems/illiteracy
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

set<string> vis;
string s, t;

inline char rot(char ch){
    return (char)('A' + ((ch-'A') + 1)%6);
}

inline string build(string mains, char ch, int idx){
    string res = mains;
    switch(ch){
        case 'A':
            if(idx > 0){
                res[idx-1] = rot(res[idx-1]);
            }
            if(idx < 7){
                res[idx+1] = rot(res[idx+1]);
            }
            break;
        case 'B':
            if(idx > 0 && idx < 7){
                res[idx+1] = res[idx-1];
            }
            break;
        case 'C':
            res[7-idx] = rot(res[7-idx]);
            break;
        case 'D':
            if(idx != 0 && idx < 4){
                for (int i = 0; i < idx; ++i) {
                    res[i] = rot(res[i]);
                }
            }
            else if(idx != 7 && idx >3){
                for (int i = idx+1; i < 8; ++i) {
                    res[i] = rot(res[i]);
                }
            }
            break;
        case 'E':
            if(idx != 0 && idx < 4){
                int y = idx;
                res[idx+y] = rot(res[idx+y]);
                res[idx-y] = rot(res[idx-y]);
            }
            else if(idx != 7 && idx >3){
                int y = 7 - idx;
                res[idx+y] = rot(res[idx+y]);
                res[idx-y] = rot(res[idx-y]);
            }
            break;
        case 'F':
            if((idx+1)%2){
                res[((idx+1+9)/2)-1] = rot(res[((idx+1+9)/2)-1]);
            }
            else{
                res[((idx+1)/2)-1] = rot(res[((idx+1)/2)-1]);
            }
            break;
    }
    return res;
}

int main()
{
    cin >> s >> t;
    string tmp, newtmp;
    queue<pair<string, int>> q;
    q.push({s, 0});
    vis.insert(s);
    pair<string, int> p;
    while(!q.empty()){
        p = q.front(); q.pop();
        tmp = p.first;
        if(tmp == t)
            break;
        for (int i = 0; i < 8; ++i) {
            newtmp = build(tmp, tmp[i], i);
            if(vis.find(newtmp) == vis.end()){
                vis.insert(newtmp);
                q.push({newtmp, p.second+1});
            }
        }
    }
    cout << p.second << endl;
    return 0;
}

