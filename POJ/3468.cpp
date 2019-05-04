#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

// Recursive version
template <typename T>
class SegTree {
 private:
  size_t size;
  vector<T> data;
  vector<T> flag;   // lazy flag, the current node has been updated but its
                    // children haven't
  vector<T> *base;  // Avoid copy

  void pushup(int pos) { data[pos] = data[pos << 1] + data[pos << 1 | 1]; }

  void pushdown(int pos, int lcnt, int rcnt) {
    if (flag[pos]) {
      flag[pos << 1] += flag[pos];
      flag[pos << 1 | 1] += flag[pos];
      data[pos << 1] += flag[pos] * lcnt;
      data[pos << 1 | 1] += flag[pos] * rcnt;
      flag[pos] = 0;
    }
  }

  int calSize(int num) {
    int i = 1, j = num;
    while ((j >>= 1) || (i < num)) i <<= 1;
    return i * 2;
  }

  void build(int l, int r, int cur) {
    if (l == r) {
      data[cur] = (*base)[l - 1];
      return;
    }

    int m = ((r - l) >> 1) + l;
    build(l, m, cur << 1);
    build(m + 1, r, cur << 1 | 1);
    pushup(cur);
  }

  void update(int pos, T val, int l, int r, int cur) {
    if (l == r) {
      data[cur] += val;
      return;
    }

    int m = ((r - l) >> 1) + l;

    // if mixed
    // pushdown(cur, m - l + 1, r - m);

    if (pos <= m)
      update(pos, val, l, m, cur << 1);
    else
      update(pos, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
  }

  void update(int ul, int ur, T val, int l, int r, int cur) {
    if (ul <= l && r <= ur) {
      data[cur] += val * (r - l + 1);
      flag[cur] += val;
      return;
    }

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);

    if (ul <= m) update(ul, ur, val, l, m, cur << 1);
    if (ur > m) update(ul, ur, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
  }

  T query(int ql, int qr, int l, int r, int cur) {
    if (ql <= l && r <= qr) return data[cur];

    int m = ((r - l) >> 1) + l;
    pushdown(cur, m - l + 1, r - m);

    T ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, cur << 1);
    if (qr > m) ans += query(ql, qr, m + 1, r, cur << 1 | 1);
    return ans;
  }

 public:
  void init(vector<T> v) {
    size = v.size();
    data.clear();
    flag.clear();
    data.resize(calSize(size));  // *4
    flag.resize(calSize(size));
    base = &v;
    build(1, size, 1);
  }

  void update(int pos, T val) { update(pos, val, 1, size, 1); }

  void update(int ul, int ur, T val) { update(ul, ur, val, 1, size, 1); }

  T query(int l, int r) { return query(l, r, 1, size, 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  string op;
  ll t, l, r, a;
  cin >> n >> q;
  vector<ll> v;
  while (n--) {
    cin >> t;
    v.push_back(t);
  }
  SegTree<ll> st;
  st.init(v);

  while (q--) {
    cin >> op;
    if (op == "Q") {
      cin >> l >> r;
      cout << st.query(l, r) << endl;
    } else {
      cin >> l >> r >> a;
      st.update(l, r, a);
    }
  }
}