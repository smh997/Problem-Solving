/*
 * https://open.kattis.com/problems/explodingkittens
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

// Exploding Kittens

int N, E, D;
int id[1003], de[1003], e[10003], d[10003];
int last = 0, card = 0;

void pe(int i){
    int pl = ((i - card) % N + last) % N;
    if(de[pl])
        de[pl]--;
    else{
        for(int j = pl; j < N - 1; j++){
            id[j] = id[j+1];
            de[j] = de[j+1];
        }
        last = pl == N - 1 ? 0 : pl;
        card = i + 1;
        N--;
    }
}

void pd(int i){
    int pl = ((i - card) % N + last) % N;
    de[pl] = min(5, de[pl]+1);
}

int main(){
    cin >> N >> E >> D;
    for(int i = 0; i < E; i++)
        cin >> e[i];
    sort(e, e + E);
    for(int i = 0; i < D; i++)
        cin >> d[i];
    sort(d, d + D);
    iota(id, id+N, 0);
    fill_n(de, N, 0);
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < E || ptr2 < D){
        if(N == 1 || ptr1 == E)
            break;
        if(ptr2 == D)
            pe(e[ptr1++]);
        else if(e[ptr1] < d[ptr2])
            pe(e[ptr1++]);
        else
            pd(d[ptr2++]);
    }
    if(N == 1)
        cout << id[0] << endl;
    else cout << -1 << endl;
}