/*
 * https://quera.org/problemset/10327/
 * Author: https://github.com/smh997/
 */
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string t, b, c;
    cin >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> b;
        bool ok = true;
        for(int i = 0; i < b.length(); i++)
        {
                if(t.find(b[i]) == -1)
                {
                    ok = false;
                    cout << "No" << endl;
                    break;
                }
        }
        if(ok)
        {
            for(int i = 0; i < t.length(); i++)
            {
                if(b.find(t[i]) == -1)
                {
                    ok = false;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if(ok)
        {
            cout << "Yes" << endl;
        }
    }
}
