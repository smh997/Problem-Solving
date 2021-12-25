/*
 * https://open.kattis.com/problems/modulo
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int main(){
	int a;
	set<int> s;
	for(int i=0; i<10; i++){
		cin>>a;
		s.insert(a%42);
	}
	cout<<s.size()<<endl;
	
	
}