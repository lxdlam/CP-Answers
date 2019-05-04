#include <bits/stdc++.h>

using namespace std;

const int CHAR_SIZE = 26;
const char CHAR_START = 'a';
const int SIZE = 1e5 + 10;  // String size

struct PAM {
  int node[SIZE][CHAR_SIZE];
  int fail[SIZE];
  int cnt[SIZE];  // distinct palindromes at node i
  int num[SIZE];  // the number of palindroms which end with the end of longest
                  // palindrome at node i
  int len[SIZE];  // length of the palindrome at node i
  int s[SIZE];

  int last;  // the longest palindrome's node
  int n;     // count of character
  int p;     // count of nodes

  int new_node(int le) {
    for (int i = 0; i < CHAR_SIZE; i++) node[p][i] = 0;
    cnt[p] = 0;
    num[p] = 0;
    len[p] = le;
    return p++;
  }

  void init() {
    p = 0;
    new_node(0);
    new_node(-1);

    last = n = 0;
    s[0] = -1;
    fail[0] = 1;
  }

  int get_fail(int x) {
    while (s[n - len[x] - 1] != s[n]) x = fail[x];
    return x;
  }

  void add(char ch) {
    int c = ch - CHAR_START;
    s[++n] = c;
    int cur = get_fail(last);
    if (!node[cur][c]) {
      int now = new_node(len[cur] + 2);
      fail[now] = node[get_fail(fail[cur])][c];
      node[cur][c] = now;
      num[now] = num[fail[now]] + 1;
    }
    last = node[cur][c];
    cnt[last]++;
  }

  void get_cnt() {
    for (int i = p - 1; i >= 0; i--) cnt[fail[i]] += cnt[i];
  }

  int get_num() { return num[n]; }
} pam;

int main() {
  string s;
  cin >> s;
  pam.init();
  int ans = 0;
  for (auto i : s) pam.add(i);
  pam.get_cnt();
  for (int i = 2; i < pam.p; i++) ans += pam.cnt[i];
  cout << ans << '\n';
};