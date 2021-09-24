/*
 * https://open.kattis.com/problems/connectthedots
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> mp;
vector<char> li;
char grid[103][103];
string s;

int main()
{
    for (int i = 0; i < 10; ++i) {
        li.push_back((char)('0'+i));
    }
    for (int i = 0; i < 26; ++i) {
        li.push_back((char)('a' + i));
    }
    for (int i = 0; i < 26; ++i) {
        li.push_back((char)('A' + i));
    }
    int row = 0;
    int col = 0;
    pair<int, int> targ, cur;
    while(getline(cin , s)){
        if(s.length() == 0){
            for (int i = 1; i < mp.size(); ++i) {
                cur = mp[li[i-1]];
                targ = mp[li[i]];
                if(cur.first == targ.first){
                    if(cur.second < targ.second){
                        for (int k = cur.second+1; k < targ.second; ++k) {
                            if(grid[cur.first][k] == '.'){
                                grid[cur.first][k] = '-';
                            }
                            else if(grid[cur.first][k] == '|'){
                                grid[cur.first][k] = '+';
                            }
                        }
                    }
                    else{
                        for (int k = targ.second+1; k < cur.second; ++k) {
                            if(grid[cur.first][k] == '.'){
                                grid[cur.first][k] = '-';
                            }
                            else if(grid[cur.first][k] == '|'){
                                grid[cur.first][k] = '+';
                            }
                        }
                    }
                }
                else{
                    if(cur.first < targ.first){
                        for (int k = cur.first+1; k < targ.first; ++k) {
                            if(grid[k][cur.second] == '.'){
                                grid[k][cur.second] = '|';
                            }
                            else if(grid[k][cur.second] == '-'){
                                grid[k][cur.second] = '+';
                            }
                        }
                    }
                    else{
                        for (int k = targ.first+1; k < cur.first; ++k) {
                            if(grid[k][cur.second] == '.'){
                                grid[k][cur.second] = '|';
                            }
                            else if(grid[k][cur.second] == '-'){
                                grid[k][cur.second] = '+';
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
            cout << endl;
            row = 0;
            mp.clear();
            continue;
        }
        col = s.length();
        for (int i = 0; i < s.length(); ++i) {
            grid[row][i] = s[i];
            if(s[i] != '.'){
                mp[s[i]] = {row, i};
            }
        }
        row++;
    }
    for (int i = 1; i < mp.size(); ++i) {
        cur = mp[li[i-1]];
        targ = mp[li[i]];
        if(cur.first == targ.first){
            if(cur.second < targ.second){
                for (int k = cur.second+1; k < targ.second; ++k) {
                    if(grid[cur.first][k] == '.'){
                        grid[cur.first][k] = '-';
                    }
                    else if(grid[cur.first][k] == '|'){
                        grid[cur.first][k] = '+';
                    }
                }
            }
            else{
                for (int k = targ.second+1; k < cur.second; ++k) {
                    if(grid[cur.first][k] == '.'){
                        grid[cur.first][k] = '-';
                    }
                    else if(grid[cur.first][k] == '|'){
                        grid[cur.first][k] = '+';
                    }
                }
            }
        }
        else{
            if(cur.first < targ.first){
                for (int k = cur.first+1; k < targ.first; ++k) {
                    if(grid[k][cur.second] == '.'){
                        grid[k][cur.second] = '|';
                    }
                    else if(grid[k][cur.second] == '-'){
                        grid[k][cur.second] = '+';
                    }
                }
            }
            else{
                for (int k = targ.first+1; k < cur.first; ++k) {
                    if(grid[k][cur.second] == '.'){
                        grid[k][cur.second] = '|';
                    }
                    else if(grid[k][cur.second] == '-'){
                        grid[k][cur.second] = '+';
                    }
                }
            }
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

