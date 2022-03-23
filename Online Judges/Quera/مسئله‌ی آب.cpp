/*
 * https://quera.org/problemset/6192/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;
int main()
{
    long long int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if((a >= d && b >= e) || (a >= e && b >= d) || (a >= d && b >= f) ||(a >= f && b >= d) || (a >= e && b >= f) || (a >= f && b >= e))
        cout << "zende mimuni" <<endl;
    else 
        cout << "dari mimiri" << endl;
    return 0;
}

