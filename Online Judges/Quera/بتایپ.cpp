/*
 * https://quera.org/problemset/28948/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '='){
            if(i > 0){
                s.erase(s.begin() + i - 1, s.begin() + i + 1);
                i -= 2;
            }
            else{
                s.erase(s.begin() + i, s.begin() + i + 1);
                i--;
            }
        }
    }
    cout << s << endl;
    return 0;
}

