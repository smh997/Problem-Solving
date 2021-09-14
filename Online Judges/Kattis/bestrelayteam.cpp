/*
 * https://open.kattis.com/problems/bestrelayteam
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

string s[503];
vector<pair<double, int>> leg1;
vector<pair<double, int>> leg2;

int main()
{
    int n; double l1, l2, m=1000.0, tmp;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s[i]>>l1>>l2;
        leg1.push_back(make_pair(l1, i));
        leg2.push_back(make_pair(l2, i));
    }
    sort(leg2.begin(), leg2.end());
    sort(leg1.begin(), leg1.end());
    string res[4]; 
    for (int i = 0; i < 4; ++i) 
        for (int j = 0; j < 4; ++j) 
            for (int k = j+1; k < 4; ++k) 
                for (int l = k+1; l < 4; ++l){
                    tmp = leg1[i].first + leg2[j].first + leg2[k].first + leg2[l].first;
                    if(leg1[i].second != leg2[j].second && leg1[i].second != leg2[k].second && leg1[i].second != leg2[l].second && tmp<m){
                        m = tmp;
                        res[0] = s[leg1[i].second];
                        res[1] = s[leg2[j].second];
                        res[2] = s[leg2[k].second];
                        res[3] = s[leg2[l].second];
                    }
                }
    printf("%.2lf\n", m);
    for (int i = 0; i < 4; ++i) {
        cout<<res[i]<<endl;
    }
    return 0;
}

