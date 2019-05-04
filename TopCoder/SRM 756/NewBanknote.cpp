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

class NewBanknote {
 private:
  // Constants
  vector<int> cost{0, 1, 1, 2, 2, 1, 2, 2, 3, 3};
  map<int, int> memorize;

  // Useful Inner Method
  int remain(int val) {
    if (val < 0) return 0;
    if (!memorize.count(val)) {
      int cur = val;
      for (int i = 0; i < 5; i++) {
        memorize[val] += cost[cur % 10];
        cur /= 10;
      }
      memorize[val] += cur * 2;  // use 500 euro to form
    }
    return memorize[val];
  }

 public:
  NewBanknote() {}

  vector<int> fewestPieces(int newBanknote, vector<int> amountsToPay) {
    int n = amountsToPay.size();

    vector<int> ans(n, INT_MAX);

    for (int i = 0; i < n; i++)
      for (int p = 0, cur = amountsToPay[i]; cur >= 0 && p < 40000;
           cur -= newBanknote, p++)
        smin(ans[i], p + remain(cur));

    return ans;
  }
};