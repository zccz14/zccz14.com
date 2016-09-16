#include <cstdio>
const int MAXN = 100;
int prime[MAXN];
bool isPrime[MAXN + 1];
int SieveOfEuler(int n, int *prime, bool *isPrime) {
  printf("$$\n\\require{AMScd}\n\\begin{CD}\n");
  // Initialize
  int cnt = 0;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    isPrime[i] = true;
  }
  // Sieve
  for (int i = 2; i <= n; i++) {
    printf("%d", i);
    if (isPrime[i]) {
      prime[cnt++] = i;
      printf("(p_{%d})", cnt);
    }
    for (int j = 0; j < cnt; j++) {
      int next = i * prime[j];
      if (next > n) {
        break;
      }
      printf(" @>%d>> %d", prime[j], next);
      isPrime[next] = false;
      if (i % prime[j] == 0) {
        break;
      }
    }
    printf(" @>\\cdots>> \\cdots \\\\\n@VVV\\\\\n");
  }
  printf("\\vdots\n\\end{CD}\n$$");
  return cnt;
}

int main() {
  SieveOfEuler(MAXN, prime, isPrime);
  return 0;
}
