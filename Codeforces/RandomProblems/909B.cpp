#include <bits/stdc++.h>

#define FOR(_i, _s, _e) for (int _i = _s; _i < _e; _i++)
#if __cpluscplus > 201103L
#define FORE(_c) for (auto i : _c)
#define FORER(_c) for (auto &i : _c)
#else
#define FORE(_c)
#define FORER(_c)
#define nullptr NULL
#endif
#if __cplusplus > 201402L
#define VIS(_kind, _name, _size) \
  vector<_kind> _name(_size);    \
  for (auto &i : v) cin >> i;
#elif __cpluscplus > 201103L
#define VIS(_kind, _name, _size) \
  vector<_kind> _name;           \
  _name.resize(_size);           \
  for (auto &i : v) cin >> i;
#else
#define VIS(_kind, _name, _size) \
  vector<_kind> _name;           \
  _name.resize(_size);           \
  for (int i = 0; i < _size; i++) cin >> v[i];
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

const int SIZE = 100 + 10;

int table[SIZE] = {0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 2; i < SIZE; i++) table[i] = table[i - 1] + (i + 1) / 2;

  int n;
  cin >> n;
  cout << table[n] << endl;

  return 0;
}