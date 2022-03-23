/*
 * https://quera.org/problemset/10636/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> arr;
    int n;
    int max = 1;
    string str1, str2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        if(arr.find(str1) != arr.end()){
            arr.at(str1)++;
            if(max < arr.at(str1))
                max = arr.at((str1));
        }
        else{
            arr.insert(pair<string, int>(str1, 1));
        }
    }
    cout << max << endl;
    return 0;
}
