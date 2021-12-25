/*
 * https://open.kattis.com/problems/peggamefortwo
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

map<pair<string, int>, int> dp;
map<pair<int, int>, int> c2p;
pair<int, int> p2c[15];
int arr[15];
int mvx[6] = {-2, 0, 2, 0, 2, -2};
int mvy[6] = {0, -2, 0, 2, 2, -2};
int mvx2[6] = {-1, 0, 1, 0, 1, -1};
int mvy2[6] = {0, -1, 0, 1, 1, -1};

int cdp(string s, int turn){
    if(dp.find({s, turn})!= dp.end()){
        return dp[{s,turn}];
    }
    int res;
    if(turn)res = INT_MAX;
    else res = INT_MIN;
    int cx, cy;
    string t = s;
    stringstream ss(s);
    for (int i = 0; i < 15; ++i) {
        ss>>arr[i];
    }
    
    for (int j = 0; j < 15; ++j) {
        if(arr[j]==0){
            cx = p2c[j].first;
            cy = p2c[j].second;
            for (int i = 0; i < 6; ++i) {
                if(cx+mvx[i]>=0 && cx+mvx[i]<=4 && cy+mvy[i]>=0 && cy+mvy[i]<=cx+mvx[i]){
                    int p1x,p2x,p1y,p2y, p1, p2;
                    p1x = cx + mvx2[i],p2x = cx + mvx[i],p1y = cy + mvy2[i], p2y = cy + mvy[i];
                    p1 = c2p[{p1x, p1y}];
                    p2 = c2p[{p2x, p2y}];
//                    cout<<s<<"/ "<<j<<" ("<<p1x<<","<<p1y<<") ("<<p2x<<","<<p2y<<") "<<p1<<" "<<p2<<" "<<arr[p1]<<" "<<arr[p2]<<endl;
                    
                    if((arr[p1]!=0) && (arr[p2]!=0)){
//                        cout<<"yes "<<j<<" "<<p1<<","<<p2<<" "<<arr[p1]*arr[p2]<<" /"<<s<<endl;
                        int t1 = arr[p1], t2 = arr[p2];;
                        arr[j] = arr[p2];
                        arr[p1] = 0;
                        arr[p2] = 0;
                        string tmp="";
                        for (int k = 0; k < 15; ++k) {
                            tmp += to_string(arr[k]);
                            if(k!=14) tmp += " ";
                        }
                        if(turn) res = min(res, -t1*t2+cdp(tmp, 0));
                        else res = max(res, t1*t2+cdp(tmp, 1));
                        arr[j] = 0;
                        arr[p1] = t1;
                        arr[p2] = t2;
                    }
                }
            }
        }
    }
    
    return dp[{t, turn}] = (res == INT_MAX || res == INT_MIN) ? 0 : res;
}

int main()
{
    int pp = 0;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j <= i; ++j) {
            p2c[pp] = make_pair(i, j);
            c2p[p2c[pp]] = pp;
            pp++;
        }
    }
    for (int i = 0; i < 15; ++i) {
        cin>>arr[i];
    }
    string s = "";
    for (int i = 0; i < 15; ++i) {
        s += to_string(arr[i]);
        if(i!=14) s += " ";
    }
    cout<<cdp(s, 0)<<endl;
    return 0;
}

