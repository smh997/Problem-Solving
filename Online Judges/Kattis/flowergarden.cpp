/*
 * https://open.kattis.com/problems/flowergarden
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num double
#define inf LONG_LONG_MAX

inline num dis(pair<num, num> p1, pair<num, num> p2){
	num deltax = p1.first - p2.first;
	num deltay = p1.second - p2.second;
	return sqrt(deltax * deltax + deltay * deltay); 
}

bool prime(int n){
	if(n ==0)
        return 1;
	if(n == 1)
        return 0;
    for(int x = 2; x < int(sqrt(n))+1; x++)
        if(n % x == 0)
            return 0;
	return 1;
}

pair<num, num> points[20003];

int main(void){

	int T; 
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N; num D;
        cin >> N >> D;
        for (int j = 0; j < N; ++j) {
            num x, y;
            cin >> x >> y;
			points[j] = make_pair(x, y);
        }
		pair<num, num> lastp = make_pair(0, 0);
		int idx = 0;
        for (int j = 0; j < N; ++j) {
            num distance = dis(points[idx], lastp);
			lastp = points[idx];
			D -= distance;
			if(D > 0)
                idx++;
            else if(D == 0){
                idx++; 
                break;
            }
            else
                break;
        }
        while(!prime(idx))
            idx--;
        cout << idx << endl;
    }

	return 0;
}


