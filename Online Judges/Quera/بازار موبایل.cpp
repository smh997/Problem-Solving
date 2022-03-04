/*
 * https://quera.org/problemset/3415/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    bool flag = true;
    int p[n], q[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> q[i];
    }
    for (int i = 0; i < n; ++i) {
        flag = true;
        for (int j = 0; j < n; ++j) {
            if(i == j) 
                continue;
            if(p[i] >= p[j] && q[i] <= q[j]){
                flag = false;
            }
        }
        if(flag)
            res++;
    }
    cout << res << endl;
    return 0;
}

