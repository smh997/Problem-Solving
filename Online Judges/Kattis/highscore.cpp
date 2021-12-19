/*
 * https://open.kattis.com/problems/highscore
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int t;
string s, srev;
set<int> sr, sl;

int calc_change_pos(int i, bool r){
    if (r) {
        auto nxt = sr.upper_bound(i);
        if (nxt == sr.end())
            return i;
        return i + (s.length() - (*nxt - i));
    }
    auto nxt = sl.upper_bound(i);
    if (nxt == sl.end())
        return i;
    return i + (s.length() - (*nxt - i));
}


int main()
{
    cin >> t;
    while (t--) {
       cin >> s;
       srev = s; reverse(srev.begin()+1, srev.end());
       sr.clear();
       sl.clear();
       int change_pos = s.length();
       int change_char = 0;
       for (int i = 0; i < s.length(); ++i) {
           if (i != 0 && s[i] != 'A')
               sr.insert(i);
           if (i != 0 && srev[i] != 'A')
               sl.insert(i);
           change_char += min(s[i] - 'A', 'Z' - s[i] + 1);
       }
       if(sr.empty()){
           cout << change_char << endl;
           continue;
       }
       for (auto it = sr.begin(); it != sr.end(); ++it) 
           change_pos = min(change_pos, calc_change_pos(*it, true));
       for (auto it = sl.begin(); it != sl.end(); ++it) 
           change_pos = min(change_pos, calc_change_pos(*it, false));
       
       cout << change_char + change_pos << endl;
    }
    return 0;
}

