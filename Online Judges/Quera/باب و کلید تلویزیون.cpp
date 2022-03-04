/*
 * https://quera.org/problemset/14580/
 * Author: https://github.com/smh997/
 */

#include <iostream>
#include<queue>
using namespace std;

int main()
{
    queue<string> q;
    int n, x, k;
    cin >> n >> x >> k;
    string y;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        q.push(y);
    }
    for (int i = 0; i < x + k - 1; ++i) {
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}

