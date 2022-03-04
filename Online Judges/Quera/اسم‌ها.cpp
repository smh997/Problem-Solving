/*
 * https://quera.org/problemset/2529/
 * Author: https://github.com/smh997/
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string A;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> A;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                if (A[i] == A[j])
                {
                    A.erase(j, 1);
                    j--;
                }
            }
        }
        if(max < A.length())
            max = A.length();
    }
    cout << max << endl;
    return 0;
}
