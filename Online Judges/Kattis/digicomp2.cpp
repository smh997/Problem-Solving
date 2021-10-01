/*
 * https://open.kattis.com/problems/digicomp2
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 5e5 + 3;

num b, balls[maxn];
int n, indeg[maxn], le[maxn], ri[maxn];
char state[maxn];
queue<int> kahn;

int main(){
    cin >> b >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> state[i] >> x >> y, le[i] = x-1, ri[i] = y-1;
        if(x)
            indeg[x-1]++;
        if(y)
            indeg[y-1]++;
    }
    balls[0] = b;
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        num leb = balls[u] / 2, rib = leb;
        if(balls[u] % 2){
            if(state[u] == 'L')
                leb++;
            else
                rib++;
            state[u] = (state[u] == 'L') ? 'R' : 'L';
        }
        if(le[u] != -1){
            balls[le[u]] += leb;
            indeg[le[u]]--;
            if(!indeg[le[u]])
                kahn.push(le[u]);
        }
        if(ri[u] != -1){
            balls[ri[u]] += rib;
            indeg[ri[u]]--;
            if(!indeg[ri[u]])
                kahn.push(ri[u]);
        }
    }
    for(int i = 0; i < n; i++)
        cout << state[i];
    cout << endl;
}