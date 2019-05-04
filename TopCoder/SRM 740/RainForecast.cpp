#include <bits/stdc++.h>

using namespace std;

#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)

template <typename T>
bool smax(T &a, const T &b) {
  if (a > b) return false;
  a = b;
  return true;
}

template <typename T>
bool smin(T &a, const T &b) {
  if (a < b) return false;
  a = b;
  return true;
}

template <typename T>
T cd(T a, T b) {
  return (a + b - 1) / b;
}

template <typename T>
bool se(T &a, T &b) {
  if (a < b) return false;
  swap(a, b);
  return true;
}

const int INF = 0x3f3f3f3f;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef vector<string> cb;

class RainForecast {
 private:
  // Constants

  static const int SIZE = 60;

  double dp[SIZE][2];

  // Useful Inner Method

  // Solver
  inline double solve() { return 0.0; }

 public:
  double predictRain(int ilkoProb, vector<int> deliverProbs) {
    // Build

    dp[0][1] = 1.0 * ilkoProb / 100;
    dp[0][0] = 1 - dp[0][1];

    for (int i = 1; i <= deliverProbs.size(); i++) {
      double t = 1.0 * deliverProbs[i - 1] / 100, f = 1 - t;
      dp[i][0] = (dp[i - 1][1] * f) + (dp[i - 1][0] * t);
      dp[i][1] = (dp[i - 1][1] * t) + (dp[i - 1][0] * f);
    }

    return max(dp[deliverProbs.size()][1], dp[deliverProbs.size()][0]);
    // return 0.0;
  }
};