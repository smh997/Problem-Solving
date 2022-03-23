/*
 * https://quera.org/problemset/9021/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include<set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    int arr[100003], onoff[100003];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> onoff[i];
        if(onoff[i] == 1)
            s.insert(arr[i]);
    }
    for (set<int>::iterator i = s.begin();  i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}

