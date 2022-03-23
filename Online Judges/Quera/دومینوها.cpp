/*
 * https://quera.org/problemset/17676/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int n, m, sum = 0;
    bool flag = false;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (!flag && arr[i][j] == '|') {
                flag = true;
                sum++;
            } else if (flag && arr[i][j] == '-') {
                flag = false;
            }
        }
    }
    flag = false;
    for (int j = 0; j < m; j++) {
        flag = false;
        for (int i = 0; i < n; i++) {
            if (!flag && arr[i][j] == '-') {
                flag = true;
                sum++;
            } 
            else if (flag && arr[i][j] == '|') {
                flag = false;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
