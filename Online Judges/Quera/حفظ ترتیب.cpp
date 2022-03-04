/*
 * https://quera.org/problemset/1359/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

string reverseStr(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}
bool isSubSequence(string str1, string str2, int m, int n)
{
    if (m == 0) return true;
    if (n == 0) return false;

    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);

    return isSubSequence(str1, str2, m, n - 1);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string first,second;
        cin >> first >> second;
        if(isSubSequence(second, first, second.length(), first.length())
                ||isSubSequence(reverseStr(second),first, second.length(), first.length()))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

