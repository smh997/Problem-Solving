/*
 * https://open.kattis.com/problems/stringmultimatching
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200010
char T[MAX_N];
char P[MAX_N/2];
int n, m;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N]; // for counting/radix sort
void countingSort(int k) { 
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k); // actually radix sort: sort based on the second item
        countingSort(0); // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++) // compare adjacent suffixes
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;// if same pair => same rank r; otherwise, increase r                    
        for (i = 0; i < n; i++) // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1)
            break; // nice optimization trick
    }
}

pair<int, int> stringMatching() { // O(m log n)
    int lo = 0, hi = n-1, mid = lo;
    while (lo < hi) {
        mid = (lo + hi) / 2; 
        int res = strncmp(T + SA[mid], P, m);
        if (res >= 0)
            hi = mid; // prune upper half (notice the >= sign)
        else
            lo = mid + 1; // prune lower half including mid
    } // observe ‘=’ in "res >= 0" above
    if (strncmp(T + SA[lo], P, m) != 0)
        return {-1, -1}; // not found
    pair<int, int> ans; ans.first = lo;
    lo = 0; hi = n - 1; mid = lo;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if (res > 0)
            hi = mid; // prune upper half
        else
            lo = mid + 1; // prune lower half including mid
    } // (notice the selected branch when res == 0)
    if (strncmp(T + SA[hi], P, m) != 0) hi--; // special case
    ans.second = hi;
    return ans;
} // return lower/upperbound as first/second item of the pair, respectively

string pats[MAX_N/2];

int f;
int patsn[MAX_N/2];
string s;
int main() {
    while(cin >> f){
        getline(cin, s);
        for (int i = 0; i < f; ++i) {
            getline(cin, pats[i]);
            patsn[i] = pats[i].length();
        }
        cin.getline(T, MAX_N);
        n = (int)strlen(T); // input T as per normal, without the ‘$’
//        T[n++] = '$';
        constructSA();
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < patsn[i]; ++j) {
                P[j] = pats[i][j];
            }
            m = patsn[i];
            pair<int, int> pos = stringMatching();
            if (pos.first != -1 && pos.second != -1) {
                set<int> res;
                for (int o = pos.first; o <= pos.second; o++)
                    res.insert(SA[o]);
                for (int aaa: res) {
                    cout << aaa << " ";
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
