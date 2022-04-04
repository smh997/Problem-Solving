/*
 * https://open.kattis.com/problems/uxuhulvoting
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
int pref[103][8];
int dp[103][8];

int main(){
    cin >> n;
    while(n--){
        cin >> m;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < 8; j++){   
                cin >> pref[i][j];
                pref[i][j]--;
            }
        }
        for (int mask = 0; mask < 8; mask++)
            dp[m][mask] = mask;
        for (int i = m-1; i >= 0; i--){
            for (int mask = 0; mask < 8; mask++){
                int mi = 8, act = 0;
                for (int b = 0; b < 3; b++){
                    int place = pref[i][dp[i + 1][(mask ^ (1 << b))]];
                    if (place < mi){
                        mi = place;
                        act = b;
                    }
                }
                dp[i][mask] = dp[i+1][(mask ^ (1 << act))];
            }
        }
        for (int b = 2; b >= 0; b--){
            if (dp[0][0] & (1 << b))
                cout << "Y";
            else
                cout << "N";
        }
        cout << endl;
    }
    return 0;
}