/*
 * https://quera.org/problemset/10164/
 * Author: https://github.com/smh997/
 */
#include<iostream>
using namespace std;
int main(void)
{
    char a[7][7];
    int ans = 0;
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            cin >> a[i][j];

    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            if(a[i][j] == '.')
            {
                if(j <= 4 && a[i][j + 1] == 'o' && a[i][j + 2] == 'o')
                    ans++;
                if(i >= 2 && a[i-1][j] == 'o' && a[i - 2][j] == 'o')
                    ans++;
                if(i <= 4 && a[i + 1][j] == 'o' && a[i + 2][j] == 'o')
                    ans++;
                if(j >= 2 && a[i][j - 1] == 'o' && a[i][j - 2] == 'o')
                    ans++;
            }
    cout << ans << endl;
}
