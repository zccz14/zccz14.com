#include <cstdio>
#include <algorithm>

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int *data = new int[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", data + i);
    }
    int k;
    scanf("%d", &k);
    if (0 < k && k <= n) {
      std::sort(data, data + n);
      printf("the k-th largest element is %d\n", data[n - k]);
    } else {
      printf("excuse me?\n");
    }
    delete data;
  }
  return 0;
}
