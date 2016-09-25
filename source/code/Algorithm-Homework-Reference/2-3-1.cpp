// Half Set
#include <cstdio>
const int MAXN = 1000;

int ans[MAXN];

int solve(int n) {
  if (ans[n]) return ans[n]; 
  if (n == 1) return 1;
  if (n % 2 == 0) return ans[n] = solve(n / 2) + solve(n - 1);
  return ans[n] = solve(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", solve(n));
  return 0;
}
