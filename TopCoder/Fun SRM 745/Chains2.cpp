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

class Chains2 {
private:
  // Constants

  // Useful Inner Method

public:
  Chains2() {}

  int validate(vector<int> x, vector<int> y) {
    // Solution here

    int n = x.size();
    int l = x[0], r = y[0];
    for (int i = 1; i < n; i++) {
      if ((l == r) || (x[i] <= l && y[i] > r) || (x[i] < l && y[i] >= r)) {
        if (l == r && x[i] == y[i]) return -(i + 1);
        l = x[i];
        r = y[i];
        continue;
      }

      return -(i + 1);
    }

    return l == r ? 0 : r;
  }
};
