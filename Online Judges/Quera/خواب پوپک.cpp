/*
 * https://quera.org/problemset/15124/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int a, b, x, res = 0;
    cin >> a >> b >> x;
    for (int i = 1; i <= a; ++i) {
        if(a % i == 0){
            for (int j = 1; j <= b; ++j) {
                if(b % j == 0){
                    if(i + j <= x) 
                        res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}

