/*
 * https://open.kattis.com/problems/taxededitor
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define EPS 1e-18
const int maxn = 1e5 + 3;
int n, m;
pair<num, num> interval[maxn]; // first: needed time, second: deadline

bool cmp(pair<num, num> p1, pair<num, num> p2){
    return p1.second < p2.second;
}

bool moore(num sp){
    priority_queue<long double> pq;
    long double t = 0;
    for(int i = 0; i < n; i++){
        long double needed_time = (long double)interval[i].first / sp;
        pq.push(needed_time);
        if(t + needed_time < (long double)interval[i].second || fabs(t + needed_time - (long double)interval[i].second) < EPS)
            t += needed_time;
        else{
            long double p = pq.top();
            pq.pop();
            t = t - p + needed_time;
        }
    }
    return n - (int)pq.size() <= m;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> interval[i].first >> interval[i].second;
    sort(interval, interval + n, cmp);
    num lo = 1, hi = 1e14, mid;
    while(lo < hi){
        mid = (hi + lo)/2;
        if(moore(mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    cout << lo << endl;
    return 0;
}
