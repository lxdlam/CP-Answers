#include <bits/stdc++.h>

using namespace std;

class RingLex {
 private:
  // Constants
  vector<int> primes{2,  3,  5,  7,  11, 13, 17, 19,
                     23, 29, 31, 37, 41, 43, 47, 53};

  // Useful Inner Method

  // Builder
  void build() {}

  // Solver
 public:
  string getmin(string s) {
    build();
    int len = s.size();

    string res =
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
        "z";
    string tmp;
    stringstream ss;
    for (int i = 0; i < len; i++) {
      for (auto j : primes) {
        if (j >= len) break;
        ss.str("");
        ss << s[i];
        for (int p = 1; p <= len - 1; p++) ss << s[(i + p * j) % len];
        tmp = ss.str();
        res = min(res, tmp);
      }
    }

    return res;
  }
};
