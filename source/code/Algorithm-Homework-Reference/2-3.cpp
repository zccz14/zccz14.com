// Half Set
#include <cstdio>
const int MAXN = 1000;

int ans[MAXN];

int solve(int n) {
  if (ans[n]) return ans[n]; 
  int sum = 1;
  for (int i = n / 2; i > 0; i--) {
    sum += solve(i);
  }
  return ans[n] = sum;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", solve(n));
  return 0;
}
