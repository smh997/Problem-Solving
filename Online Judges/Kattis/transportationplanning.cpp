/*
 * https://open.kattis.com/problems/transportationplanning
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX_n 103
#define INF 1e9

int n, m, a, b; double c;
double matAdj[MAX_n][MAX_n], tmp[MAX_n][MAX_n];
pair<int, int> points[MAX_n];
bool exis[MAX_n][MAX_n];
int ex[MAX_n*MAX_n][2];
double calc(int i, int j){
    return sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second));
}

int main(){
    while (scanf("%d", &n)==1)
    {
        if(!n)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &points[i].first, &points[i].second);
            for (int j = 0; j < n; j++)
            {
                exis[i][j] = (i==j);
                if(i==j)
                    matAdj[i][j]=0;
                else
                    matAdj[i][j]=INF;
            }
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            c = calc(a, b);
            if(c<matAdj[a][b]){
                matAdj[a][b] = c;
                matAdj[b][a] = c;
                exis[a][b] = true;
                exis[b][a] = true;
            }
        }
        
        for (int k = 0; k < n; k++)
        {    
            for (int i = 0; i < n; i++)
            {
                for (int j = i+1; j < n; j++)
                {
                    if(matAdj[i][k] != INF && matAdj[k][j]!=INF && matAdj[i][k]+matAdj[k][j] < matAdj[i][j])
                        matAdj[j][i]=matAdj[i][j]=matAdj[i][k]+matAdj[k][j];
                }
            }
        }
        int co=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp[i][j] = matAdj[i][j];
                if(!exis[i][j]){
                    ex[co][0]=i, ex[co][1]=j;
                    co++;
                }
            }
        }
        double sum=0, sumt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                sum += matAdj[i][j]; 
            }
        }
        double best = sum; int besta = 0, bestb=0;
        
        for (int h = 0; h < co; h++)
        {
            int f=ex[h][0], g = ex[h][1];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matAdj[i][j] = tmp[i][j];
                }
            }
            sumt = 0;
            matAdj[g][f] = matAdj[f][g] = calc(f, g);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matAdj[i][j] = min(matAdj[i][j], matAdj[i][f] + matAdj[f][g] + matAdj[g][j]);
                    matAdj[i][j] = min(matAdj[i][j], matAdj[i][g] + matAdj[g][f] + matAdj[f][j]);
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i+1; j < n; j++)
                {
                    sumt += matAdj[i][j]; 
                }
            }
            if(sumt<best){
                best = sumt;
                besta = f;
                bestb = g;
            }
        }
        
        if(best == sum){
            printf("no addition reduces %.5lf\n", best);
        }
        else{
            printf("adding %d %d reduces %.5lf to %.5lf\n", besta, bestb, sum, best);
        }
    }
    return 0;
}
