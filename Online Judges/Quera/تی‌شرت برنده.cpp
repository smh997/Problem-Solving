/*
 * https://quera.org/problemset/3107/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int s, h, s1, h1;
    cin >> s >> h >> s1 >> h1;
    cout << ((s >= s1 && h >= h1) ? "yes" : "no") << endl;
    return 0;
}

