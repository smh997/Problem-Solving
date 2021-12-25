/*
 * https://open.kattis.com/problems/paludarium
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

map<long long int, long long int> mp, mp2, mp3;
set<long long int> s;
long long int h, w;
long long int heights[500003];
long long int land = 0, water = 0, air = 0;

long long int judge(long long int hhh){
    auto it = s.upper_bound(hhh);
    it--;
    long long int wat = mp2[*it];
    if(*it != hhh){
        wat += (hhh - *it) * mp3[*it];
    }
    water = wat;
//    cerr << *it << " ";
//    cerr << mp3[*it] << " ";
//    cerr << wat << endl;
    return abs(wat - (air - wat));
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < w; ++i) {
        cin >> heights[i];
        land += heights[i];
        s.insert(heights[i]);
        if(mp.find(heights[i]) == mp.end()){
            mp[heights[i]] = 0;
        }
        mp[heights[i]]++;
    }
    if(s.find(0) == s.end()){
        s.insert(0);
        mp[0] = 0;
    }
    if(s.find(h) == s.end()){
        s.insert(h);
        mp[h] = w;
    }
    long long int azad = 0, alll = 0, pre = 0;
    for(pair<long long int, long long int> sss : mp){
       alll += azad * (sss.first - pre);
       mp2[sss.first] = alll;
       azad += sss.second;
       mp3[sss.first] = azad;
       pre = sss.first;
    }
//    for (auto kkkk : s) {
//        cout << kkkk << " ";
//    }
//    cerr << endl;
    air = w * h - land;
    long long int lo = 0, hi = h;
//    judge(1);
//    cerr << *s.lower_bound(1) << endl;
    while(lo < hi){
        long long int mid1 = lo + (hi - lo) / 3;
        long long int mid2 = hi - (hi - lo) / 3;
        long long int res1, res2;
        res1 = judge(mid1);
        res2 = judge(mid2);
//        cerr << mid1 << " " << res1 << " / " << mid2 << " " << res2 << endl; 
        if (res1 < res2) {
            hi = mid2-1;
        }
        else if(res1 > res2){
            lo = mid1 + 1;
        }
        else{
            hi = mid2-1;
        }
    }
    judge(lo);
    cout << lo << " " << water << endl;
    return 0;
}

