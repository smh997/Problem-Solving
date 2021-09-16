/*
 * https://open.kattis.com/problems/boggle
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

//set<string> words, seen, feasable;
string words[300003];
bool seenword [300003];
char grid[5][5];
int w, b;
int mscore, longest, nwords;
set<string> lword;
bool seencell[5][5];
int dirx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int diry[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
map<int, int> score = {{3, 1}, {4, 1}, {5, 2}, {6, 3}, {7, 5}, {8, 11}};

bool inrange(int i, int j){
    return 0 <= i && i < 4 && 0 <= j && j < 4;
}

void travers(int i, int j, int word_i, int step){
    if(step == words[word_i].length()){
        mscore += score[step];
        nwords++;
        if(longest < step){
            lword.clear();
            lword.insert(words[word_i]);
            longest = step;
        }
        else if (longest == step){
            lword.insert(words[word_i]);
            longest = step;
        }
        seenword[word_i] = true;
        return;
    }
//    cerr << i << " " << j << " " << words[word_i] << " " << grid[i][j] << endl;
    seencell[i][j] = true;
    for (int d = 0; d < 8; ++d) {
        if(inrange(i+diry[d], j + dirx[d]) && !seencell[i+diry[d]][j + dirx[d]] && grid[i+diry[d]][j + dirx[d]] == words[word_i][step]){
            travers(i+diry[d], j+dirx[d], word_i, step+1);
            if(seenword[word_i])
                return;
        }
    }
    seencell[i][j] = false;
}

void clear(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            seencell[i][j] = false;
        }
    }
}

int main()
{
    string s;
    cin >> w;
    for (int i = 0; i < w; ++i) {
        cin >> s;
        words[i] = s;
    }
    cin >> b;
    while(b--){
        mscore = longest = nwords = 0;
        fill_n(seenword, w+1, false);
        lword.clear();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> grid[i][j];
            }
        }
        bool flag = false;
        for (int word_i = 0; word_i < w; ++word_i) {
            flag = false;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if(grid[i][j] == words[word_i][0]){
                        clear();                   
                        travers(i, j, word_i, 1);
                        if(seenword[word_i]){
                            flag = true;
                            break;
                        }
                    }                    
                }
                if(flag)
                    break;
            }
        }
        
        cout << mscore << " " << *lword.begin() << " " << nwords << endl;
    }
    return 0;
}
/*
5
ICPC
ACM
CONTEST
GCPC
PROGRAMM

1
ACMA
APCA
TOGI
NEST
*/
