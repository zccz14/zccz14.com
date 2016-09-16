#include <cstdio>
const int MAXN = 100;
int prime[MAXN];
bool isPrime[MAXN + 1];
int SieveOfEuler(int n, int *prime, bool *isPrime) {
    // Initialize
    int cnt = 0;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }
    // Sieve
    for (int i = 2; i <= n; i++) {
        printf("---%d---\n", i);
        if (isPrime[i]) {
            prime[cnt++] = i;
            printf("Prime #%d is %d\n", cnt, i);
        }
        for (int j = 0; j < cnt; j++) {
            int next = i * prime[j];
            if (next > n) {
                break;
            }
            printf("%d = %d * %d\n", next, i, prime[j]);
            isPrime[next] = false;
            if (i % prime[j] == 0) {
                printf("Break!\n");
                break;
            }
        }
    }
    return cnt;
}

int main() {
    SieveOfEuler(MAXN, prime, isPrime);
    return 0;
}
