/*
 * https://open.kattis.com/problems/randomproblem
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
#include<tuple>
using namespace std;

int arr[1003], p,oc;
vector<tuple<int, int, int, int, int, int, int>> res;
int main()
{
    cin>>p;
    int n,m, lim = ceil(p*1.0/40)+1;
    for (int i = 0; i < p; ++i) {
        cin>>arr[i];
    }
    bool flag = true;
    for (int i = 0; i < p-2; ++i) {
        for (int j = i+1; j < min(p-1, i+300); ++j) {
            for (int k = j+1; k < min(p, i+300); ++k) {
                n=j-i;m=k-j;oc=0;flag = true;
                for (int x = 0; x < p; ++x) {
                    if((x>=n+m && arr[x]==arr[k] && arr[x-n-m]==arr[i] && arr[j]!=arr[x-m]) ||
                       (x>=n+m && arr[x]==arr[k] && arr[x-m]==arr[j] && arr[i]!=arr[x-m-n]) ||
                       (x>=n && x+m<p && arr[x]==arr[j] && arr[i]==arr[x-n] && arr[x+m]!=arr[k])   ||
                       (x>=n && x+m<p && arr[x]==arr[j] && arr[k]==arr[x+m] && arr[x-n]!=arr[i])   ||
                       (x+n+m<p && arr[x]==arr[i] && arr[x+n]==arr[j] && arr[x+n+m]!=arr[k])  ||
                       (x+n+m<p && arr[x]==arr[i] && arr[x+n+m]==arr[k] && arr[x+n]!=arr[j]) ){
                            flag = false;
                            break;
                    }
                }
                if(!flag)
                    continue;
                for (int x = 0; x < p-n-m; ++x) {
                    if(arr[i]==arr[x] && arr[j]==arr[x+n] && arr[k]==arr[x+n+m])
                        oc++;
                }
                if(oc>=lim){
                    res.push_back(make_tuple(i, n, m,arr[i], arr[j], arr[k], oc));
                }
            }
        }
    }
    if(res.size())
        printf("triple correlation %d(%d)%d(%d)%d found\n", get<3>(res[0]),get<1>(res[0]), get<4>(res[0]), get<2>(res[0]), get<5>(res[0]));
    else
        cout<<"random sequence"<<endl;
    return 0;
}
