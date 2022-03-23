/*
 * https://quera.org/problemset/10166/
 * Author: https://github.com/smh997/
 */
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int *a = new int[n];
    string q;
    cin >> q;
    for(int i = 0; i < n; i++)
        a[i] = q[i] - 48;
    int max = 0, ex = 0, ey = 0, ez = 0, i;
    for(i = 0; i < n; i += 6)
    {
        if(a[i] == 3)
            ex++;
        if(a[i + 1] == 3)
            ex++;
        if(a[i + 2] == 1)
            ex++;
        if(a[i + 3] == 1)
            ex++;
        if(a[i + 4] == 2)
            ex++;
        if(a[i + 5] == 2)
            ex++;

    }
    if(a[i] == 3 && i < n)
        ex++;
    if(a[i + 1] == 3 && i + 1 < n)
        ex++;
    if(a[i + 2] == 1 && i + 2 < n)
        ex++;
    if(a[i + 3] == 1 && i + 3 < n)
        ex++;
    if(a[i + 4] == 2 && i + 4 < n)
        ex++;
    if(a[i + 5] == 2 && i + 5 < n)
        ex++;
    if(ex > max)
        max = ex;
    for(i = 0; i < n; i += 3)
    {
        if(a[i] == 1)
            ey++;
        if(a[i + 1] == 2)
            ey++;
        if(a[i + 2] == 3)
            ey++;
    }
    if(a[i] == 1 && i < n)
        ey++;
    if(a[i + 1] == 2 && i + 1 < n)
        ey++;
    if(a[i + 2] == 3 && i + 2 < n)
        ey++;
    if(ey > max)
        max = ey;
    for(i = 0; i < n; i += 4)
    {
        if(a[i] == 2)
            ez++;
        if(a[i + 1] == 1)
            ez++;
        if(a[i + 2] == 2)
            ez++;
        if(a[i + 3] == 3)
            ez++;
    }
    if(a[i] == 2 && i < n)
        ez++;
    if(a[i + 1] == 1 && i + 1 < n)
        ez++;
    if(a[i + 2] == 2 && i + 2 < n)
        ez++;
    if(a[i + 3] == 3 && i + 3 < n)
        ez++;
    if(ez > max)
        max = ez;
    cout << max << endl;
    if(max == ex){
        cout << "keyvoon" << endl;
    }
    if(max == ey){
        cout << "nezam" << endl;
    }
    if(max == ez){
        cout << "shir farhad" << endl;
    }
}
