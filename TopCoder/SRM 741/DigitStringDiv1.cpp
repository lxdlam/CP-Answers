#include <bits/stdc++.h>

using namespace std;

#define FOR(_i, _begin, _end) for (auto _i = _begin; _i < _end; _i++)
#define FORR(_i, _begin, _end) for (auto _i = _begin; _i > _end; _i--)

template <typename T>
bool smax(T& a, const T& b) {
  if (a > b) return false;
  a = b;
  return true;
}

template <typename T>
bool smin(T& a, const T& b) {
  if (a < b) return false;
  a = b;
  return true;
}

template <typename T>
T cd(T a, T b) {
  return (a + b - 1) / b;
}

template <typename T>
bool se(T& a, T& b) {
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

class DigitStringDiv1 {
private:
  // Constants
  static const int SIZE = 60;
  ll c[SIZE][SIZE];

  // Useful Inner Method

  void getCom() {
    memset(c, 0, sizeof c);
    c[0][0] = 1;
    for (int i = 1; i < SIZE; i++) {
      c[i][0] = 1;
      for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }

  // Solver

public:
  long long count(string S, int X) {
    // Build
    stringstream ss;
    ss << X;
    string x = ss.str();
    int len = x.size();

    int n = S.size();
    ll ans = 0;

    getCom();

    for (int i = len + 1; i <= n; i++) ans += c[n][i];

    for (int i = 0; i < n; i++)
      if (S[i] == '0')
        for (int j = len + 1; j <= n; j++) ans -= c[n - i - 1][j - 1];

    vll tmp(len + 1);  // Genius
    tmp[0] = 1;
    FOR(i, 0, n) {
      for (int j = len; j >= 1; j--) {
        if (S[i] == x[j - 1])
          tmp[j] += tmp[j - 1];
        else if (S[i] > x[j - 1])
          ans += tmp[j - 1] * c[n - i - 1][len - j];
      }
    }

    return ans;
  }
};