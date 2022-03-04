/*
 * https://quera.org/problemset/10232/
 * Author: https://github.com/smh997/
 */
#include<iostream>
using namespace std;
int main(void)
{
    int n, l, time = 0;
    cin >> n >> l;
    int* d = new int[n];
    int* r = new int[n];
    int* g = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> r[i] >> g[i];
        if(i != 0)
            time += d[i] - d[i - 1];
        else
            time += d[0];
        if(time % (r[i] + g[i]) < r[i]){
            time += r[i] - (time % (r[i] + g[i]));
        }
    }
    time += l - d[n - 1];
    cout << time << endl;
}
