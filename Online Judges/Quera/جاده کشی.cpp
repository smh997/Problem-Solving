/*
 * https://quera.org/problemset/2637/
 * Author: https://github.com/smh997/
 */
// 
#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << pow((n / 2 + 1), 2) + ((n % 2) * (n / 2 + 1)) << endl;
    return 0;
}
