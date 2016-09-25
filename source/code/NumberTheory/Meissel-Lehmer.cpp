#include <cstdio>
#include <vector>
#include <cmath>

const long long MAXN = 10000000LL;  

std::vector<int> prime;
bool isPrime[MAXN + 1];
int pi[MAXN + 1];

void SieveOfEuler(int n, std::vector<int> &prime, int *pi, bool *isPrime) {
  int cnt = 0;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    isPrime[i] = true;
  }
  for (int i = 0; i <= n; i++) {
    if (isPrime[i]) {
      prime.push_back(i);
      cnt++;
    }
    pi[i] = cnt;
    for (std::vector<int>::iterator it = prime.begin(); it != prime.end(); it++) {
      int next = i * (*it);
      if (next > n) {
        break;
      }
      isPrime[next] = false;
      if (i % (*it) == 0) {
        break;
      }
    }
  }
}

long long MeisselLehmer(long long lim);  

// 
long long phi(long long m, int n) {
  if(m <= 0) return 0;
  if(n == 0) return m;
  if(prime[n - 1] * prime[n - 1] >= m) return MeisselLehmer(m) - n + 1;
  return phi(m, n - 1) - phi(m / prime[n - 1], n - 1);
}

long long MeisselLehmer(long long n) {  
  if(n <= MAXN) return pi[n];
  int m3 = int(pow(n, 1./3)), m2 = int(sqrt(n));
  long long sub = MeisselLehmer(m3), p2 = 0;
  // \forall p \in (\sqrt[3]{n}, \sqrt{n}]
  for (int p = m2; p > m3; p--) {
    if (isPrime[p]) {
      p2 += MeisselLehmer(n / p) - MeisselLehmer(p) + 1;
    }
  }
  return phi(n, sub) + sub - 1 - p2;
}

int main() {
  long long N;
  SieveOfEuler(MAXN, prime, pi, isPrime);
  while (scanf("%lld",&N) == 1) {
    printf("%lld\n",MeisselLehmer(N));
  }
  return 0;
}

