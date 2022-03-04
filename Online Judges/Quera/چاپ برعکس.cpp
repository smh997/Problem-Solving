/*
 * https://quera.org/problemset/3405/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> A;
	int n;
	cin >> n;
	while(n != 0){
		A.push_back(n);
		cin >> n;
	}
	while(!A.empty()){
		cout << A.back() << endl;
		A.pop_back();
	}
	return 0;
}
