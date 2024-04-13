#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Atom {
  int l = 0, r = 0, no = 0;

  Atom() = default;

  Atom(int i, std::string&& s) : no(i) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
      if (s[i] == ')') {
        if (l == 0) {
          r++;
        } else {
          l--;
        }
      } else {
        l++;
      }
    }
  }

  bool operator<(const Atom& a) const {
    int lr = (l > a.r) ? r : (a.r - l + r);
    int rr = (a.l > r) ? a.r : (r - a.l + a.r);
    return lr < rr;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s;
  cin >> n;

  vector<int> ans, last;
  int tl = 0, tr = 0;

  priority_queue<Atom> pq;
  for (int i = 1; i <= n; i++) {
    cin >> s;

    Atom a{i, std::move(s)};

    if (a.r == 0) {
      tl += a.l;
      ans.emplace_back(i);
    } else if (a.l == 0) {
      tr += a.r;
      last.emplace_back(i);
    } else {
      pq.emplace(std::move(a));
      while (!pq.empty() && tl >= pq.top().r) {
        tl = tl - pq.top().r + pq.top().l;
        ans.emplace_back(pq.top().no);
        pq.pop();
      }
    }
  }

  while (!pq.empty() && tl >= pq.top().r) {
    tl = tl - pq.top().r + pq.top().l;
    ans.emplace_back(pq.top().no);
    pq.pop();
  }

  if (tr != tl || !pq.empty()) {
    cout << "impossible\n";
  } else {
    for (auto x : ans) {
      cout << x << '\n';
    }
    for (auto x : last) {
      cout << x << '\n';
    }
  }
}
