/*
 * https://quera.org/problemset/69903/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if(m1 == m2){
        cout << abs(d2 - d1) << endl;
        return 0;
    }
    if(m1 > m2){
        int tmpm, tmpd;
        tmpm = m1;
        m1 = m2;
        m2 = tmpm;
        tmpd = d1;
        d1 = d2;
        d2 = tmpd;
    }
    if(m2 < 7){
        cout << d2 + (31 - d1) + ((m2 - m1 > 1) ? (m2 - m1 - 1) * 31 : 0) << endl;
    }
    else if(m1 > 6){
        cout << d2 + (30 - d1) + ((m2 - m1 > 1) ? (m2 - m1 - 1) * 30 : 0) << endl;
    }
    else{
        cout << d2 + (m2-7) * 30 + (31 - d1) + (6 - m1) * 31 << endl;
    }
    return 0;
}

