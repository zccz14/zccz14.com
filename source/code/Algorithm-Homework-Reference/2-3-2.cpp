// Half Set
#include <cstdio>
const int MAXN = 1000;

int ans[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    ans[i] = ans[i - 1] + (i % 2 == 0? ans[i / 2]: 0);
  }
  printf("%d\n", ans[n]);
  return 0;
}
