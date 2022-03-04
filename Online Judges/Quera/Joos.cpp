"""
https://quera.org/problemset/18310/
Author: https://github.com/smh997/
"""
#include <iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> q;
    string s, p;
    cin >> s >> p;
    for (unsigned int i = 0; i < s.length(); ++i) {
        q.push(s[i]);
    }

    bool flag = false;
    unsigned int i;
    int res = 0;
    for (i = 0; i < p.length(); ++i) {
        if(q.front() == p[i]){
            flag = true;
        }
        else if(flag){
            flag=false;
            i = -1;
            if(++res == 1000){
                cout << "No" << endl;
                return 0;
            }
        }
        else{

            i = -1;
            if(++res == 1000){
                cout << "No" << endl;
                return 0;
            }
        }
        q.push(q.front());
        q.pop();
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

