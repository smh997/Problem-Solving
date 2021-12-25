/*
 * https://open.kattis.com/problems/retribution
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, p;
pair<int, int> judges[1003], repo[1003], house[1003];
bool judge_taken[1003], repo_taken[1003], house_taken[1003];

double dis_repo(int i, int k){
    return hypot(judges[i].first - repo[k].first, judges[i].second - repo[k].second);
}

double dis_house(int i, int k){
    return hypot(judges[i].first - house[k].first, judges[i].second - house[k].second);
}

int main(){
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++)
        cin >> judges[i].first >> judges[i].second;
    for(int i = 0; i < m; i++)
        cin >> repo[i].first >> repo[i].second;
    for(int i = 0; i < p; i++)
        cin >> house[i].first >> house[i].second;
    double sum = 0;
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
    for(int i = 0; i < n; i++)
        for(int k = 0; k < m; k++)
            pq.push({dis_repo(i, k), {i, k}});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        double d = x.first;
        int i = x.second.first, k = x.second.second;
        if(judge_taken[i] || repo_taken[k])
            continue;
        judge_taken[i] = repo_taken[k] = 1;
        sum += d;
    }
    fill_n(judge_taken, n, 0);
    for(int i = 0; i < n; i++)
        for(int k = 0; k < p; k++)
            pq.push({dis_house(i, k), {i, k}});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        double d = x.first;
        int i = x.second.first, k = x.second.second;
        if(judge_taken[i] || house_taken[k])
            continue;
        judge_taken[i] = house_taken[k] = 1;
        sum += d;
    }
    cout << fixed << setprecision(7) << sum << endl;
}