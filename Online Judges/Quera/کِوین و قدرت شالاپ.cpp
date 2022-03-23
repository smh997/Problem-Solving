/*
 * https://quera.org/problemset/14581/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = 0;
    sum += (n / 2) * ((n / 2) + 1);
    if(n % 2 == 0)
        sum -= n / 2;
    cout << fixed << setprecision(6) << (double)sum / (n + 1) << endl;
    return 0;
}

