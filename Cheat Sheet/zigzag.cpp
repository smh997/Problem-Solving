int n, a[1000003];

int zigzag(bool inc){ // true for decrease first
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(inc && a[i] < a[i-1])
            inc = false, ans++;
        if(!inc && a[i] > a[i-1])
            inc = true, ans++;
    }
    return ans;
}