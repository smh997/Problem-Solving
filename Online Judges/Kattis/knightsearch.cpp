/*
 * https://open.kattis.com/problems/knightsearch
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string word = "ICPCASIASG";
bool seenword;
char grid[103][103];
int n;
bool seencell[103][103];
int dirx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int diry[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool inrange(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < n;
}

void travers(int i, int j, int step){
    if(step == word.length()){
        seenword = true;
        return;
    }
//    cerr << i << " " << j << " " << words[word_i] << " " << grid[i][j] << endl;
//    seencell[i][j] = true;
    for (int d = 0; d < 8; ++d) {
        if(inrange(i+diry[d], j + dirx[d]) && /*!seencell[i+diry[d]][j + dirx[d]] &&*/ grid[i+diry[d]][j + dirx[d]] == word[step]){
            travers(i+diry[d], j+dirx[d], step+1);
            if(seenword)
                return;
        }
    }
//    seencell[i][j] = false;
}

void clear(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            seencell[i][j] = false;
        }
    }
}

int main()
{
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[i*n+j];
//            cout<<grid[i][j];
        }
//        cout<<endl;
    }
    seenword = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(grid[i][j] == word[0]){
//                clear();                   
                travers(i, j, 1);
                if(seenword){
                    break;
                }
            }             
        }
        if(seenword)
            break;
    }
    if(seenword)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
