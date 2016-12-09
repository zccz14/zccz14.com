#include <cstdio>
#include <algorithm>

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", arr + i);
    }
    std::sort(arr, arr + n);
    bool has = false;
    int mainElement;
    for (int left = 0, right = 0; right < n; right++) {
      if (arr[left] != arr[right]) {
        left = right;
      }
      if (right - left + 1 > n / 2) {
        has = true;
        mainElement = arr[left];
        break;
      }
    }
    if (has) {
      printf("main element is %d\n", mainElement);
    } else {
      printf("no main element\n");
    }
    delete arr;
  }
  return 0;
}

