/*
 * https://quera.org/problemset/2551/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    string a,b;
    char c;
    cin >> a >> c >> b;
    if(c == '*'){
        cout << 1;
        for (int i = 0; i < a.length() + b.length() - 2; ++i) {
            cout << 0;
        }
    }
    else{
        if(a.length() == b.length()){
            cout << 2;
            for (int i = 0; i < a.length() - 1; ++i) {
                cout << 0;
            }
        }
        else{
            cout << 1;
            for (int i = 0; i < ((a.length() > b.length()) ? a.length() - b.length() : b.length() - a.length()) - 1; ++i) {
                cout << 0;
            }
            cout << 1;
            for (int i = 0; i < min(a.length(), b.length()) - 1; ++i) {
                cout << 0;
            }
        }
    }
    cout << endl;
    return 0;
}

