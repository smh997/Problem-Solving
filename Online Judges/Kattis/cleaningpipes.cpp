/*
 * https://open.kattis.com/problems/cleaningpipes
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll W, P, wells[1003][2], endp[1003][2], pipeWell[1003], color[1003];
vector<int> adjList[1003];

ll ccw(ll* a, ll *b, ll *p) {
	ll c = (b[0] - a[0]) * (p[1] - a[1]) - (p[0] - a[0]) * (b[1] - a[1]);
	return (c == 0 ? 0 : (c > 0) ? 1 : -1);
}

bool bicoloring(int pipe, int col) {
	if (color[pipe] != 0) 
        return color[pipe] == col;
	color[pipe] = col;
	for (int next : adjList[pipe])
        if (!bicoloring(next, -1*col))
            return false;
	return true;
}

int main() {
	cin >> W >> P;
    for (int i = 0; i < W; ++i)
        cin>>wells[i][0]>>wells[i][1];
    for (int i = 0; i < P; ++i)
        cin>>pipeWell[i]>>endp[i][0]>>endp[i][1], pipeWell[i]--;
    for (int i = 0; i < P; ++i) {
        for (int j = i+1; j < P; ++j) {
            if (pipeWell[i] != pipeWell[j] && (ccw(wells[pipeWell[i]], endp[i], wells[pipeWell[j]]) * ccw(wells[pipeWell[i]], endp[i], endp[j]) <= 0) && (ccw(wells[pipeWell[j]], endp[j], wells[pipeWell[i]]) * ccw(wells[pipeWell[j]], endp[j], endp[i]) <= 0)) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
	bool res = true;
    for (int i = 0; i < P; ++i)
        if(!color[i])
            if(!bicoloring(i, 1)){
                res = false;
                break;
            }
	cout << (res ? "possible" : "impossible") << endl;

	return 0;
}
