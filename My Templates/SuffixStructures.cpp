#include <bits/stdc++.h>

using namespace std;

// This template is based on https://riteme.site/blog/2016-6-19/sais.html
// The space can be greatly optimized, but I don't know how to do it
vector<int> SAIS(const vector<int>& S, int SIGMA) {
  int n = S.size();
  deque<bool> type(n, false);
  vector<int> position, name(n, -1), SA(n, -1);
  vector<int> bucket(SIGMA + 1, 0), lbucket(SIGMA + 1, 0),
      sbucket(SIGMA + 1, 0);

  auto induced_sort = [&]() {
    for (int i = 0; i < n; i++) {
      if (SA[i] > 0 && !type[SA[i] - 1]) {
        SA[lbucket[S[SA[i] - 1]]++] = SA[i] - 1;
      }
    }

    for (int i = 1; i <= SIGMA; i++) {
      sbucket[i] = bucket[i] - 1;
    }

    for (int i = n - 1; i >= 0; i--) {
      if (SA[i] > 0 && type[SA[i] - 1]) {
        SA[sbucket[S[SA[i] - 1]]--] = SA[i] - 1;
      }
    }
  };

  auto is_lms_char = [&](int pos) {
    return pos > 0 && type[pos] && !type[pos - 1];
  };

  auto equal_substring = [&](int x, int y) {
    do {
      if (S[x] != S[y]) {
        return false;
      }

      x++, y++;
    } while (!is_lms_char(x) && !is_lms_char(y));

    return S[x] == S[y];
  };

  for (int i = 0; i < n; i++) {
    bucket[S[i]]++;
  }

  for (int i = 1; i <= SIGMA; i++) {
    bucket[i] += bucket[i - 1];
    lbucket[i] = bucket[i - 1];
    sbucket[i] = bucket[i] - 1;
  }

  type[n - 1] = true;

  for (int i = n - 2; i >= 0; i--) {
    if (S[i] < S[i + 1]) {
      type[i] = true;
    } else if (S[i] > S[i + 1]) {
      type[i] = false;
    } else {
      type[i] = type[i + 1];
    }
  }

  for (int i = 1; i < n; i++) {
    if (type[i] && !type[i - 1]) {
      position.push_back(i);
    }
  }
  int cnt = position.size();

  for (const auto& p : position) {
    SA[sbucket[S[p]]--] = p;
  }

  induced_sort();

  int lastx = -1, namecnt = 1;
  bool flag = false;
  for (int i = 1; i < n; i++) {
    int x = SA[i];
    if (is_lms_char(x)) {
      if (lastx >= 0 && !equal_substring(x, lastx)) {
        namecnt++;
      }

      if (lastx >= 0 && namecnt == name[lastx]) {
        flag = true;
      }

      name[x] = namecnt;
      lastx = x;
    }
  }

  name[n - 1] = 0;

  vector<int> S1;
  for (int i = 0; i < n; i++) {
    if (name[i] >= 0) {
      S1.push_back(name[i]);
    }
  }

  vector<int> SA1;

  if (!flag) {
    SA1.resize(cnt);
    for (int i = 0; i < cnt; i++) {
      SA1[S1[i]] = i;
    }
  } else {
    SA1 = SAIS(S1, namecnt);
  }

  lbucket[0] = sbucket[0] = 0;

  for (int i = 1; i <= SIGMA; i++) {
    lbucket[i] = bucket[i - 1];
    sbucket[i] = bucket[i] - 1;
  }

  fill(SA.begin(), SA.end(), -1);
  for (int i = cnt - 1; i >= 0; i--) {
    SA[sbucket[S[position[SA1[i]]]]--] = position[SA1[i]];
  }
  induced_sort();

  return SA;
}

void get_sa(const string& str, vector<int>& sa, vector<int>& rk,
            vector<int>& ht, int SIGMA = 26) {
  vector<int> v;
  for (const auto& ch : str) {
    v.push_back(ch - 'a' + 1);
  }

  v.push_back(0);  // A fail character

  auto SA = SAIS(v, SIGMA);

  int n = SA.size() - 1;
  sa.resize(n);
  rk.resize(n);
  ht.resize(n);

  for (int i = 0; i < n; i++) {
    sa[i] = SA[i + 1];
    rk[sa[i]] = i;
  }

  for (int i = 0, k = 0; i < n; i++) {
    if (rk[i] == 0)
      k = 0;
    else {
      if (k > 0) k--;
      int j = sa[rk[i] - 1];
      while (i + k < n && j + k < n && str[i + k] == str[j + k]) k++;
    }
    ht[rk[i]] = k;
  }
}