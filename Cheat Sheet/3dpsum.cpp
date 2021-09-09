num a[23][23][23];
num psum[23][23][23];
int A, B, C;

num get(int i, int j, int k){
    if(i >= 0 && i < A && j >= 0 && j < B && k >= 0 && k < C)
        return psum[i][j][k];
    return 0;
}
// Inclusion-exclusion principle everywhere!
void build(){
    for(int i = 0; i < A; i++)
        for(int j = 0; j < B; j++)
            for(int k = 0; k < C; k++)
                psum[i][j][k] = a[i][j][k] + get(i-1, j, k) + get(i, j-1, k) + get(i, j, k-1) - get(i-1, j-1, k) - get(i-1, j, k-1) - get(i, j-1, k-1) + get(i-1, j-1, k-1);
}

num cube(int i1, int j1, int k1, int i2, int j2, int k2){
    return get(i2, j2, k2) - get(i1-1, j2, k2) - get(i2, j1-1, k2) - get(i2, j2, k1-1) + get(i1-1, j1-1, k2) + get(i1-1, j2, k1-1) + get(i2, j1-1, k1-1) - get(i1-1, j1-1, k1-1);
}