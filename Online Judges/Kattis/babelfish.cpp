/*
 * https://open.kattis.com/problems/babelfish
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> mp ;
    string input,a,b;
    while(getline(cin, input) && input!=""){
        stringstream ss(input);
        ss>>a>>b;
        mp.insert(make_pair(b,a));
    }
    string target;
    while(cin>>target){
        if(mp.find(target) != mp.end()){
            cout<<mp.at(target)<<endl;
        }
        else
            cout<<"eh"<<endl;
    }
    return 0;
}
