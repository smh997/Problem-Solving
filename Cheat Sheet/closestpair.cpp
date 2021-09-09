inline double cdis(pair<double, double>& p1, pair<double, double>& p2){
    double deltax = p1.first - p2.first;
    double deltay = p1.second - p2.second;
    return sqrt(deltax * deltax + deltay * deltay); 
}

bool byX(const pair<double, double>& p1, const pair<double, double>& p2){
    return p1.first < p2.first;
}

bool byY(const pair<double, double>& p1, const pair<double, double>& p2){
    return p1.second < p2.second;
}

int n;
pair<double, double> points[100003];
pair<double, double> tmp[100003];

struct closest{
    double dis;
    pair<double, double> p1, p2;
};

closest find_closest(int l, int r){
    closest ans;
    if(r-l == 1){
        ans.dis = cdis(points[l], points[r]);
        ans.p1 = points[l];
        ans.p2 = points[r];
    }
    else if(r-l == 2){
        ans.dis = cdis(points[r-1], points[r]);
        ans.p1 = points[r-1];
        ans.p2 = points[r];
        for(int k = r-1; k <= r; k++){
            double dis = cdis(points[l], points[k]);
            if(dis < ans.dis){
                ans.dis = dis;
                ans.p1 = points[l];
                ans.p2 = points[k];
            }
        } 
    }
    else{
        int mid = (l + r) / 2;
        closest left = find_closest(l, mid);
        closest right = find_closest(mid+1, r);
        if(left.dis < right.dis){
            ans.dis = left.dis;
            ans.p1 = left.p1;
            ans.p2 = left.p2;
        }else{
            ans.dis = right.dis;
            ans.p1 = right.p1;
            ans.p2 = right.p2;
        }
        auto lptr = lower_bound(points+l, points+r+1, make_pair(points[mid].first - ans.dis, 0.0), byX);
        auto rptr = upper_bound(points+l, points+r+1, make_pair(points[mid+1].first + ans.dis, 0.0), byX); 
        int size = rptr - lptr;
        copy(lptr, rptr, tmp);
        sort(tmp, tmp+size, byY);
        for(int i = 0; i < size; i++)
            for(int j = i+1; j < min(i+16, size); j++){
                double dis = cdis(tmp[i], tmp[j]);
                if(dis < ans.dis){
                    ans.dis = dis;
                    ans.p1 = tmp[i];
                    ans.p2 = tmp[j];
                }
            }
    }
    return ans;
}

closest solve(){
    sort(points, points+n);
    return find_closest(0, n-1);
}