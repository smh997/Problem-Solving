/*
 * https://open.kattis.com/problems/mathhomework
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool flag = true;
    int a, b, c, L;
    cin>>a>>b>>c>>L;
    for (int i = 0; i <= L/a; ++i)
        for (int j = 0; j <= (L-i*a)/b; ++j)
            for (int k = 0; k <= (L-i*a-j*b)/c; ++k)
                if(i*a+j*b+k*c==L)
                    flag = false, cout<<i<<" "<<j<<" "<<k<<endl;
    if(flag)
        cout<<"impossible"<<endl;
    return 0;
}

