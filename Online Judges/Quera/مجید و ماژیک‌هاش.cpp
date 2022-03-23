/*
 * https://quera.org/problemset/9109/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int n, arr[101], min = 101, imin, a;
    for (int i = 1; i < 101; ++i) {
        arr[i] = 0;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        arr[a]++;
    }
    for (int i = 1; i < 101; ++i) {
        if(arr[i] < min && arr[i] > 0){
            min = arr[i];
            imin = i;
        }
    }
    cout << imin << endl;
    return 0;
}

