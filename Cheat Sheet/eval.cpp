#include <bits/stdc++.h>
using namespace std;

// encode and decode for unary - operator

string encode(string str){
    string en = "";
    en += (str[0] == '-') ? '#' : str[0];
    for(int i = 1; i < str.size(); i++){
        if(str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9') && !(str[i-1] >= '0' && str[i-1] <= '9'))
            en += '#';
        else 
            en += str[i];
    }
    return en;
}

string decode(string str){
    string de = "";
    for(char c : str){
        if(c == '#')
            de += '-';
        else de += c;
    }
    return de;
}

vector<string> tokenize(string str, char delim){
    stringstream ss(delim == '-' ? encode(str) : str);
    string token;
    vector<string> ans;
    while(getline(ss, token, delim))
        ans.push_back(delim == '-' ? decode(token) : token);
    return ans;
}

bool div_by_zero;

int eval1(string str){ // just with * and /
    int ans = 1;
    vector<string> t1 = tokenize(str, '*');
    for(string s : t1){
        vector<string> t2 = tokenize(s, '/');
        ans *= stoi(t2[0]);
        for(int i = 1; i < t2.size(); i++){
            int tmp = stoi(t2[i]);
            if(tmp)
                ans /= tmp;
            else div_by_zero = true;
        }
    }
    return ans;
}

int eval2(string str){ // with + - * /
    int ans = 0;
    vector<string> t1 = tokenize(str, '+');
    for(string s : t1){
        vector<string> t2 = tokenize(s, '-');
        if(t2[0] != "")
            ans += eval1(t2[0]);
        for(int i = 1; i < t2.size(); i++)
            ans -= eval2(t2[i]);
    }
    return ans;
}

int eval(string str){ // with () + - * /
    string ans = "";
    int i = 0;
    while(i < str.size()){
        if(str[i] == '('){
            int cnt = 1, j = i + 1;
            while(cnt){
                if(str[j] == '(')
                    cnt++;
                else if(str[j] == ')')
                    cnt--;
                j++;
            }
            ans += to_string(eval(str.substr(i+1, j-i-1)));
            i = j;
        }
        else
            ans += str[i], i++;
    }
    return eval2(ans);
}

int main(){
    string str;
    cin >> str;
    cout << eval(str) << endl;
}