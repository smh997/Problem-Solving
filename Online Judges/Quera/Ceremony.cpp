/*
 * https://quera.org/problemset/41181/
 * Author: https://github.com/smh997/
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m = INT_MAX;
	for(int i = n - 1; i >= 0; i--)
		if(m > arr[i] + n - i - 1)
			m = arr[i] + n - i - 1;
	if(n < m)
		m = n;
	cout << m << endl;
}