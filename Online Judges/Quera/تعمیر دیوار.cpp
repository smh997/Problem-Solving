/*
 * https://quera.org/problemset/6580/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int x, y, r, dx, dy;
    cin >> x >> y >> r >> dx >> dy;
    if (x <= dx && dx <= x + r && y - r <= dy && dy <= y) {
        cout << "Mahdi" << endl;
    }
    else 
        cout << "Parsa" << endl;
    return 0;
}

