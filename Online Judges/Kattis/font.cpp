/*
 * https://open.kattis.com/problems/font
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int n;
int wordMasks[30];
int revsumMask[30];
const int targ = (1 << 26) - 1;
long long int res = 0;

void backtrack(int i, int mask){
//    cerr << i << " " << mask << endl;
    if(i == n){
        if(mask == targ){
            res++;
        }
        return;
    }
    if(revsumMask[i+1] | mask == targ)
        backtrack(i+1, mask);
    backtrack(i+1, mask | wordMasks[i]);
}

string s;

int main()
{
    cerr << targ << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            wordMasks[i] |= (1 << (s[j]-'a'));
        }
    }
    revsumMask[n-1] = wordMasks[n-1];
    for (int i = n-2; i >= 0; i--) {
        revsumMask[i] = revsumMask[i+1] | wordMasks[i];
    }
//    cerr << revsumMask[0] << endl;
//    for (int i = 0; i < n; ++i) {
//        cerr << wordMasks[i] << endl;
//    }
    backtrack(0, 0);
    cout << res << endl;
    return 0;
}

