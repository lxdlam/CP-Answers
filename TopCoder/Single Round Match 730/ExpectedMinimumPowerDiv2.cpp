#include <bits/stdc++.h>

using namespace std;

class ExpectedMinimumPowerDiv2 {
private:
  // Constants
  const static int SIZE = 50 + 10;
  double table[SIZE] = {1};
  double c[SIZE][SIZE];

  // Useful Inner Method

  // Builder
  void build() {
    for (int i = 1; i < SIZE; i++) table[i] = 2 * table[i - 1];
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++) {
      c[i][0] = 1;
      for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }

  // Solver
public:
  double findExp(int n, int x) {
    build();

    double res = 0;
    double base = c[n][x];
    x--;
    for (int i = n - 1; i >= x; i--) res += c[i][x] * table[n - i];
    return res / base;

    return 0.0;
  }
};