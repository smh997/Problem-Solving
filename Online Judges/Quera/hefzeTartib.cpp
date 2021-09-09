/**
  https://quera.ir/problemset/contest/1359/%D8%B3%D8%A4%D8%A7%D9%84-%D8%AD%D8%B1%DB%8C%D8%B5%D8%A7%D9%86%D9%87-%D8%AD%D9%81%D8%B8-%D8%AA%D8%B1%D8%AA%DB%8C%D8%A8
  Author: https://github.com/smh997/
**/

#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
string reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}
bool isSubSequence(string str1, string str2, int m, int n)
{
    // Base Cases
    if (m == 0) return true;
    if (n == 0) return false;

    // If last characters of two strings are matching
    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);

    // If last characters are not matching
    return isSubSequence(str1, str2, m, n-1);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string first,second;
        cin>>first>>second;
        if(isSubSequence(second, first, second.length(), first.length())
                ||isSubSequence(reverseStr(second),first, second.length(), first.length()))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

