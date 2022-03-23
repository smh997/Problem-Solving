/*
 * https://quera.org/problemset/10325/
 * Author: https://github.com/smh997/
 */
#include<iostream>

using namespace std;

int main(void)
{
    int r, c;
    cin >> r >> c;
    if(c <= 10)
        cout << "Right " << 11 - r << " " << c << endl;
    else
        cout << "Left " << 11 - r << " " << 21 - c << endl;
}
