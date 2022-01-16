/*
 * https://open.kattis.com/problems/ummcode
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string code = "";

string check(string s){
    string t = "";
    for(char c : s)
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            if(!(c == 'u' || c == 'm'))
                return "N";
            t += c;
        }
    return t;
}

char interpret(string s){
    int num = 0, mul = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'u')
            num += mul;
        mul *= 2;
    }
    return num;
}

int main(){
    string word;
    while(cin >> word){
        string st = check(word);
        if(st != "N")
            code += st;
    }
    for(int i = 0; i < code.size(); i+=7)
        cout << interpret(code.substr(i, 7));
    cout << endl;   
}