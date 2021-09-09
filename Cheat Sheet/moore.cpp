#include <bits/stdc++.h>
using namespace std;

// Moore Algorithm to minimize the number of late jobs.

// O(n * logn)

#define num long long int

const int maxn = 1e5 + 3;
int n, m;
pair<num, num> interval[maxn]; // first: needed time, second: deadline

bool cmp(pair<num, num> & p1, pair<num, num> & p2){
    return p1.second < p2.second;
}

num moore(){
    priority_queue<num> pq;
    num t = 0;
    for(int i = 0; i < n; i++){
        num needed_time = interval[i].first;
        pq.push(needed_time);
        if(t + needed_time <= interval[i].second)
            t += needed_time;
        else{
            num p = pq.top();
            pq.pop();
            t = t - p + needed_time;
        }
    }
    return n - (int)pq.size();
}

int main(){
    // read the input
    sort(interval, interval + n, cmp);
    cout << moore() << endl;
}