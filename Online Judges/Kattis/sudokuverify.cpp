/*
 * https://open.kattis.com/problems/sudokuverify
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n = 9;
bool check(unordered_set<int>& s, int ch){
    if(s.find(ch) != s.end())
        return true;
    s.insert(ch);
    return false;
}
bool isValidSudoku(vector<vector<int>>& board) {
    unordered_set<int> cols[9];
    unordered_set<int> sqs[9];
    for(int i = 0; i < n; i++){
        unordered_set<int> row; 
        for(int j = 0; j < n; j++){
            int ch = board[i][j];
            if(check(row, ch) || check(cols[j], ch) || check(sqs[i/3*3+j/3], ch))
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> board[i][j];
    cout << (isValidSudoku(board) ? "VALID" : "INVALID!") << endl;
    
    return 0;
}
