/*
 * https://quera.org/problemset/6374/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int i = str.length() - 1; i >= 0; i--) {
        if(str[i] == 'F'){
            str[i] = '0';
            if(i == 0){
                str = '1' + str;
            }
        }
        else{
            switch (str[i]) {
                case '9':
                    str[i] = 'A';
                    break;
                case 'A' :
                    str[i] = 'B';
                    break;
                case 'B':
                    str[i] = 'C';
                    break;
                case 'C' :
                    str[i] = 'D';
                    break;
                case 'D' :
                    str[i] = 'E';
                    break;
                case 'E' :
                    str[i] = 'F';
                    break;
                default:
                    str[i]++;
                    break;
            }
            break;
        }
    }
    cout << str << endl;
    return 0;
}
