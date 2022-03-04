/*
 * https://quera.org/problemset/2534/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n], sum = 0, mid, res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    mid = sum / n;
    for (int i = 0; i < n; ++i) {
        if(arr[i] > mid){
            res += arr[i] - mid;
        }
    }
    cout << res << endl;
    return 0;
}

