vector<long long int> factors;
long long int primeFactors(long long int N) { // and also sumPF
    long long int PF_idx = 0, primefactor = PF[PF_idx], res = 0;
    while (primefactor * primefactor <= N) { // stop at sqrt(N); N can get smaller
        while (N % primefactor == 0){
            N /= primefactor; // remove PF
            factors.push_back(primefactor);
            res += primefactor;
        } 
        primefactor = PF[++PF_idx]; // only consider primes
    }
    if (N != 1)
        factors.push_back(N), res += N; // special case if N is a prime
    return res;
}

long long int numPF(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = 0;
    while (primefactor * primefactor <= N) {
        while (N % primefactor == 0){
            N /= primefactor;
            ans++;
        }
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        ans++;
    return ans;
}

long long int numDiv(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = 1; // start from ans = 1
    while (primefactor * primefactor <= N) {
        long long int power = 0;
        while (N % primefactor == 0) { N /= primefactor; power++; }
        ans *= (power + 1); // according to the formula
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        ans *= 2;// (last factor has pow = 1, we add 1 to it)
    return ans;
}

long long int sumDiv(long long int N) {
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = 1; // start from ans = 1
    while (primefactor * primefactor <= N) {
        long long int power = 0;
        while (N % primefactor == 0){
            N /= primefactor;
            power++;
        }
        ans *= ((long long int)pow((double)primefactor, power + 1.0) - 1) / (primefactor - 1);
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        ans *= ((long long int)pow((double)N, 2.0) - 1) / (N - 1); // last
    return ans;
}

long long int EulerPhi(long long int N) { // Count the number of positive integers < N that are relatively prime to N
    long long int PF_idx = 0, primefactor = PF[PF_idx], ans = N; // start from ans = N
    while (primefactor * primefactor <= N) {
        if (N % primefactor == 0)
            ans -= ans / primefactor; // only count unique factor
        while (N % primefactor == 0)
            N /= primefactor;
        primefactor = PF[++PF_idx];
    }
    if (N != 1)
        ans -= ans / N; // last factor
    return ans;
}

int numDiffPF[MAX_N];
void modified_sieve(){ // calculate number of diffferent PFs
    for (int i = 2; i < MAX_N; i++)
        if (numDiffPF[i] == 0) // i is a prime number
            for (int j = i; j < MAX_N; j += i)
                numDiffPF[j]++; // increase the values of multiples of i
}
