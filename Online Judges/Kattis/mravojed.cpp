/*
 * https://open.kattis.com/problems/mravojed
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
int R, C;
char grid[103][103];
int main()
{
    cin >> R >> C;
    int sr=-1, sc=-1;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j){
            cin>>grid[i][j];
            if(sr == -1 && sc == -1 && grid[i][j] == 'x')
                sr = i, sc = j;
        }
    int my = 0, mx = 0;
    for (int i = sr; i < R; ++i) {
        if(grid[i][sc] == 'x')
            my++;
        else
            break;
    }
    for (int j = sc; j < C; ++j) {
        if(grid[sr][j] == 'x')
            mx++;
        else
            break;
    }
    int mi = min(mx, my);
    cout << sr+1 << " " << sc+1 << " " << mi << endl;
    for (int i = sr; i < sr+mi; ++i) {
        for (int j = sc; j < sc+mi; ++j) {
            grid[i][j] = '.';
        }
    }
//    int miny = R+1, minx = C+1, tmpy, tmpx, minxr=-1, minxc=-1, minyr=-1, minyc=-1;
//    for (int i = 0; i < R; ++i) {
//        for (int j = 0; j < C; ++j) {
//            if(grid[i][j] == 'x'){
//                tmpx = 1;int k;
//                for (k = j+1; k < C; ++k) {
//                    if(grid[i][k] == 'x'){
//                        tmpx++;
//                    }
//                    else{
//                        break;
//                    }
//                }
//                if(minx > tmpx){
//                    minx = tmpx;
//                    minxr = i;
//                    minxc = j;
//                }
//                j = k-1;
//            }
//        }
//    }
//    for (int j = 0; j < C; ++j) {
//        for (int i = 0; i < R; ++i) {
//            if(grid[i][j] == 'x'){
//                tmpy = 1;int k;
//                for (k = i+1; k < R; ++k) {
//                    if(grid[k][j] == 'x'){
//                        tmpy++;
//                    }
//                    else{
//                        break;
//                    }
//                }
//                if(miny > tmpy){
//                    miny = tmpy;
//                    minyr = i;
//                    minyc = j;
//                }
//                i = k-1;
//            }
//        }
//    }
////    cerr<< minx << ": " << minxr<< " " << minxc<<endl;
////    cerr<< miny << ": " << minyr<< " " << minyc<<endl;
//    if(minx <= miny){
//        cout << minxr+1 << " " << minxc+1 << " " << minx << endl;
//        for (int i = minxr; i < minxr+minx; ++i) {
//            for (int j = minxc; j < minxc+minx; ++j) {
//                grid[i][j] = '.';
//            }
//        }
//    }
//    else{
//        cout << minyr+1 << " " << minyc+1 << " " << miny << endl;
//        for (int i = minyr; i < minyr+miny; ++i) {
//            for (int j = minyc; j < minyc+miny; ++j) {
//                grid[i][j] = '.';
//            }
//        }
//    }

//    for (int i = 0; i < R; ++i){
//        for (int j = 0; j < C; ++j)
//            cerr<<grid[i][j];
//        cerr<<endl;
//    }
    int maxy = 0, maxx = 0, maxxr=-1, maxxc=-1, maxyr=-1, maxyc=-1, tmpx, tmpy;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if(grid[i][j] == 'x'){
                tmpx = 1;int k;
                for (k = j+1; k < C; ++k) {
                    if(grid[i][k] == 'x'){
                        tmpx++;
                    }
                    else{
                        break;
                    }
                }
                if(maxx < tmpx){
                    maxx = tmpx;
                    maxxr = i;
                    maxxc = j;
                }
                j = k-1;
            }
        }
    }
    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < R; ++i) {
            if(grid[i][j] == 'x'){
                tmpy = 1;int k;
                for (k = i+1; k < R; ++k) {
                    if(grid[k][j] == 'x'){
                        tmpy++;
                    }
                    else{
                        break;
                    }
                }
                if(maxy < tmpy){
                    maxy = tmpy;
                    maxyr = i;
                    maxyc = j;
                }
                i = k-1;
            }
        }
    }
//    cerr<< maxx << ": " << maxxr<< " " << maxxc<<endl;
//    cerr<< maxy << ": " << maxyr<< " " << maxyc<<endl;
    int m = max(maxx, maxy);
    if(!maxx){
        cout << sr+1 << " " << sc+1 << " " << mi << endl;
    }
    else if (maxx == maxy){
        if(maxxr == maxyr && maxxc == maxyc){
            cout << maxxr+1 << " " << maxxc+1 << " " << m << endl;
        }
        else if(maxxr > maxyr){
            cout << maxyr+1 << " " << maxxc+1 << " " << m << endl;
        }
        else{
            cout << maxxr - m + 2 << " " << maxxc+1 << " " << m << endl;
        }
    }
    else if(maxx>maxy){
        if(maxxr == maxyr && maxxc == maxyc){
            cout << maxxr - (maxx-maxy) + 1 << " " << maxxc+1 << " " << m << endl;
        }
        else if(maxxr > maxyr){
            cout << maxyr+1 << " " << maxxc+1 << " " << m << endl;
        }
        else{
            cout << maxxr - m + 2 << " " << maxxc+1 << " " << m << endl;
        }
    }
    else{
        if(maxxr == maxyr && maxxc == maxyc){
            if(maxxc < sc)
                cout << maxxr+1 << " " << maxxc + 1 << " " << m << endl;
            else
                cout << maxxr+1 << " " << maxxc - (maxy-maxx) + 1 << " " << m << endl;
        }
        else if(maxxr > maxyr){
            cout << maxyr+1 << " " << maxxc+1 << " " << m << endl;
        }
        else{
            cout << maxyr+1 << " " << maxyc - m + 2 << " " << m << endl;
        }
        
    }
    return 0;
}
/*
4 6
xxxxxx
xxxxxx
xxxxxx
xxxxxx

4 5
.xxxx
xxxxx
xxxxx
xxxxx
*/
