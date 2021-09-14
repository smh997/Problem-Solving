/*
 * https://open.kattis.com/problems/workstations
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n, m;
pair<int, int> arr[300003];
int a, s;
int main()
{
    int res = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>a>>s;
        arr[i] = {a, s};
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; ++i) {
        while(!pq.empty()){
            int topp = pq.top();
            if(topp + m < arr[i].first)
                pq.pop();
            else{
                break;
            }
        }
        if(pq.empty()){
            pq.push(arr[i].first + arr[i].second);
        }
        else{
            int topp = pq.top();
            if(topp <= arr[i].first){
                res++;
                pq.pop();
            }
            pq.push(arr[i].first + arr[i].second);
        }
    }
    cout<<res<<endl;
    
    return 0;
}

