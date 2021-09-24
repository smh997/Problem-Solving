/*
 * https://open.kattis.com/problems/codecleanups
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;

int days[400];

int main(){
    for(int i = 1; i <= 365; i++)
        days[i] = 0;
    int n;
    cin >> n;
    int last_dirty_push = -1;
    int pushes = 0;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        days[d] = 1;
    }
    int cleanup = 0;
    for(int i = 1; i <= 365; i++){
        if(last_dirty_push != -1 && pushes * i - last_dirty_push >= 20){
            cleanup++;
            if(days[i]){
                last_dirty_push = i;
                pushes = 1;
            }
            else{
                last_dirty_push = -1;
                pushes = 0;
            }
        }
        else if(days[i] && last_dirty_push != -1){
            last_dirty_push += i;
            pushes++;
        }
        else if(days[i]){
            last_dirty_push = i;
            pushes = 1;
        }
    }
    if(last_dirty_push != -1){
        cleanup++;
    }
    cout << cleanup << endl;
    
}