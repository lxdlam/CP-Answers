#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  char a[110][110], b[110][110];
  char c[110 * 110];
  while (cin >> n) {
    cin.get();
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cin >> a[i][j];
      cin.get();
    }
    if (n == 1) {
      cout << a[0][0] << '\n';
      continue;
    }
    int i = 0, j = 0, k = 0;
    while (1) {
      // cout << a[i][j];
      c[k++] = a[i][j];
      if (i == 0 && j == 0) {
        j++;
      } else if (i == 0 && j != 0 && j != n - 1 && (i + j) % 2 == 0) {
        j++;
      } else if (i == 0 && j != 0 && j != n - 1 && (i + j) % 2 == 1) {
        j--;
        i++;
      } else if (j == 0 && i != 0 && i != n - 1 && (i + j) % 2 == 0) {
        i--;
        j++;
      } else if (j == 0 && i != 0 && i != n - 1 && (i + j) % 2 == 1) {
        i++;
      } else if (i == n - 1 && j == n - 1) {
        break;
      } else if (i == n - 1 && (i + j) % 2 == 0) {
        i--;
        j++;
      } else if (i == n - 1 && (i + j) % 2 == 1) {
        j++;
      } else if (j == n - 1 && (i + j) % 2 == 0) {
        i++;
      } else if (j == n - 1 && (i + j) % 2 == 1) {
        i++;
        j--;
      } else if ((i + j) % 2 == 0) {
        i--;
        j++;
      } else {
        i++;
        j--;
      }
    }

    int l = 0;
    int x = 0, y = 0;

    while (true) {
      while (y < n - x) b[x][y++] = c[l++];
      if (l >= k) break;
      x++, y--;

      while (x <= y) b[x++][y] = c[l++];
      if (l >= k) break;
      x--, y--;

      while (n - x - 1 <= y) b[x][y--] = c[l++];
      if (l >= k) break;
      y++, x--;

      while (x > y) b[x--][y] = c[l++];
      if (l >= k) break;
      x++, y++;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << b[i][j];
      cout << '\n';
    }
  }

  return 0;
}