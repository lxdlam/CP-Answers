#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  ll ans = 0;
  int cur = 0;
  while (n--) {
    int t;
    cin >> t;
    if (cur > t) ans += 1LL * (cur - t);
    cur = t;
  }

  ans += 1LL * cur;

  cout << ans << '\n';
  return 0;
}