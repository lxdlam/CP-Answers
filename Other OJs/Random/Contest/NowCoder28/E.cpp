#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  cin.get();
  ll res;
  string t;
  int k;
  while (T--) {
    res = 0;
    getline(cin, t);
    stringstream ss(t);
    while (ss >> k) res += k;
    cout << res << endl;
  }

  return 0;
}