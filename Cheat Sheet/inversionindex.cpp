int n;
int arr[1000003];
int tmp[1000003];

long long int swaps(int start, int end){
    if(start == end)
        return 0;
    int mid = (start + end) / 2;
    long long int cnt = swaps(start, mid) + swaps(mid+1, end);
    int lptr = start, rptr = mid+1;
    int output = start;
    while(lptr <= mid || rptr <= end){
        if(lptr == mid+1)
            tmp[output++] = arr[rptr++];
        else if(rptr == end+1)
            tmp[output++] = arr[lptr++];
        else{
            if(arr[lptr] > arr[rptr]){
                tmp[output++] = arr[rptr++];
                cnt += mid - lptr + 1;
            }
            else tmp[output++] = arr[lptr++];
        }
    }
    copy(tmp+start, tmp+output, arr+start);
    return cnt;
}