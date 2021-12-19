/*
 * https://open.kattis.com/problems/throwns
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<char, int>> v;
stack<int> st;

int main(){
    cin >> n >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    string x, y;
    stringstream ss(s);
    while(ss >> x){
        if(x == "undo"){
            ss >> y;
            v.push_back({'u', stoi(y)});
        }
        else
            v.push_back({'n', stoi(x)});
    }
    int size = v.size();
    int pre = 0;
    for(int i = 0; i < size; i++){
        char c = v[i].first;
        int d = v[i].second;
        if(c == 'n'){
            pre = (pre + d + 10000 * n) % n;
            st.push(pre);
        }
        if(c == 'u'){
            for(int k = 0; k < d; k++){
                if(!st.empty())
                    st.pop();
                else
                    break;
            }
            if(st.empty())
                pre = 0;
            else
                pre = st.top();
        }
    }
    cout << pre << endl;
}