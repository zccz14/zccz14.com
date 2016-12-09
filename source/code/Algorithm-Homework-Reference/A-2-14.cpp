#include <iostream>
#include <cmath>
const int MAXN = 10;
int Gray[1 << MAXN];

int getGray(int n) {
  if (n == 0) return 0;
  if (Gray[n]) return Gray[n];
  return Gray[n] = (1 << int(log2(n)))
                 + getGray((1 << int(ceil(log2(n+1)))) - 1 - n);
}

int main() {
  int n;
  while (std::cin >> n) {
    for (int i = 0; i < (1 << n); i++) {
      int x = getGray(i);
      for (int j = n - 1; j >= 0; j--) {
        std::cout << ((x & (1 << j))? '1': '0');
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
