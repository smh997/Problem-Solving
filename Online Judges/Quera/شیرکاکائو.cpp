/*
 * https://quera.org/problemset/6395/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    long long int s = 0, n = 0;
    int m;
    cin >> m;
    long long int arr[100003];
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
        if(arr[i] > 0){
            if(s >= arr[i]){
                s -= arr[i];
            }
            else{
                n += arr[i] - s;
                s = 0;
            }
        }
        else if(arr[i] < 0){
            s += -arr[i];
        }
    }
    cout << n << endl;
    return 0;
}

