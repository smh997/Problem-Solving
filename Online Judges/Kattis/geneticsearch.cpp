/*
 * https://open.kattis.com/problems/geneticsearch
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define Max_n 1003
int M, N, lps[Max_n];
string pat, txt;
int res;
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
            res++;
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
string s;
string ch[4] = {"A", "G", "C", "T"};
set<string> stock;
int res2;
int main() 
{ 
    while(cin >> s){
        if(s == "0")
            break;
        cin >> txt;
        res = 0;
        pat = s;
        KMPSearch();
        cout << res << " ";
        res2 = 0;stock.clear();
        for (int i = 0; i < s.length(); ++i) {
            res = 0;
            pat = s.substr(0, i) + s.substr(i+1, s.length()-i-1);
            if(stock.find(pat) == stock.end()){
                stock.insert(pat);
                KMPSearch();
                res2 += res;
            }
        }
        cout << res2 << " ";
        if(s.length() == txt.length()){
            cout << 0 << endl;
            continue;
        }
        res2 = 0;
        for (int i = 0; i <= s.length(); ++i) {
            for (int j = 0; j < 4; ++j) {
                res = 0;
                pat = s;
                pat.insert(i, ch[j]);
                if(stock.find(pat) == stock.end()){
                    stock.insert(pat);
                    KMPSearch();
                    res2 += res;
                }
            }
        }
        cout << res2 << endl;
    }
	
	return 0; 
}

