int gcd(int a, int b){
    int mx = max(abs(a), abs(b));
    int mi = min(abs(a), abs(b));
    if(mi == 0)
        return mx;
    return gcd(mi, mx % mi);
}
