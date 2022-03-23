/*
 * https://quera.org/problemset/3433/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

#define num long long int

num arr[(1 << 17) + 3], n;

num dc(num l, num r){
    if (l == r){
        return arr[l];
    }
    num resl, resr;
    num mid = (l + r)/2;
    resl = dc(l, mid);
    resr = dc(mid + 1, r);
    if (resl <= resr)
        return resr + *max_element(arr + l, arr + mid + 1);
    else
        return resl + *max_element(arr + mid + 1, arr + r + 1);
}

int main()
{
    cin >> n;
    n = 1 << n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cout << dc(0, n - 1) << endl;
    
    return 0;
}

