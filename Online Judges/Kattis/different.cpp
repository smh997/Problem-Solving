/*
 * https://open.kattis.com/problems/different
 * Author: https://github.com/smh997/
 */

#include <iostream>
using namespace std;
int main(){
	long long int a,b;
	while (scanf("%lld %lld", &a, &b) == 2) {
			cout << ((a >= b)? a-b: b-a) << endl;
	}	
	return 0;
}