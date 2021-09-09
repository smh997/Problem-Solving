#include <bits/stdc++.h>
using namespace std;

// KMP String Matching

// Find All Occurrences of Pattern P in Text T

// O(n + m)

const int maxn = 1e8 + 5;

int n, m; // n = size of t, m = size of p
string t, p; // t is text, p is pattern
int lcp[maxn + 3];

int main(){
	// read input
	n = t.size(), m = p.size();
	int i = 0, j = 1;
	lcp[0] = 0;
	while(j < m){
		if(p[i] == p[j])
			lcp[j] = i + 1, i++, j++;
		else if(i)
			i = lcp[i - 1];
		else
			lcp[j] = 0, j++;
	}
	i = 0, j = 0;
	while(i < n){
		if(t[i] == p[j]){
			i++, j++;
			if(j == m){
				cout << i - j << endl; // T[i-m, i) == P  
				j = lcp[j - 1];
			}
		}
		else if(j)
			j = lcp[j - 1];
		else
			i++;
	}
}
