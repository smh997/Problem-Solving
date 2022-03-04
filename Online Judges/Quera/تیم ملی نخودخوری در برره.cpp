/*
 * https://quera.org/problemset/10163/
 * Author: https://github.com/smh997/
 */
#include<iostream>
using namespace std;
int main(void)
{
    int a, b, c, maxa = 0, mine = 101, mina = 101, maxe = 0;
    cin >> a >> b >> c;
    int j[6];
    for(int i = 0; i < 6; i++){
        cin >> j[i];
        if(i % 2 == 0){
            if(j[i] > maxa)
                maxa = j[i];
            if(j[i] < mina)
                mina = j[i];
        }
        else{
            if(j[i] > maxe)
                maxe = j[i];
            if(j[i] < mine)
                mine = j[i];
        }
    }
    int sum1 = 0,sum2 = 0, sum3;
    if(mine - maxa < 0)
        sum3 = 0;
    else 
        sum3 = mine - maxa;

    if(j[0] > j[2])
        maxa = j[0];
    else 
        maxa = j[2];

    if(j[1] > j[3])
        mine = j[3];
    else 
        mine = j[1];

    if(mine - maxa > 0) 
        sum2 += mine - maxa;

    if(j[0] > j[4]) 
        maxa = j[0];
    else 
        maxa = j[4];

    if(j[1] > j[5])
        mine = j[5];
    else 
        mine = j[1];

    if(mine - maxa > 0) 
        sum2 += mine - maxa;

    if(j[2] > j[4]) 
        maxa = j[2];
    else 
        maxa = j[4];

    if(j[3] > j[5])
        mine = j[5];
    else 
        mine = j[3];

    if(mine - maxa > 0)
        sum2 += mine - maxa;

    sum2 -= 3 * sum3;

    sum1= maxe - mina - sum2 - sum3;

    cout << sum1 * a + sum2 * 2 * b + sum3 * 3 * c << endl;
}
