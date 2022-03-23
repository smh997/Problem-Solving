/*
 * https://quera.org/problemset/8901/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;
    map<char, int> m;
    pair<char, int> p[3];
    p[0].first = 'L';
    p[0].second = 0;
    p[1].first = 'M';
    p[1].second = 0;
    p[2].first = 'R';
    p[2].second = 0;
    m.insert(p[0]);
    m.insert(p[1]);
    m.insert(p[2]);
    m[ch] = 1;
    char f, s;

    for (int i = 0; i < n; ++i) {
        cin >> f >> s;
        int temp = m[f];
        m[f] = m[s];
        m[s] = temp;
    }
    for (map<char, int>::iterator i = m.begin(); i != m.end(); i++) {
        if(i->second == 1)
            cout << i->first << endl;
    }
    return 0;
}

