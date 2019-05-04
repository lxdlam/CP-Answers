#include <bits/stdc++.h>

using namespace std;

// Recursive version
template <typename T>
class SegTree {
 private:
  size_t size;
  vector<T> data;
  vector<T> flag;
  vector<T> *base;  // Avoid copy

  void pushup(int pos) { data[pos] = data[pos << 1] + data[pos << 1 | 1]; }

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

  void update(int pos, int val, int l, int r, int cur) {
    if (l == r) {
      data[cur] += val;
      return;
    }

    int m = ((r - l) >> 1) + l;
    if (pos <= m)
      update(pos, val, l, m, cur << 1);
    else
      update(pos, val, m + 1, r, cur << 1 | 1);
    pushup(cur);
  }

  T query(int ql, int qr, int l, int r, int cur) {
    if (ql <= l && r <= qr) return data[cur];

    int m = ((r - l) >> 1) + l;
    // pushdown(cur,m-l+1,r-m);

    T ans = 0;
    if (ql <= m) ans += query(ql, qr, l, m, cur << 1);
    if (qr > m) ans += query(ql, qr, m + 1, r, cur << 1 | 1);
    return ans;
  }

 public:
  void init(vector<T> v) {
    size = v.size();
    int realsize = calSize(size);
    data.clear();
    flag.clear();
    data.resize(calSize(size));  // *4
    flag.resize(calSize(size));
    base = &v;
    build(1, size, 1);
  }

  void update(int pos, int val) { update(pos, val, 1, size, 1); }

  T query(int l, int r) { return query(l, r, 1, size, 1); }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T, l, r, n;
  string op;
  cin >> T;
  SegTree<long long> st;

  for (int i = 1; i <= T; i++) {
    cout << "Case " << i << ":\n";
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v) cin >> i;
    st.init(v);

    while (cin >> op && op != "End") {
      cin >> l >> r;
      if (op == "Query")
        cout << st.query(l, r) << endl;
      else if (op == "Add")
        st.update(l, r);
      else if (op == "Sub")
        st.update(l, -r);
    }
  }
}