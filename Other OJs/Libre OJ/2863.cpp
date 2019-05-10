#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

string guess_sequence(int N) {
  string ans = "";
  vector<string> v;

  if (press("AB")) {
    if (press("A"))
      ans = "A", v.pb("B"), v.pb("X"), v.pb("Y");

    else
      ans = "B", v.pb("A"), v.pb("X"), v.pb("Y");

  } else {
    if (press("X"))
      ans = "X", v.pb("A"), v.pb("B"), v.pb("Y");
    else
      ans = "Y", v.pb("A"), v.pb("B"), v.pb("X");
  }

  for (int i = 1; i < N - 1; i++) {
    stringstream ss;
    ss << ans;
    ss << v[0];
    for (int p = 0; p < 3; p++) ss << ans << v[1] << v[p];

    // cerr << ss.str() << '\n';

    int ret = press(ss.str());

    if (ret == i + 1)
      ans += v[0];
    else if (ret == i + 2)
      ans += v[1];
    else
      ans += v[2];
  }

  if (static_cast<int>(ans.size()) < N) {
    stringstream ss;

    ss << ans << v[0] << ans << v[1];
    if (press(ss.str()) == N) {
      ss.str("");
      ss << ans << v[0];
      if (press(ss.str()) == N)
        ans += v[0];
      else
        ans += v[1];
    } else
      ans += v[2];
  }

  assert(static_cast<int>(ans.size()) == N);
  return ans;
}