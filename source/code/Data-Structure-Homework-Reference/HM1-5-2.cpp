#include <cstdio>
#include <algorithm>
#include <cassert>

#define R(x, y) (x > y)

int getKth(int *data, int n, int k) {
  assert(0 < k && k <= n);
  if (n == 1) return data[0];
  int i = 0, j = n - 1, x = data[(n - 1) / 2];
  while (i <= j) {
    while (R(data[i], x)) i++;
    while (R(x, data[j])) j--;
    if (i <= j) std::swap(data[i++], data[j--]);
  }
  if (k - 1 <= j) { // [0, j]
    return getKth(data, j + 1, k);
  } else if (k - 1 >= i){ // [i, n)
    return getKth(data + i, n - i, k - i);
  } else {
    return data[k - 1];
  }
}
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
      printf("the k-th largest element is %d\n", getKth(data, n, k));
    } else {
      printf("excuse me?\n");
    }
    delete data;
  }
  return 0;
}

