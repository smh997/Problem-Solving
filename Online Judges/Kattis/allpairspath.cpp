/*
 * https://open.kattis.com/problems/allpairspath
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h> 
using namespace std;
#define MAX_n 153
#define INF 1e9
int n, m, q, a, b, c;
int matAdj[MAX_n][MAX_n];

int main(){
    
    while (cin>>n>>m>>q)
    {
        if(!n && !m && !q)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==j)
                    matAdj[i][j]=0;
                else
                    matAdj[i][j]=INF;
            }
        }
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b>>c;
            if(c<matAdj[a][b])
                matAdj[a][b]=c;
        }
        for (int k = 0; k < n; k++)
        {    
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(matAdj[i][k] != INF && matAdj[k][j]!=INF && matAdj[i][k]+matAdj[k][j] < matAdj[i][j])
                        matAdj[i][j]=matAdj[i][k]+matAdj[k][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if(matAdj[k][k]<0 && matAdj[i][k] != INF && matAdj[k][j]!=INF)
                        matAdj[i][j] = -INF;
                }
            }
            
        }
        for (int i = 0; i < q; i++)
        {
            cin>>a>>b;
            if(matAdj[a][b]==INF)
                cout<<"Impossible"<<endl;
            else if(matAdj[a][b]==-INF){
                cout<<"-Infinity"<<endl;
            }
            else
                cout<<matAdj[a][b]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
