/*
 * https://open.kattis.com/problems/stringmatching
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define Max_n 10000003
int M, N, lps[Max_n];
string pat, txt;
vector<int> res;

void calcLPS() 
{ 
	int len = 0; 
	lps[0] = 0;
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else 
		{ 
			if (len != 0) { 
				len = lps[len - 1];  
			} 
			else
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

void KMPSearch() 
{ 
	M = pat.length(); 
	N = txt.length();  
    
	calcLPS();
    
	int i = 0; // index of txt
	int j = 0; // index of pattern
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 
		if (j == M) { 
			// find a full match: print answer or store it
            res.push_back(i-j);
			j = lps[j - 1]; 
		}  
		else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

int main() 
{ 
    while(getline(cin, pat)){
        getline(cin, txt);
        res.clear();
        KMPSearch();
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << ((i==res.size()-1)?"":" ");
        }
        cout << endl;
    }
	return 0; 
}

