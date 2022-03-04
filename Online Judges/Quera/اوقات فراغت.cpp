/*
 * https://quera.org/problemset/3431/
 * Author: https://github.com/smh997/
 */
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char t[n][m];int res=0;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    cin >> s;
    char * data = new char[s.size() + 1];
    copy(s.begin(), s.end(), data);
    data[s.size()] = '\0';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + s.length() <= m; ++j) {
            int k;
            for (k = 0; k < s.length(); ++k) {
                if(t[i][j + k] != data[k])
                    break;
            }
            if(k == s.length())
                res++;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i + s.length() <= n; ++i) {
            int k;
            for (k = 0; k < s.length(); ++k) {
                if(t[i + k][j] != data[k])
                    break;
            }
            if(k == s.length())
                res++;
        }
    }
    cout << res << endl;
    return 0;
}

