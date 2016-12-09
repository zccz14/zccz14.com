#include <fstream>
const int MAXB = 5, MAXK = 5, MAXST = 7776, MAXC = 1000, MAXS = 100;

int IndexOfC[MAXC]; // map C to Index
int K[MAXB], P[MAXB];
int Number[MAXB];
int MaxProfit[MAXST]; // the maximum profit
int Valid[MAXST];     // 0 for unknown, 1 for invalid, 2 for valid

// O(B) Status Compressing
int compress(int *N) {
  int ans = 0;
  for (int i = 0, p = 1; i < MAXB; i++) {
    ans += p * N[i];
    p *= MAXK + 1;
  }
  return ans;
}

// O(B) Status Decompressing and check
bool check(int x) {
  if (Valid[x]) {
    return Valid[x] == 2;
  }
  for (int i = 0; i < MAXB; i++) {
    if (x % (MAXK + 1) > K[i]) {
      return (Valid[x] = 1) == 2;
    }
    x /= MAXK + 1;
  }
  return (Valid[x] = 2) == 2;
}

int main() {
  std::ifstream FInput("input.txt");
  std::ifstream FOffer("offer.txt");
  std::ofstream FOutput("output.txt");
  int PriceStd = 0;
  // process input.txt
  int B;
  FInput >> B;
  for (int i = 0; i < B; i++) {
    int C;
    FInput >> C >> K[i] >> P[i];
    IndexOfC[C] = i;
    PriceStd += K[i] * P[i];
  }
  // process offer.txt
  int S;
  FOffer >> S;
  for (int i = 0; i < S; i++) {
    int maxJ;
    FOffer >> maxJ;
    int profit = 0;
    std::fill(Number, Number + MAXB, 0);
    for (int j = 0; j < maxJ; j++) {
      int c, k;
      FOffer >> c >> k;
      Number[IndexOfC[c]] = k;
      profit += P[IndexOfC[c]] * k;
    }
    int price;
    FOffer >> price;
    profit -= price;
    // Online DP
    int maxST = compress(K);
    int delta = compress(Number);
    for (int j = maxST; j >= delta; j--) {
      if (check(j - delta)) {
        MaxProfit[j] = std::max(MaxProfit[j], MaxProfit[j - delta] + profit);
      }
    }
  }
  // Get Maximum Profit
  int ans = PriceStd - MaxProfit[compress(K)];
  // output to output.txt
  FOutput << ans << std::endl;
  return 0;
}
