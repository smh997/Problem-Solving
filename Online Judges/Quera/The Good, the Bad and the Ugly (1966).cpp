/*
 * https://quera.org/problemset/132247/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,ll> name;
int main(){
	ll n;
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		string na;
		cin >> na;
		name[na]++;
	}
	for(ll i = 0; i < n - 1; i++){
		string na;
		cin >> na;
		name[na]--;
	}
	for(auto n:name){
		if(n.second != 0){
            cout << n.first << endl;
            break;
        }
	}
	return 0;
}