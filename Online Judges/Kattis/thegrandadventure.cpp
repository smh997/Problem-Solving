/*
 * https://open.kattis.com/problems/thegrandadventure
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t;
string line;

int main(){
    cin >> t;
    while(t--){
        cin >> line;        
        stack<char> st;
        bool res = 1;
        for (int i = 0; i < line.length(); ++i) {
            bool flag = 1;
            switch(line[i]){
                case '.':
                    flag = 0;
                    break;
                case '$':
                    st.push('b');
                    flag = 0;
                    break;
                case '|':
                    st.push('t');
                    flag = 0;
                    break;
                case '*':
                    st.push('j');
                    flag = 0;
                    break;
            }
            if(!flag) 
                continue;
            if(!st.empty() && st.top() == line[i]){
                st.pop();
            }
            else{
                res = 0;
                break;
            }
        }
        cout << ((st.empty() && res) ? "YES" : "NO") << endl;
    }
    return 0;
}
