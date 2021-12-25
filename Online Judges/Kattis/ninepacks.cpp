/*
 * https://open.kattis.com/problems/ninepacks
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100003
int dph[103][MAX_N], dpb[103][MAX_N];
int H[103], B[103], h, b;


int cdph(int i, int w){
    if(dph[i][w] != -1)
        return dph[i][w];
    if(i==h){
        if(!w)
            return dph[i][w] = 0;
        return dph[i][w] = INT_MAX;
    }
    dph[i][w] = cdph(i+1, w);
    if(w>=H[i] && cdph(i+1, w-H[i]) != INT_MAX)
        dph[i][w] = min(dph[i][w], cdph(i+1, w-H[i])+1);
    return dph[i][w];
}

int cdpb(int i, int w){
    if(dpb[i][w] != -1)
        return dpb[i][w];
    if(i==b){
        if(!w)
            return dpb[i][w] = 0;
        return dpb[i][w] = INT_MAX;
    }
    dpb[i][w] = cdpb(i+1, w);
    if(w>=B[i] && cdpb(i+1, w-B[i]) != INT_MAX)
        dpb[i][w] = min(dpb[i][w], cdpb(i+1, w-B[i])+1);
    return dpb[i][w];
}

int main()
{
    for (int i = 0; i < 103; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            dph[i][j] = -1;
            dpb[i][j] = -1;
        }
    }
    cin>>h;
    int sumh=0, sumb = 0;
    for (int i = 0; i < h; ++i)
        cin>>H[i], sumh+=H[i];
    cin>>b;
    for (int i = 0; i < b; ++i)
        cin>>B[i], sumb+=B[i];
    int mi = min(sumh, sumb), res = INT_MAX;
    for (int i = 1; i <= mi; ++i) {
        if(cdph(0, i)!=INT_MAX && cdpb(0, i)!=INT_MAX)
            res = min(res, cdph(0, i)+cdpb(0, i));
    }
    cout<<((res!=INT_MAX)?to_string(res):"impossible")<<endl;
    return 0;
}

