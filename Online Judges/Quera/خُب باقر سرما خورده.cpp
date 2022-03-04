/*
 * https://quera.org/problemset/10231/
 * Author: https://github.com/smh997/
 */
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
    char a[20];
    int aa[5] = {0}; 
    bool h = true;
    for(int i = 0; i < 5; i++)
    {
        cin >> a;
        if(strstr(a, "MOLANA"))
            aa[i] = 1;
        else if(strstr(a, "HAFEZ"))
            aa[i] = 1;
    }
    for(int i = 0; i < 5; i++)
    {
        if(aa[i] == 1)
        {
            cout << i + 1 << " ";
            h = false;
        }
    }
    if(h)
        cout << "NOT FOUND!" << endl;
    else
        cout << endl;
}
