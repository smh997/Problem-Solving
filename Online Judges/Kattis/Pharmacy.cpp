/*
 * https://open.kattis.com/problems/pharmacy
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

#define num unsigned long long int
#define inf LONG_LONG_MAX


vector<pair<num, num>> pre_s, pre_r, te;

num s_sum = 0, r_sum = 0;

inline num max_(num x, num y){
    return x > y ? x : y;
}

bool decide(int s_index, int r_index){
    if(s_index >= pre_s.size()) 
        return 1;
    if(r_index >= pre_r.size())
        return 0;
    if(pre_s[s_index].first == pre_r[r_index].first)
        return 0;
    if(pre_s[s_index].first < pre_r[r_index].first)
        return 0;
    return 1;
}

int main(){
    int N, P;
    scanf("%d %d", &N, &P);
    te.resize(P);
    for (int i = 0; i < N; ++i) {
        int a, l;
        char sr;
        scanf("%d %c %d", &a, &sr, &l);
        if(sr == 'S')
            pre_s.push_back(make_pair(a, l));
        else
            pre_r.push_back(make_pair(a, l));
    }

    sort(pre_s.begin(), pre_s.end());
    sort(pre_r.begin(), pre_r.end());
    int index_s = 0, index_r = 0;
    for (int i = 0; i < N; ++i) {
        if(i < P){
            if(decide(index_s, index_r)){
                te[i] = pre_r[index_r];
                r_sum += te[i].second;
                index_r++;
            }
            else{
                te[i] = pre_s[index_s];
                s_sum += te[i].second;
                index_s++;
            }
        }
        else{
            int te_min_index = 0;
            int te_min = te[0].first + te[0].second;
            for (auto it = te.begin(); it != te.end(); ++it) {
                if((*it).first + (*it).second < te_min){
                    te_min_index = it-te.begin();
                    te_min = (*it).first + (*it).second;
                }
            }
            if(index_s < pre_s.size() && pre_s[index_s].first <= te_min){
                te[te_min_index] = make_pair(te_min, pre_s[index_s].second);
                s_sum += te_min + pre_s[index_s].second - pre_s[index_s].first;
                index_s++;
            }
            else{
                if(decide(index_s, index_r)){
                    num a = max_(te_min, pre_r[index_r].first), b = pre_r[index_r].second;
                    te[te_min_index] = make_pair(a, b);
                    r_sum += a + b - pre_r[index_r].first;
                    index_r++;
                }else{
                    num a = max_(te_min, pre_s[index_s].first), b = pre_s[index_s].second;
                    te[te_min_index] = make_pair(a, b);
                    s_sum += a + b - pre_s[index_s].first;
                    index_s++;
                }
            }
        }
    }
    double s_result = 0;
    double r_result = 0;
    if(pre_s.size() != 0)
        s_result = double(s_sum) / pre_s.size();
    if(pre_r.size() != 0)
        r_result = double(r_sum) / pre_r.size(); 
    printf("%.7f %.7f\n", s_result, r_result);
    return 0;
}
