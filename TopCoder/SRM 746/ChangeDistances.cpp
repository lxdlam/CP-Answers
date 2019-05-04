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

class ChangeDistances {
 private:
  // Constants

  // Useful Inner Method

 public:
  ChangeDistances() {}

  vector<string> findGraph(vector<string> g) {
    vector<string> ans;
    int n = g.size();
    for (int i = 0; i < n; i++) {
      stringstream ss;
      for (int j = 0; j < n; j++) {
        if (i == j)
          ss << '0';
        else if (g[i][j] == '1')
          ss << '0';
        else
          ss << '1';
      }
      ans.pb(ss.str());
    }

    return ans;
  }
};