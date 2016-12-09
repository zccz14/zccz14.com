#include <fstream>
const int MAXN = 100;

int T[MAXN][MAXN];

int main() {
  std::ifstream FInput("input.txt");
  std::ofstream FOutput("output.txt");
  int N;
  FInput >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      FInput >> T[i][j];
    }
  }
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      T[i][j] += std::max(T[i + 1][j], T[i + 1][j + 1]);
    }
  }
  FOutput << T[0][0] << std::endl;
  return 0;
}
