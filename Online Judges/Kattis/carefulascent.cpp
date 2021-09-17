/*
 * https://open.kattis.com/problems/carefulascent
 * Author: https://github.com/smh997/
 */

#include <iostream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
        int x,y,n;
        cin >> x >> y >> n;
        double mainn[n][3];
        double high = 100000000;
        double low = 0.000000001;
        double mid = (high + low)/2;
        double l = 0;
        int space = 0;
        int z = 0;
        bool is = false;
        for (int i = 0 ; i < n ; i++){
            cin >> mainn[i][0] >> mainn[i][1] >> mainn[i][2];
            space += mainn[i][1] - mainn[i][0];
        }
        if (x < 0){
            is = true;
            x = -x;
        }
        else if (x == 0){
            cout << 0;
            return 0;
        }
        while (high > low){
            l = 0;
            z++;
            if (z > 200){
                if (is){
                    cout  << fixed << setprecision(8) << -mid << endl;
                    break;
                }
                cout  << fixed << setprecision(8) << mid << endl;
                break;
            }
            l += mid * (y-space);
            for (int i = 0 ; i < n ; i++){
                l += mid * mainn[i][2] * (mainn[i][1] - mainn[i][0]);
            }
            if (l == x){
                if (is){
                    cout  << fixed << setprecision(8) << -mid << endl;
                    break;
                }
                cout  << fixed << setprecision(8) << mid << endl;
                break;
            }
            if (l > x){
                high = mid;
                mid = (high + low)/2;
            }
            else {
                low = mid;
                mid = (high + low)/2;
            }
        }
    return 0;
}
