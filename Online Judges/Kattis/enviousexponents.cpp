/*
 * https://open.kattis.com/problems/enviousexponents
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

long long int n, k;
char arr[65];
int main()
{
    for (int i = 0; i < 64; ++i) {
        arr[i] = '0';
    }
    cin >> n >> k;
    int it = 0, cnt = 0, it2 = 0, cnt2;
    long long int m = n;
    while(m){
        arr[it] = (m % 2)?'1':'0';
        if(arr[it] == '1')
            cnt++;
        m /= 2;
        it++;
    }if(k > cnt){
        for (int i = 0; i < it; ++i) {
            if(arr[i] == '0'){
                arr[i] = '1';
                cnt++;
                if(cnt == k)
                    break;
            }
        }
        if(k != cnt){
            for (int i = it; i < 64; ++i) {
                arr[it] = '1';
                it++;
                cnt++;
                if(cnt == k){
                    break;
                }
            }
        }
    }
    else if(k <= cnt){
        it2 = it;
        cnt2 = 0;
        while(cnt2 != k){
            if(arr[it2] == '1'){
                cnt2++;
            }
            it2--;
        }
        cnt2 = 0;
        arr[it2+1] = '0';
        it2 += 2;
        while(arr[it2] != '0'){
            arr[it2] = '0';
            cnt2++;
            it2++;
        }
        arr[it2] = '1';
        for (int i = 0; i < it2; ++i) {
            if(cnt2){
                if(arr[i] == '0'){
                    arr[i] = '1';
                }
                cnt2--;
            }
            else{
                arr[i] = '0';
            }
        }
        it2++;
    }
    long long int res = 0;
    for (int i = 0; i <= max(it2, it); i++) {
        //cerr << arr[max(it, it2)-i];
        if(arr[i] == '1'){
            res |= (1LL << i);
        }
    }//cerr << endl;
    cout << res << endl;
    return 0;
}

