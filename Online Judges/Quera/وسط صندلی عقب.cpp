/*
 * https://quera.org/problemset/3412/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<string> q;
    string name;
    char ch;
    for(int i = 0; i < 4; i++){
        cin >> name >> ch;
        if(ch == 'L'){
            q.push_front(name);
        }
        else if(ch == 'R'){
            q.push_back(name);
        }
    }
    q.pop_front();
    cout << q.front() << endl;
    
    return 0;
}

