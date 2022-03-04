/*
 * https://quera.org/problemset/10326/
 * Author: https://github.com/smh997/
 */
#include<iostream>
using namespace std;
int main(void)
{
    int a ,b , c , d;
    int marahel;
    cin >> a >> b >> c >> d;
    if(a <= c){
        marahel = 2 * a - 1;
    }
    else{
        marahel = 2 * c;
    }
    int A[4];
    A[0] = marahel / 4;
    A[1] = marahel / 4;
    A[2] = marahel / 4;
    A[3] = marahel / 4;
    for (int i = 0; i < marahel % 4; ++i) {
        A[i]++;
    }
    for (int i = 0; i < 4; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
