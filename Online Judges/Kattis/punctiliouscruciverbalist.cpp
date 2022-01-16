/*
 * https://open.kattis.com/problems/punctiliouscruciverbalist
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[53][53];

struct candidate{
    int ind, row, col;
    char dir;
};

inline double check(candidate& cand){
    double k = 0, a = 0;
    int inci = 0, incj = 0;
    if(cand.dir == 'D')
        inci = 1;
    else
        incj = 1;
    int x = cand.row, y = cand.col;
    int ab = 0;
    while(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#')
        ab++, x += inci, y += incj;
    x = cand.row, y = cand.col;
    while(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#'){
        a += ab;
        if(g[x][y] == 'f')
            k += ab;
        ab--, x += inci, y += incj;
    }
    return k / a;
}

inline void filll(candidate & cand){
    int inci = 0, incj = 0;
    if(cand.dir == 'D')
        inci = 1;
    else
        incj = 1;
    int x = cand.row, y = cand.col;
    while(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#')
        g[x][y] = 'f', x += inci, y += incj;
}

int id = 0;
map<int, candidate> cands;
vector<int> trash;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] != '.' && g[i][j] != '#')
                g[i][j] = 'f';
        }
    int cnt = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(g[i][j] == '#')
                continue;
            bool up = false;
            if(i == 0)
                up = true;
            else if(g[i-1][j] == '#')
                up = true;
            bool left = false;
            if(j == 0)
                left = true;
            else if(g[i][j-1] == '#')
                left = true;
            if(up){
                candidate cand;
                cand.ind = cnt, cand.row = i, cand.col = j, cand.dir = 'D';
                cands[id++] = cand;               
            }
            if(left){
                candidate cand;
                cand.ind = cnt, cand.row = i, cand.col = j, cand.dir = 'A';
                cands[id++] = cand;
            }
            if(up || left)
                cnt++;
        }
    while(true){
        trash.clear();       
        double mx = -1;
        int mxid = -1;
        char mxdir;
        int mxind;
        for(auto cand : cands){
            double c = check(cand.second);
            if(c == 1.0)
                trash.push_back(cand.first);
            else if(c > mx)
                mx = c, mxid = cand.first, mxdir = cand.second.dir, mxind = cand.second.ind;
            else if(c == mx){
                if(cand.second.dir == mxdir){
                    if(cand.second.ind < mxind)
                        mx = c, mxid = cand.first, mxdir = cand.second.dir, mxind = cand.second.ind;                   
                }
                else if(cand.second.dir == 'A')
                    mx = c, mxid = cand.first, mxdir = 'A', mxind = cand.second.ind;
            }
        }
        if(mxid == -1)
            break;
        for(int t : trash)
            cands.erase(t);
        cout << cands[mxid].ind << cands[mxid].dir << endl;
        filll(cands[mxid]);
        cands.erase(mxid);       
    }   
}