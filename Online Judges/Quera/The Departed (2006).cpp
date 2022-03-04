/*
 * https://quera.org/problemset/132251/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string n;
	ll i = 1;
	vector<ll> ans;
	while(cin >> n){
		if(n.find("FBI") != string::npos){
			ans.push_back(i);
		}
		i++;
	}
	if(ans.size() > 0){
		for(auto i: ans){
			cout << i << ' ';
		}
		cout << endl;
	}
	else
		cout << "HE GOT AWAY!" << endl;
	return 0;
}