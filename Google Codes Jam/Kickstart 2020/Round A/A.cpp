#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
  int T;
  scanf("%d", &T);
  for (int k = 1; k <= T; k++) {
    int N, B, ans = 0;
    scanf("%d %d", &N, &B);

    vector<int> v(N);

    for (auto&& i : v) {
      scanf("%d", &i);
    }

    sort(v.begin(), v.end());

    for (const auto& i : v) {
      if (B >= i) {
        B -= i;
        ans++;
      } else {
        break;
      }
    }

    printf("Case #%d: %d\n", k, ans);
  }
}