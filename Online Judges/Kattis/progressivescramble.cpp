/*
 * https://open.kattis.com/problems/progressivescramble
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
string line;

int v[83];

string encrypt(string code){
    v[0] = (code[0] == ' ') ? 0 : (code[0] - 'a' + 1);
    for(int i = 1; i < code.size(); i++)
        v[i] = v[i-1] + ((code[i] == ' ') ? 0 : (code[i] - 'a' + 1));
    for(int i = 0; i < code.size(); i++)
        v[i] %= 27;
    string ans = "";
    for(int i = 0; i < code.size(); i++){
        if(v[i])
            ans += char(v[i] + 'a' - 1);
        else
            ans += " ";
    }
    return ans;
}

string decrypt(string code){
    for(int i = 0; i < code.size(); i++)
        v[i] = (code[i] == ' ') ? 0 : (code[i] - 'a' + 1);
    string ans = "";
    if(v[0])
        ans += char(v[0] + 'a' - 1);
    else
        ans += " ";
    for(int i = 1; i < code.size(); i++){
        int a = v[i-1] % 27;
        int b = v[i];
        int c = (b >= a) ? (b - a) : (27 - a + b);
        if(c)
            ans += char(c + 'a' - 1);
        else
            ans += " ";
        v[i] = v[i-1] + c;
    }
    return ans;
}

int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, line);
        char c = line[0];
        if(c == 'e')
            cout << encrypt(line.substr(2, line.size() - 2)) << endl;
        else
            cout << decrypt(line.substr(2, line.size() - 2)) << endl;
    }
}