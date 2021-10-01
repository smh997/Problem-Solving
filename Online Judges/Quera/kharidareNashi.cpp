#include <iostream>

using namespace std;

int main()
{
    int n,m,k,r,c;
    cin>>n>>m>>k;
    int arr[n+1][m+1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            arr[i][j]=0;
        }
    }
    for (int i = 0; i < k; ++i) {
        cin>>r>>c;
        arr[r][c]=1;
    }
    if(k%2==1){
        cout<<0<<endl;
        return 0 ;
    }
    else if(n*m==k){
        cout<<-1<<endl;
        return 0;
    }    else
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(arr[i][j]==0){
                    cout<<1<<endl<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }

    return 0;
}

