
/*
 * https://open.kattis.com/problems/touchdown
 * Author: https://github.com/smh997/
 */


#include <bits/stdc++.h>
using namespace std;

int yards[20];
int N;
int totsum = 20, sum = 0;
bool first_down = 1;
int ind = 0;

int main(){
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> yards[i];
        sum += yards[i];
        totsum += yards[i];
        if(sum >= 10){
            ind = -1;
            sum = 0;
        }
        else if(ind == 3 && sum < 10){
            first_down = 0;
            ind = -1;
        }
        if(totsum == 0){
            cout << "Safety" << endl;
            return 0;
        }
        if(totsum >= 100 && first_down){
            cout << "Touchdown" << endl;
            return 0;
        }
        ind++;
    }
    cout << "Nothing" << endl;
    return 0;
}
