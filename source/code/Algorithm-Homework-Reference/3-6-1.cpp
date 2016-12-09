#include <fstream>

const int MAXN = 200;
int R[MAXN];

int main() {
  std::ifstream FInput("input.txt");
  std::ofstream FOutput("output.txt");
  int n;
  FInput >> n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int r;
      FInput >> r;
      R[j] = i == 0? r: std::min(R[j], R[i] + r);
    }
  }
  FOutput << R[n - 1] << std::endl;
  return 0;
}
