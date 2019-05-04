#include <bits/stdc++.h>

using namespace std;

struct LB {
  using ll = long long;
  int MaxL;

  vector<ll> data;

  LB(int size = 60) {
    MaxL = size;
    data.resize(size + 1);
  }

  void insert(ll t) {
    for (int j = MaxL; j >= 0; j--) {
      if (!(t & (1LL << j))) continue;

      if (data[j])
        t ^= data[j];
      else {
        for (int k = 0; k < j; k++)
          if (t & (1LL << k)) t ^= data[k];

        for (int k = j + 1; k <= MaxL; k++)
          if (data[k] & (1LL << j)) data[k] ^= t;

        data[j] = t;

        return;
      }
    }
  }

  void merge(const LB &l) {
    for (int i = 0; i <= MaxL; i++) insert(l.data[i]);
  }

  ll queryMax() {
    ll ans = 0;
    for (auto i : data) ans ^= i;
    return ans;
  }

  int rank() {
    int ans = 0;
    for (auto i : data)
      if (i) ans++;
    return ans;
  }
};