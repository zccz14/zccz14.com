int SieveOfEuler(int n, int *prime, bool *isPrime) {
    // Initialize
    int cnt = 0;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }
    // Sieve
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++) {
            int next = i * prime[j];
            if (next > n) {
                break;
            }
            isPrime[next] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}
