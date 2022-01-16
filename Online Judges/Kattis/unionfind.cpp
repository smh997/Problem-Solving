/*
 * https://open.kattis.com/problems/unionfind
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000003

int parent[MAX_N];
int raank[MAX_N];

void initSets(int n){
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        raank[i] = 0;
    }
}

int findSet(int i){
    if(parent[i] == i) return i;
    return parent[i] = findSet(parent[i]);
}

inline bool inSameSets(int i, int j){
    return findSet(i) == findSet(j);
}

void mergeSets(int i, int j){
    int a = findSet(i);
    int b = findSet(j);

    if(a == b) return;

    if(raank[a] >= raank[b]){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
    if(raank[a] == raank[b])
        raank[a]++;

}

int N, Q;

int main(){
    scanf("%d %d", &N, &Q);
    initSets(N);
    for (int k = 0; k < Q; ++k) {
        char x[1];
        int i;
        int j;
        scanf("%s %d %d", x, &i, &j);
        if(x[0] == '?'){
            printf(inSameSets(i, j) ? "yes\n" : "no\n");
        }
        else if(x[0] == '='){
            mergeSets(i, j);
        }
    }
}
