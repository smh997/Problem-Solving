/*
 * https://open.kattis.com/problems/easierdonethansaid
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string pw;
    while (cin >> pw) {
        if (pw == "end") 
            break;

        bool hasVowel = false;
        bool tripleBad = false;
        bool doubleBad = false;

        for (int i = 0; i < pw.length(); i++) {
            if (isVowel(pw[i])) 
                hasVowel = true;
            if (i >= 2) {
                bool a = isVowel(pw[i]), b = isVowel(pw[i-1]), c = isVowel(pw[i-2]);
                if ((a && b && c) || (!a && !b && !c))
                    tripleBad = true;
            }

            if (i >= 1 && (pw[i] == pw[i-1] && !(pw[i] == 'e' && pw[i-1] == 'e') && !(pw[i] == 'o' && pw[i-1] == 'o'))) {
                doubleBad = true;
            }
        }

        if (hasVowel && !tripleBad && !doubleBad)
            cout << "<" << pw << "> is acceptable." << endl;
        else
            cout << "<" << pw << "> is not acceptable." << endl;
    }
    return 0;
}
