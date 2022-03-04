/*
 * https://quera.org/problemset/6313/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int income;
    while(cin >> income){
        if(income == 0)
            break;
        if(income <= 1000000)
            cout << income << endl;
        else if(income <= 5000000)
            cout << income * 9 / 10 << endl;
        else 
            cout << income * 8 / 10 << endl;
    }
    return 0;
}
