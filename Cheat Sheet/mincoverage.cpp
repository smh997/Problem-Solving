int n;
pair<int, int> intervals[10003];
vector<int> indices;

int min_coverage(int A, int B){ // -1 means impossible
    sort(intervals, intervals+n);
    indices.clear();
    int coverage = A, i = -1, cnt = 0;
    while(i < n){
        int cand = -1, maxl = INT_MIN;
        for(int j = i + 1; j < n; j++)
            if(intervals[j].first <= coverage && intervals[j].second >= maxl)
                cand = j, maxl = intervals[j].second;
        if(cand == -1)
            break;
        indices.push_back(cand);
        coverage = maxl, i = cand, cnt++;
        if(coverage >= B)
            break;
    }
    return coverage >= B ? cnt : -1;
}