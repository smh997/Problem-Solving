/*
 * https://open.kattis.com/problems/cyaniderivers
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string arr;
    cin >> arr;
    int n = arr.size();
    vector<int> start_indices;
    vector<int> dist(n, n);

    for (int i = 0; i < n; i++) {
        if(arr[i] == '1') {
            start_indices.push_back(i);
        }
    }
    queue<int> q;
    for (int start : start_indices) {
        dist[start] = 0;
        q.push(start);
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr - 1 >= 0 && dist[curr - 1] > dist[curr] + 1) {
            q.push(curr - 1);
            dist[curr - 1] = dist[curr] + 1;
        }
        if(curr + 1 < n && dist[curr + 1] > dist[curr] + 1) {
            q.push(curr + 1);
            dist[curr + 1] = dist[curr] + 1;
        }
    }
    int result = 0;
    for (int d : dist) {
        result = max(result, d);
    }
    cout << result << endl;
}
