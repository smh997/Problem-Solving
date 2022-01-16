/*
 * https://open.kattis.com/problems/secretchamber
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_n 27
int n, m;
char a, b;
string sa, sb;
int matAdj[MAX_n][MAX_n];


int main()
{
    cin>>m>>n;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            matAdj[i][j]=(i==j);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        matAdj[a-'a'][b-'a']=1;
    }
    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                matAdj[i][j] |= matAdj[i][k] & matAdj[k][j];
    for (int i = 0; i < n; ++i) {
        cin>>sa>>sb;
        if(sa.length()!=sb.length()){
            cout<<"no"<<endl;
            continue;
        }
        bool ans = true;
        for (int i = 0; i < sa.length(); ++i) {
            if(!matAdj[sa[i]-'a'][sb[i]-'a']){
                ans = false;
                break;
            }
        }
        cout<<((ans)?"yes":"no")<<endl;
    }
    return 0;
}

