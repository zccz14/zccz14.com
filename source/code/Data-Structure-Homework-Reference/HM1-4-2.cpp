#include <cstdio>
#include <unordered_map>

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::unordered_map<int, int> cnt;
    bool has = false;
    int mainElement;
    for (int i = 0; i < n; i++) {
      if (has) {
        scanf("%*d");
      } else {
        int x;
        scanf("%d", &x);
        if (++cnt[x] > n / 2) {
          has = true;
          mainElement = x;
        }
      }
    }
    if (has) {
      printf("main element is %d\n", mainElement);
    } else {
      printf("no main element\n");
    }
  }
  return 0;
}

