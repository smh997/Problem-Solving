/*
 * https://quera.org/problemset/17675/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int fib[n];
    fib[2] = 2; fib[1] = 1;
    for(int i = 3; i <= n; i++) 
        fib[i] = fib[i - 1] + fib[i - 2];
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i == fib[j])
        {
            cout << "+";
            j++;
        }
        else
        {
            cout << "-";
        }
    }
    cout << endl;
    return 0;
}
